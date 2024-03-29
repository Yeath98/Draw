#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{

public:
    Circle(QObject *parent = 0);
    void paint(QPainter &painter) const;
    Shape* clone() const override; //add
};

#endif // CIRCLE_H
