#ifndef GEOMETRYCONTAINER_H
#define GEOMETRYCONTAINER_H

#include "wcontextnavigation.h"
#include "wgldatageomstacktriangulated.h"
#include "wglmaterialsurface.h"
#include "wglmaterialwireframe.h"
#include "wglobjectrenderer.h"
#include "wglgrid.h"
#include "wgldots.h"

class GeometryContainer
{
public:
    GeometryContainer();
    GeometryContainer(GeometryStack2::GeomStackTriangulated *ingeom,
                      Wrap::WGLDataGeomStackTriangulated *inglData,
                      Wrap::WGLObjectRenderer *inglRenderer);

    GeometryStack2::GeomStackTriangulated *geom = nullptr;
    Wrap::WGLDataGeomStackTriangulated *glData = nullptr;
    Wrap::WGLObjectRenderer *glRenderer = nullptr;
};

#endif // GEOMETRYCONTAINER_H
