#include "animationfunctor.h"
#include <qthread.h>

AnimationFunctor::AnimationFunctor(Wrap::WViewport *inpViewportContext,QVector<GeometryContainer> &geometries, MainWindow *inpWindow)
{
    geometry = geometries[0];
    mMesh = geometries[0].geom->v;
    mTargetMesh =  geometries[1].geom->v;
    mViewportContext = inpViewportContext;
    window = inpWindow;
}

void AnimationFunctor::update(float inpRotation, float inpShiftX,float inpShiftY)
{
    for(int j=0;j<mMesh.count();j++){
        float rotX = geometry.geom->v[j].x()*cos(inpRotation) - geometry.geom->v[j].y()*sin(inpRotation);
        float rotY = geometry.geom->v[j].x()*sin(inpRotation) + geometry.geom->v[j].y()*cos(inpRotation);
        float transX = rotX + inpShiftX;
        float transY = rotY + inpShiftY;
        mMesh[j].setX(transX);
        mMesh[j].setY(transY);
    }
    geometry.glData->setVertices(mMesh);
    window->markVerts(mMesh,mTargetMesh);
    mViewportContext->updateGL();
    qDebug() << "floating mesh X coord";
    qDebug() << "X0 = " << mMesh[0].x();
    qDebug() << "X1 = " << mMesh[1].x();
    qDebug() << "X2 = " << mMesh[2].x();
}
