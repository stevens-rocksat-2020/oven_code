//
// Created by jesse on 11/1/19.
//

#ifndef OVEN_CONTROL_CURVEFOLLOWER_H
#define OVEN_CONTROL_CURVEFOLLOWER_H

#include "oven.pb.h"

class CurveFollower {
private:
    ReflowCurve curve;

public:
    float getTempForTime(unsigned long time);

    void setTempertureCurve(ReflowCurve c);
};


#endif //OVEN_CONTROL_CURVEFOLLOWER_H
