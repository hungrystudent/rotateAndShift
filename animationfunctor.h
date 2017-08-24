#ifndef ANIMATIONFUNCTOR_H
#define ANIMATIONFUNCTOR_H

#include "wcontextnavigation.h"
#include "wgldatageomstacktriangulated.h"
#include "wglmaterialsurface.h"
#include "wglmaterialwireframe.h"
#include "wglobjectrenderer.h"
#include "wglgrid.h"
#include <kdtreenode.h>
#include "wgldots.h"
#include <geometrycontainer.h>
#include <mainwindow.h>

class AnimationFunctor
{
public:
    AnimationFunctor(Wrap::WViewport *inpViewportContext,
                     QVector<GeometryContainer> &geometries,
                     MainWindow *inpWindow);
    void update(float inpRotation, float inpShiftX,float inpShiftY);
private:
    Wrap::WViewport *mViewportContext;
    GeometryContainer geometry;
    QVector<QVector3D> mMesh;
    QVector<QVector3D> mTargetMesh;
    MainWindow *window;
};

#endif // ANIMATIONFUNCTOR_H
