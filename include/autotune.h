//
// Created by jesse on 10/30/19.
//

#ifndef OVEN_CONTROL_AUTOTUNE_H
#define OVEN_CONTROL_AUTOTUNE_H

#include <PID_v1.h>
#include <PID_AutoTune_v0.h>
#include "OvenTemp.h"
#include "oven.pb.h"

byte ATuneModeRemember = 2;
double input = 80, output = 50, setpoint = 180;
double kp = 8.15, ki = 0.33, kd = 2;

double aTuneStep = 50, aTuneNoise = 1, aTuneStartValue = 100;
unsigned int aTuneLookBack = 20;

boolean tuning = false;

PID myPID(&input, &output, &setpoint, kp, ki, kd, DIRECT);
PID_ATune aTune(&input, &output);

OvenState ovenState = OvenState_OFF;

//set to false to connect to the real world

void changeAutoTune();

//void SerialSend();
//void SerialReceive();
void AutoTuneHelper(bool start);

void setupPID() {
    //Setup the pid
    myPID.SetMode(AUTOMATIC);

    if (tuning) {
        tuning = false;
        changeAutoTune();
        tuning = true;
    }

//    serialTime = 0;

}

void PIDLoop() {
    unsigned long now = millis();

    input = ovenTemp();

    if (tuning) {
        byte val = (aTune.Runtime());
        if (val != 0) {
            tuning = false;
        }
        if (!tuning) { //we're done, set the tuning parameters
            kp = aTune.GetKp();
            ki = aTune.GetKi();
            kd = aTune.GetKd();
            myPID.SetTunings(kp, ki, kd);
            AutoTuneHelper(false);
        }
    } else {
        myPID.SetTunings(kp, ki, kd);
        myPID.Compute();
    }

    if (ovenState == OvenState_ON) {
        setOvenPower((int)output);
    } else {
        setOvenPower(0);
    }


//    //send-receive with processing if it's time
//    if (millis() > serialTime) {
//        SerialReceive();
//        SerialSend();
//        serialTime += 500;
//    }

}

void changeAutoTune() {
    if (!tuning) {
        //Set the output to the desired starting frequency.
        output = aTuneStartValue;
        aTune.SetNoiseBand(aTuneNoise);
        aTune.SetOutputStep(aTuneStep);
        aTune.SetLookbackSec((int) aTuneLookBack);
        AutoTuneHelper(true);
        tuning = true;
    } else { //cancel autotune
        aTune.Cancel();
        tuning = false;
        AutoTuneHelper(false);
    }
}

void AutoTuneHelper(boolean start) {
    if (start)
        ATuneModeRemember = myPID.GetMode();
    else
        myPID.SetMode(ATuneModeRemember);
}

/*
void SerialSend() {
    Serial.print("setpoint: ");
    Serial.print(setpoint);
    Serial.print(" ");
    Serial.print("input: ");
    Serial.print(input);
    Serial.print(" ");
    Serial.print("output: ");
    Serial.print(output);
    Serial.print(" ");
    if (tuning) {
        Serial.println("tuning mode");
    } else {
        Serial.print("kp: ");
        Serial.print(myPID.GetKp());
        Serial.print(" ");
        Serial.print("ki: ");
        Serial.print(myPID.GetKi());
        Serial.print(" ");
        Serial.print("kd: ");
        Serial.print(myPID.GetKd());
        Serial.println();
    }
}

void SerialReceive() {
    if (Serial.available()) {
        char b = Serial.read();
        Serial.flush();
        if ((b == '1' && !tuning) || (b != '1' && tuning))changeAutoTune();
    }
}
 */


#endif //OVEN_CONTROL_AUTOTUNE_H
