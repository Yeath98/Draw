#include "line.h"
#include <QPainter>

Line::Line(QObject *parent) : Shape(parent)
{
    shapeName= "Line";
}

void Line::paint(QPainter &painter) const
{

    QPen pen;
    pen.setWidth(penWidth);
    painter.setPen(pen);
    // 设置填充颜色,改变线条的颜色
    painter.setBrush(getFillColor());
    painter.drawLine(start, end);
}
Shape* Line::clone() const
{
    Line *line = new Line();
    line->shapeName = this->shapeName;
    line->fillColor = this->fillColor;
    line->penWidth = this->penWidth;
    line->start = this->start;
    line->end = this->end;

    return line;
}
