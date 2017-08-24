#ifndef AUTODIFFTESTS_H
#define AUTODIFFTESTS_H
#include <QObject>

class AutoDiffTests: public QObject
{
    Q_OBJECT
public:
    AutoDiffTests();
private slots:
    void testAutoDiffsin1();
    void testAutoDiffsin2();
    void testAutoDiffsin3();
};

#endif // OBJPROCESSORTESTS_H
