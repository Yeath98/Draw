#include "star.h"
#include <QPainter>

Star::Star(QObject *parent) : Shape(parent)
{
    shapeName = "Star";
}

void Star::paint(QPainter &painter) const
{
    QPen pen;
    pen.setWidth(penWidth);
    painter.setPen(pen);
    // 设置填充颜色
    painter.setBrush(getFillColor());

    QPolygonF polygon;
    QPointF center = QPointF((start.x() + end.x()) / 2.0, (start.y() + end.y()) / 2.0);
    double radius = qMin(abs(start.x() - end.x()), abs(start.y() - end.y())) / 2.0;

    for (int i = 0; i < 5; ++i) {
        double outerAngle = 2.0 * M_PI * (0.2 * i - 0.1);
        double innerAngle = 2.0 * M_PI * (0.2 * i);
        QPointF outerPoint = center + QPointF(radius * cos(outerAngle), radius * sin(outerAngle));
        QPointF innerPoint = center + QPointF((radius / 2.0) * cos(innerAngle), (radius / 2.0) * sin(innerAngle));
        polygon << outerPoint << innerPoint;
    }

    painter.drawPolygon(polygon);
}
Shape* Star::clone() const
{
    Star *star = new Star();
    star->shapeName = this->shapeName;
    star->fillColor = this->fillColor;
    star->penWidth = this->penWidth;
    star->start = this->start;
    star->end = this->end;
    return star;
}
