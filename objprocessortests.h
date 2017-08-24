#ifndef OBJPROCESSORTESTS_H
#define OBJPROCESSORTESTS_H
#include <QObject>

class ObjProcessorTests: public QObject
{
    Q_OBJECT
public:
    ObjProcessorTests();
private slots:
    void gaussNewtonStepTest();
    void internalSqrFuncTest();
    void internalSqrFuncTest1();

};

#endif // OBJPROCESSORTESTS_H
