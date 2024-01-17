#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPoint>
#include <QString>
#include <QColor>
#include <QPainter>
class QPainter;

class Shape : public QObject
{
    Q_OBJECT

public:

    enum Code {
        Line,
        Rect,
        Circle,
        Star,
        Triangle
    };

    QString shapeName;
    QColor fillColor;
    int penWidth;

    explicit Shape(QObject *parent = 0);
    virtual Shape* clone() const = 0; //add


    void setStart(QPoint s)
    {
        start = s;
    }

    void setEnd(QPoint e)
    {
        end = e;
    }

    QPoint getStart()
    {
        return start;
    }

    QPoint getEnd()
    {
        return end;
    }

    void virtual paint(QPainter & painter) const = 0;

    // 新增成员变量和设置函数
    void setFillColor(const QColor& color);
    QColor getFillColor() const;
    void setPenWidth(int width);
    int getPenWidth() const;


protected:
    QPoint start;
    QPoint end;


};

#endif // SHAPE_H
