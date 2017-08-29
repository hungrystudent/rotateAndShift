#include "problemvector.h"

ProblemVector::ProblemVector()
{

}

ProblemVector::ProblemVector(const float inpRotation, const float inpShiftX,
                             const float inpShiftY, const float inpShiftZ,
                             int inpStepCount,float inpStepLength)
{
    rotation = inpRotation;
    shiftX = inpShiftX;
    shiftY = inpShiftY;
    shiftZ = inpShiftZ;
    stepCount = inpStepCount;
    stepLength = inpStepLength;
}

float ProblemVector::getRotation()
{
    return rotation;
}

float ProblemVector::getQuaternionI()
{
    return quaternionI;
}
float ProblemVector::getQuaternionJ()
{
    return quaternionJ;
}
float ProblemVector::getQuaternionK()
{
    return quaternionK;
}

float ProblemVector::getShiftX()
{
    return shiftX;
}

float ProblemVector::getShiftY()
{
    return shiftY;
}

float ProblemVector::getShiftZ()
{
    return shiftZ;
}

int ProblemVector::getStepCount()
{
    return stepCount;
}

float ProblemVector::getStepLength()
{
    return stepLength;
}


float ProblemVector::setRotation(float value)
{
    rotation = value;
}

float ProblemVector::setShiftX(float value)
{
    shiftX = value;
}

float ProblemVector::setShiftY(float value)
{
    shiftY = value;
}

float ProblemVector::setShiftZ(float value)
{
    shiftZ = value;
}

int ProblemVector::setStepCount(int value)
{
    stepCount = value;
}

float ProblemVector::setStepLength(float value)
{
    stepLength = value;
}
