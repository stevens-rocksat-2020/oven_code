#ifndef PID_JACK_H
#define PID_JACK_H

#include <Arduino.h> 
#include <oven.pb.h>


class PID 
{
public:
    OvenState ovenState;
    double kp,ki,kd,target;

    double totalError=0;
    double lastError=0;
    long lastTimestamp=millis()-100;

    double get(double input); 
    void reset();
    void pidLoop();
};



#endif