#include "autodiff.h"

AutoDiff::AutoDiff()
{

}

AutoDiff cos(AutoDiff arg){
    return AutoDiff(cos(arg.getValue()), -sin(arg.getValue())*arg.getDerivative());
}
AutoDiff sin(AutoDiff arg){
    return AutoDiff(sin(arg.getValue()), cos(arg.getValue())*arg.getDerivative());
}
