#include "shape.h"
#include <iostream>
Shape::Shape(QObject *parent) : QObject(parent), fillColor(Qt::white), penWidth(1)
{
}
//填充颜色
void Shape::setFillColor(const QColor& color)
{
    fillColor = color;
}

QColor Shape::getFillColor() const
{
    return fillColor;
}
//粗细
void Shape::setPenWidth(int width)
{
    penWidth = width;
}
int Shape::getPenWidth() const
{
    return penWidth;
}
