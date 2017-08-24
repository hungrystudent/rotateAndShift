#ifndef POLYGON_H
#define POLYGON_H
#include<QTextStream>
#include<QVector>
#include <QVector3D>

class MyPolygon
{
public:
    MyPolygon();
    MyPolygon(const QStringList &objStringList);
    MyPolygon(const QVector<int> &surfIntVect);
    int vertex(int vertexInd) const;
    QVector<int> vertArr;
    bool operator== (const MyPolygon &b) const;
    QVector<QVector3D> normalMap;
};

#endif // POLYGON_H
