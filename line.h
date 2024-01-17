#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape
{

public:
    Line(QObject *parent = 0);
    void paint(QPainter &painter) const;
    Shape* clone() const override; //add

};

#endif // LINE_H
