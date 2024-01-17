#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QList>
#include "shape.h"
#include <QListWidget>


class QPaintEvent;
class QMouseEvent;

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = 0);

    QList<Shape*> shapeList;
    //add
    QListWidget* shapeListWidget;


public slots:
    void setCurrentShape(Shape::Code s) {
        if(s != currentShapeCode)
            currentShapeCode = s;  
    }

    void undo();
    void clearAll();

    void setPenWidth(int width);
    void copySelectedShapes(); // add
    void showContextMenu(const QPoint &pos);
    void changeSelectedShapeColor();
    void changeSelectedShapePenWidth();


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Shape::Code currentShapeCode;
    Shape *shape;
    bool endDraw;
    int currentPenWidth;

};

#endif // PAINTWIDGET_H
