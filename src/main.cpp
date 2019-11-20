#include <Arduino.h>
#include "pin_configuration.h"
#include "OvenTemp.h"
#include "autotune.h"
#include "oven.pb.h"
#include <pb_encode.h>
#include <pb_decode.h>
#include <PacketSerial.h>
#include <CurveFollower.h>

uint8_t send_buffer[300];

PacketSerial_<COBS> packetSerial;

void sendPID();

void onPacketReceived(const uint8_t *buffer, size_t size) {
    RxMicro rx = RxMicro_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(buffer, size);
    bool status = pb_decode(&stream, RxMicro_fields, &rx);
    if (status) {
        if (rx.has_target && rx.target.has_targetTemp) {
            setpoint = rx.target.targetTemp;
        }
        if (rx.has_ovenConfiguration && rx.ovenConfiguration.has_pidTune) {
            if (rx.ovenConfiguration.pidTune.has_i) {
                ki = rx.ovenConfiguration.pidTune.i;
            }
            if (rx.ovenConfiguration.pidTune.has_d) {
                kd = rx.ovenConfiguration.pidTune.d;
            }
            if (rx.ovenConfiguration.pidTune.has_p) {
                kp = rx.ovenConfiguration.pidTune.p;
            }
//            sendPID();
        }
        if (rx.has_ovenState) {
            ovenState = rx.ovenState;
        }
    }
}

void sendPID() {
    TxMicro tx = TxMicro_init_zero;
    tx.has_timeStamp = true;
    tx.timeStamp = millis();

    tx.has_ovenConfiguration = true;
    tx.ovenConfiguration.has_pidTune = true;
    tx.ovenConfiguration.pidTune.has_p = true;
    tx.ovenConfiguration.pidTune.has_i = true;
    tx.ovenConfiguration.pidTune.has_d = true;
    tx.ovenConfiguration.pidTune.p = kp;
    tx.ovenConfiguration.pidTune.i = ki;
    tx.ovenConfiguration.pidTune.d = kd;

    pb_ostream_t stream = pb_ostream_from_buffer(send_buffer, sizeof(send_buffer));
    pb_encode(&stream, TxMicro_fields, &tx);

    if (Serial) {
        packetSerial.send(send_buffer, stream.bytes_written);
        packetSerial.update();
    }

}

void sendData() {
    TxMicro tx = TxMicro_init_zero;
    tx.has_timeStamp = true;
    tx.timeStamp = millis();
    tx.has_ovenStatus = true;
    tx.ovenStatus.has_ovenState = true;
    tx.ovenStatus.has_ovenTemp = true;
    tx.ovenStatus.has_ambientTemp = true;
    tx.ovenStatus.has_targetTemp = true;
    tx.ovenStatus.has_outputPower = true;
    tx.ovenStatus.ovenState = ovenState;
    tx.ovenStatus.ovenTemp = (float) ovenTemp();
    tx.ovenStatus.ambientTemp = (float) ambientTemp();
    tx.ovenStatus.targetTemp = (float) setpoint;
    tx.ovenStatus.outputPower = getLastOvenPower();
    pb_ostream_t stream = pb_ostream_from_buffer(send_buffer, sizeof(send_buffer));
    pb_encode(&stream, TxMicro_fields, &tx);

    if (Serial) {
        packetSerial.send(send_buffer, stream.bytes_written);
        packetSerial.update();
    }

    // save_data(send_buffer, stream.bytes_written);
}


void hexPrinter(uint8_t *buffer, int number) {
    //Serial.print("0x");
    for (int n = 0; n <= number; n++) {
        Serial.print(buffer[n] < 16 ? "0" : "");
        Serial.print(buffer[n], HEX);
    }
    Serial.println();
}


void setup() {
    // put your setup code here, to run once:
    pinMode(heat_enable, OUTPUT);
    digitalWrite(heat_enable, LOW);

    packetSerial.begin(115200);
    packetSerial.setPacketHandler(&onPacketReceived);

//    Serial.begin(115200);
    setupPID();

}


unsigned long loopStart;
unsigned long loopTime;
#define LOOP_PERIOD 50

bool ledState = LOW;

void loop() {
//    sendDummyData();

      loopStart = millis();
      PIDLoop();
//
//      //Serial.println("Loop");``
//

    sendData();
    sendPID();
    packetSerial.update();
//
    loopTime = millis() - loopStart;
    if (LOOP_PERIOD - loopTime > 0) {
        digitalWrite(LED_BUILTIN, ledState);
        ledState = !ledState;
        delay(LOOP_PERIOD - loopTime);
    }


// end

//setOvenPower(255);

//    Serial.print("Thermocouple reading: ");
//    Serial.print(ovenTemp());
//    Serial.print("  Internal: ");
//    Serial.println(ambientTemp());
//    delay(1000);


////    // put your main code here, to run repeatedly:
//    delay(1000);
//    analogWrite(heat_enable, 255);
//    Serial.println("on");
//    //digitalWrite(heat_enable, HIGH);
//    delay(1000);
////  digitalWrite(heat_enable, LOW);
//    Serial.println("off");
//    analogWrite(heat_enable, 0);

}