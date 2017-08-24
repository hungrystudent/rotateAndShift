#include "objprocessortests.h"
#include <QCoreApplication>
#include <objobject.h>
#include <objprocessor.h>
#include <stdio.h>
#include <iostream>
#include <QDebug>
#include <QVector>
#include <QVector3D>
#include <kdtreenode.h>
#include <kdtree.h>
#include <QTime>
#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include "kdtreetests.h"
#include "autodifftests.h"

using namespace std;

void runTests()
{
    KDtreeTests tests;
    AutoDiffTests proctests;
    ObjProcessorTests objproctests;
    QTest::qExec(&tests);
    QTest::qExec(&proctests);
    QTest::qExec(&objproctests);
}

int main(int argc, char *argv[])
{
    runTests();
    QApplication a(argc, argv);
    //    int STEP = 10000;
    //    float STEP_LENGTH = 0.001;

    //    QVector<QVector3D> mesh1 = {QVector3D(0,0,0),QVector3D(1,0,0),QVector3D(0,3,0)};
    //    QVector<QVector3D> mesh2 = {QVector3D(0,0,0),QVector3D(0,1,0),QVector3D(0,3,0)};
    //    QVector<float> phaseVec;
    //    float shiftX=0,shiftY=0,rotation=0;
    //    phaseVec = OBJprocessor::getFullGrad(mesh1,mesh2,rotation,shiftX,shiftY,0,STEP,STEP_LENGTH);


    MainWindow w;
    w.show();
    return a.exec();
}
