//
// Created by jesse on 10/30/19.
//

#include "pin_configuration.h"
#include <Adafruit_MAX31855.h>
#include "OvenTemp.h"

Adafruit_MAX31855 thermocouple0(therm_0_cs);
Adafruit_MAX31855 thermocouple1(therm_1_cs);
Adafruit_MAX31855 thermocouple2(therm_2_cs);


int lastOvenPower = 0;

double ovenTemp() {
    return thermocouple1.readCelsius();
}

double ambientTemp() {
    return thermocouple1.readInternal();
}

void setOvenPower(int power) {
    lastOvenPower = power;
    if (power > 136) {
        digitalWrite(heat_enable, HIGH);
    }

    if (power < 120) {
        digitalWrite(heat_enable, LOW);
    }
    //    analogWrite(heat_enable, power);

}

int getLastOvenPower() {
    return lastOvenPower;
}

