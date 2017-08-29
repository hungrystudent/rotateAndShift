#ifndef OBJREADER_H
#define OBJREADER_H
#include <QString>
#include <objobject.h>
#include <QFile>
#include <problemvector.h>
#include <autodiff.h>

class OBJprocessor
{
private:
    static OBJobject parse(QFile &file2parse);

public:

    OBJprocessor();

    static QVector<float> gaussNewton3D(const QVector<QVector3D> &meshOne, const QVector<QVector3D> &meshTwo,
                                        QVector<float> inpPhasesVec,
                                        ProblemVector inpProblemSetup,
                                        AnimationFunctor *inpAnimFunctor);
    static QVector<float> gaussNewton3DStep(const QVector<QVector3D> &meshOne, const QVector<QVector3D> &meshTwo,
                                            const float rotation,
                                            const float quatX,const float quatY,const float quatZ,
                                            const float shiftX,const float shiftY,const float shiftZ);
    template<typename T> static QVector<T> internalSqrFunc3D(const QVector3D &pointOne, const QVector3D &pointTwo,
                                                             const T rotation,
                                                             const T quatX, const T quatY, const T quatZ,
                                                             const T shiftX, const T shiftY, const T shiftZ){
        QVector<T> array2return;
        T rotX = (1 - 2*quatY*quatY - 2*quatZ*quatZ)*pointOne.x() +
                (2*quatX*quatY-2*quatZ*rotation)*pointOne.y() +
                (2*quatX*quatZ + 2*quatY*rotation)*pointOne.z();

        T rotY = (2*quatX*quatY+2*quatZ*rotation)*pointOne.x() +
                (1-2*quatX*quatX-2*quatZ*quatZ)*pointOne.y() +
                (2*quatY*quatZ-2*quatX*rotation)*pointOne.z();


    }

    static QVector<float> gaussNewtonStep(const QVector<QVector3D> &meshOne,
                                          const QVector<QVector3D> &meshTwo,
                                          QVector<float> inpPhasesVec);
    template<typename T> static QVector<T> internalSqrFunc(const QVector3D &pointOne, const QVector3D &pointTwo,
                                                           const T rotation, const T shiftX, const T shiftY){
        QVector<T> array2return;
        T rotX = cos(rotation)*pointOne.x() - sin(rotation)*pointOne.y();
        T rotY = sin(rotation)*pointOne.x() + cos(rotation)*pointOne.y();
        T transX = rotX + shiftX;
        T transY = rotY + shiftY;
        T residualX = transX - pointTwo.x();
        T residualY = transY - pointTwo.y();

        array2return.append(residualX);
        array2return.append(residualY);
        return array2return;
    }

    template<typename T> static QVector<T> getColumnSqrFunc(const QVector3D &pointOne, const QVector3D &pointTwo,
                                                            const T rotation, const T shiftX, const T shiftY){

    }

    static bool read(const QString &objfilename, OBJobject &obj2return);
    static QVector<MyPolygon> triangulate(const QVector<MyPolygon> &inpPolygonArr);
    static QVector<QVector3D> computeNormals(const QVector<MyPolygon> &inputPolygonArr,
                                             const QVector<QVector3D> &inputVertArr);
    static QVector<float> getGradientForOnePoint(const QVector3D &pointOne,
                                                 const QVector3D &pointTwo,
                                                 const float rotation,
                                                 const float shiftX,
                                                 const float shiftY,
                                                 const float shitfZ);
    static QVector<float> getGrad(const QVector<QVector3D> &meshOne, const QVector<QVector3D> &meshTwo,
                                  const float rotation,
                                  const float shiftX,
                                  const float shiftY,
                                  const float shitfZ);
    static float errFuncForOneResidual(const QVector3D &pointOne,
                                       const QVector3D &pointTwo,
                                       const float rotation,
                                       const float shiftX, const float shiftY);
    static QVector<float> gradientDescent(const QVector<QVector3D> &meshOne,
                                          const QVector<QVector3D> &meshTwo,
                                          ProblemVector inpProblemSetup,
                                          AnimationFunctor *inAnimFunctor);
    static QVector<float> gaussNewtonMethod(const QVector<QVector3D> &meshOne,
                                            const QVector<QVector3D> &meshTwo,
                                            ProblemVector inpProblemSetup, AnimationFunctor *inpAnimFunctor);
};

#endif // OBJREADER_H
