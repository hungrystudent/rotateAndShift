#ifndef PROBLEMVECTOR_H
#define PROBLEMVECTOR_H

#include <animationfunctor.h>

class ProblemVector
{
public:
    ProblemVector();
    ProblemVector(const float inpRotation, const float inpShiftX,
                  const float inpShiftY, const float inpShiftZ,
                  int inpStepCount,float inpStepLength);
    float getRotation();
    float getShiftX();
    float getShiftY();
    float getShiftZ();
    int getStepCount();
    float getStepLength();
    float setRotation(float value);
    float setShiftX(float value);
    float setShiftY(float value);
    float setShiftZ(float value);
    int setStepCount(int value);
    float setStepLength(float value);
private:
    float rotation   = 0;
    float shiftX     = 0;
    float shiftY     = 0;
    float shiftZ     = 0;
    int   stepCount  = 0;
    float stepLength = 0;
};

#endif // PROBLEMVECTOR_H
