#include "rect.h"
#include <QPainter>

Rect::Rect(QObject *parent) : Shape(parent)
{
    shapeName = "Rect";
}

void Rect::paint(QPainter &painter) const
{
    QPen pen;
    pen.setWidth(penWidth);
    painter.setPen(pen);
    // 设置填充颜色
    painter.setBrush(getFillColor());

    painter.drawRect(start.x(), start.y(),
                     end.x() - start.x(), end.y() - start.y());
}
Shape* Rect::clone() const
{
    Rect *rect = new Rect();
    rect->shapeName = this->shapeName;
    rect->fillColor = this->fillColor;
    rect->penWidth = this->penWidth;
    rect->start = this->start;
    rect->end = this->end;

    return rect;
}
