#include "objprocessortests.h"
#include <qtest.h>
#include <objprocessor.h>
#include "autodiff.h"
#include <QVector>
#include <QVector3D>

ObjProcessorTests::ObjProcessorTests(){

}

void ObjProcessorTests::gaussNewtonStepTest()
{
    QVector<QVector3D> meshOne;
    QVector<QVector3D> meshTwo;
    meshOne = {QVector3D(0,0,0),QVector3D(0,1,0),QVector3D(1,0,0)};
    meshTwo = {QVector3D(2,0,0),QVector3D(3,0,0),QVector3D(3,1,0)};
    QVector<float> phaseVec = {0,0,0};
    phaseVec = OBJprocessor::gaussNewtonStep(meshOne,meshTwo,phaseVec);
    qDebug() << "gaussNewtonTested";
}

void ObjProcessorTests::internalSqrFuncTest()
{
    QVector<AutoDiff> res;
    res = OBJprocessor::internalSqrFunc(QVector3D(0,0,0),QVector3D(2,3,0),AutoDiff(0.3,1),AutoDiff(1,0),AutoDiff(1,0));
    bool ifequal1 = res[0].getDerivative() == 0;
    bool ifequal2 = res[0].getValue() == -1;
    bool ifequal3 = res[1].getDerivative() == 0;
    bool ifequal4 = res[1].getValue() == -2;
    QVERIFY((ifequal1 && ifequal2 && ifequal3 && ifequal4));
}

void ObjProcessorTests::internalSqrFuncTest1()
{
    QVector<AutoDiff> res;
    res = OBJprocessor::internalSqrFunc(QVector3D(0.5,0.7,0),QVector3D(2,3,0),AutoDiff(0.3,1),AutoDiff(0.2,0),AutoDiff(0.3,0));
    bool ifequal1 = qFuzzyCompare((float)res[0].getDerivative(),(float)-0.81649563433);
    bool ifequal2 = qFuzzyCompare((float)res[0].getValue(),(float)-1.52919589658);
    bool ifequal3 = qFuzzyCompare((float)res[1].getDerivative(),(float)0.270804103423);
    bool ifequal4 = qFuzzyCompare((float)res[1].getValue(),(float)-1.88350436567);
    QVERIFY((ifequal1 && ifequal2 && ifequal3 && ifequal4));
}


