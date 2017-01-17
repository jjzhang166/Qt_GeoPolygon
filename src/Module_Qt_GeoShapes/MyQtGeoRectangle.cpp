#include "MyQtGeoRectangle.h"
#include <QDebug>

MyQtGeoRectangle::MyQtGeoRectangle(const QGeoCoordinate &bottomLeft, const QGeoCoordinate &topRight,
                                   bool *ok, QObject *parent)   : MyQtGeoShapeBase(parent)
{
    geoRectangle.setBottomLeft(bottomLeft);
    geoRectangle.setTopRight(topRight);
    *ok=geoRectangle.isValid();
}

bool  MyQtGeoRectangle::containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule)
{
    if(!geoCoordinate.isValid())
        qDebug()<<"Error: invalid geoCooridinate:"<<geoCoordinate;
    return geoRectangle.contains(geoCoordinate);
}

QGeoRectangle MyQtGeoRectangle::getGeoRectangle() const
{
    return geoRectangle;
}

void MyQtGeoRectangle::setGeoRectangle(const QGeoRectangle &value)
{
    geoRectangle = value;
}