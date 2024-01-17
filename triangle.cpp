#include "triangle.h"
#include <QPainter>

Triangle::Triangle(QObject *parent) : Shape(parent)
{
    shapeName = "Triangle";
}

void Triangle::paint(QPainter &painter) const
{
    QPen pen;
    pen.setWidth(penWidth);
    painter.setPen(pen);
    // 设置填充颜色
    painter.setBrush(getFillColor());

    QPolygonF polygon;
    polygon << QPointF(start.x(), end.y())
            << QPointF((start.x() + end.x()) / 2.0, start.y())
            << QPointF(end.x(), end.y());

    painter.drawPolygon(polygon);
}
Shape* Triangle::clone() const
{
    Triangle *triange = new Triangle();
    triange->shapeName = this->shapeName;
    triange->fillColor = this->fillColor;
    triange->penWidth = this->penWidth;
    triange->start = this->start;
    triange->end = this->end;

    return triange;
}
