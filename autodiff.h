#ifndef AUTODIFF_H
#define AUTODIFF_H
#include <math.h>

class AutoDiff
{
public:
    AutoDiff();
    double mValue, mDeriv;

public:
    AutoDiff(double inpValue, double inpDeriv): mValue(inpValue), mDeriv(inpDeriv){}
    double getValue() {return mValue;}
    double getDerivative() {return mDeriv;}

    AutoDiff operator+ (AutoDiff secArg){
        return AutoDiff(mValue + secArg.mValue, mDeriv + secArg.mDeriv);
    }

    AutoDiff operator- (AutoDiff secArg){
        return AutoDiff(mValue - secArg.mValue, mDeriv - secArg.mDeriv);
    }

    AutoDiff operator* (AutoDiff secArg){
        return AutoDiff(mValue*secArg.mValue, mValue*secArg.mDeriv+mDeriv*secArg.mValue);
    }

    AutoDiff operator/ (AutoDiff secArg){
        return AutoDiff(mValue / secArg.mValue,
                        (mDeriv*secArg.mValue - mValue*secArg.mDeriv) / secArg.mValue / secArg.mValue);
    }

    AutoDiff operator= (float secArg){
        return AutoDiff(secArg,0);
    }

    AutoDiff operator+ (float secArg){
        return AutoDiff(mValue + secArg, mDeriv);
    }

    AutoDiff operator- (float secArg){
        return AutoDiff(mValue - secArg, mDeriv);
    }

    AutoDiff operator* (float secArg){
        return AutoDiff(mValue*secArg, mDeriv*secArg);
    }

    AutoDiff operator/ (float secArg){
        return AutoDiff(mValue / secArg,mDeriv/secArg);
    }
};

AutoDiff cos(AutoDiff arg);
AutoDiff sin(AutoDiff arg);
#endif // AUTODIFF_H
