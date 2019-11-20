//
// Created by jesse on 11/1/19.
//

#include "CurveFollower.h"

float CurveFollower::getTempForTime(unsigned long time) {
    int i = 0;

    for (i = 0; i < curve.reflowPoints_count; i++) {
        auto point = curve.reflowPoints[i];
        if (point.time > time) {
            break;
        }
    }

    if (i == 0) i++; // Increment by one to fix index
    auto left = curve.reflowPoints[i-1];
    auto right = curve.reflowPoints[i];

    if (right.time == left.time) return left.temp;

    return left.temp + ((right.temp-left.temp)/(right.time - left.time)) * (time - left.time);
}

void CurveFollower::setTempertureCurve(ReflowCurve c) {
    this->curve = c;

}
