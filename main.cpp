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
    MainWindow w;
    w.show();
    return a.exec();
}
