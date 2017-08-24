#include "geometrycontainer.h"

GeometryContainer::GeometryContainer()
{

}

GeometryContainer::GeometryContainer(GeometryStack2::GeomStackTriangulated *ingeom,
                                     Wrap::WGLDataGeomStackTriangulated *inglData,
                                     Wrap::WGLObjectRenderer *inglRenderer)
{
    geom = ingeom;
    glData = inglData;
    glRenderer = inglRenderer;
}
