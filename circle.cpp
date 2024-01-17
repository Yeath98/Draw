#include "Circle.h"
#include <cmath>
#include <QPainter>
#include <QApplication>

Circle::Circle(QObject *parent) : Shape(parent)
{
    shapeName = "Circle";
}
// //按住shift画圆形有问题所以没有实现，只是实现单纯的画圆形
// void Circle::paint(QPainter & painter) const
// {

//     int len = pow(start.x() - end.x(), 2);
//     int wid = pow(start.y() - end.y(), 2);
//     // 利用勾股定理求出半径
//     int r = (int)(sqrt(len + wid));

//     // 设置填充颜色
//     painter.setBrush(getFillColor());

//     painter.drawEllipse(start, r, r);
// }

//画椭圆
void Circle::paint(QPainter & painter) const
{
    QPen pen;
    pen.setWidth(penWidth);
    painter.setPen(pen);

    int len = abs(start.x() - end.x());
    int wid = abs(start.y() - end.y());

    // 提供矩形区域的左上角坐标和宽度、高度
    QRect ellipseRect(start.x(), start.y(), len, wid);

    // 设置填充颜色
    painter.setBrush(getFillColor());


    painter.drawEllipse(ellipseRect);
}
Shape* Circle::clone() const
{
    Circle *circle = new Circle();
    circle->shapeName = this->shapeName;
    circle->fillColor = this->fillColor;
    circle->penWidth = this->penWidth;
    circle->start = this->start;
    circle->end = this->end;

    return circle;
}
