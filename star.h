#ifndef STAR_H
#define STAR_H
#include "shape.h"

class Star : public Shape
{

public:
    Star(QObject *parent = 0);

    void paint(QPainter &painter) const;
    Shape* clone() const override; //add

};

#endif // STAR_H
