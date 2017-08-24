#include "autodifftests.h"
#include <QTest>
#include <autodiff.h>


AutoDiffTests::AutoDiffTests()
{

}

void AutoDiffTests::testAutoDiffsin1()
{
    AutoDiff xd(5, 1);
    AutoDiff ad(5, 0);
    AutoDiff two(2, 0);
    AutoDiff resa(0,0);
    resa = (ad*xd*xd*xd - cos(xd/two));
    QCOMPARE(resa.getDerivative(),375.299236072);
}

void AutoDiffTests::testAutoDiffsin2()
{
    AutoDiff rotX;
    AutoDiff rotation(2,1);
    AutoDiff xcoor(1.5,0);
    AutoDiff ycoor(2,0);
    rotX = cos(rotation)*xcoor - sin(rotation)*ycoor;
    QVERIFY(qFuzzyCompare((float)rotX.getDerivative(),(float)-0.531652));
}

void AutoDiffTests::testAutoDiffsin3()
{
    AutoDiff res;
    AutoDiff x(7,1);
    res = x*sin(cos(x*x*x*x));
    QVERIFY(qFuzzyCompare((float)res.getDerivative(),(float)-5476.348696));
}
