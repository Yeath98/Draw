#include "paintwidget.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QListWidget>
#include <QVBoxLayout>
#include <QSplitter>
#include <QColorDialog>
#include <QMessageBox>
#include <QMenu>
#include <QInputDialog>

#include "line.h"
#include "rect.h"
#include "circle.h"
#include "triangle.h"
#include "star.h"

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent), currentShapeCode(Shape::Line), shape(NULL), endDraw(false),currentPenWidth (1)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //添加列表窗口，去保存图形item
    shapeListWidget = new QListWidget(this);
    shapeListWidget->setGeometry(QRect(10, 10, 200, 300));  // 设置适当的位置和大小

    //双击复制
    connect(shapeListWidget, &QListWidget::itemDoubleClicked, this, &PaintWidget::copySelectedShapes);

    // 添加右键菜单
    shapeListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(shapeListWidget, &QListWidget::customContextMenuRequested, this, &PaintWidget::showContextMenu);
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 设置画布填充颜色为白色
    painter.fillRect(this->rect(), Qt::white);


    // 设置填充颜色为透明
    painter.setBrush(Qt::transparent);


    // 依次绘制shapeList里的图形
    for (int i = 0; i < shapeList.size(); ++i)
    {
        shapeList[i]->paint(painter);
    }
    // // 可以这么写
    // foreach(Shape * shape, shapeList)
    // {
    //     shape->paint(painter);
    // }

}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    switch (currentShapeCode)
    {
    case Shape::Line:
    {
        shape = new Line(this);
        break;
    }
    case Shape::Rect: {
        shape = new Rect(this);
        break;
    }
    case Shape::Circle:
    {
        shape = new Circle(this);
        break;
    }
    case Shape::Triangle:
    {
        shape = new Triangle(this);
        break;
    }
    case Shape::Star:
    {
        shape = new Star(this);
        break;
    }
    }
    if(shape != NULL) {
        endDraw = false;
        shapeList<<shape;
        shape->setStart(event->pos());
        shape->setEnd(event->pos());
        shape->setPenWidth(currentPenWidth); // 设置线条粗细
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(shape && !endDraw) {
        shape->setEnd(event->pos());
//        repaint();
        update(); // update方法效果更好,能减少颤动
    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    endDraw = true;
    if (shape)
    {
        //填充颜色，这个地方有个问是Line也会触发，因为捕捉鼠标释放
        QColor fillColor = QColorDialog::getColor(Qt::white, this, tr("选择填充颜色"));
        // 设置图形的填充颜色
        shape->setFillColor(fillColor);
        // 设置图形线条的粗细
        shape->setPenWidth(currentPenWidth);
        // 将图形的描述信息添加到 shapeListWidget 中
        QListWidgetItem *item = new QListWidgetItem(shape->shapeName);
        shapeListWidget->addItem(item);
        update();
    }
}

// void PaintWidget::undo()
// {
//     if (!shapeList.empty())
//     {
//         shapeList.pop_back();
//     }
//     update();
// }
void PaintWidget::undo()
{
    // 获取所有选中的项
    QList<QListWidgetItem*> selectedItems = shapeListWidget->selectedItems();

    // 逐个撤销选中的项
    foreach (QListWidgetItem* selectedItem, selectedItems)
    {
        int index = shapeListWidget->row(selectedItem);

        if (index >= 0 && index < shapeList.size())
        {
            // 从 shapeList 中移除相应的图形
            shapeList.removeAt(index);

            // 从 shapeListWidget 中移除相应的项
            shapeListWidget->takeItem(index);
            //否则删除后不会消失
            update();
        }
    }
}


void PaintWidget::clearAll()
{
    shapeList.clear();
    shapeListWidget->clear();
    update();
}

void PaintWidget::setPenWidth(int width)
{
    currentPenWidth = width;
    if (shape)
    {
        shape->setPenWidth(width);
    }
}

// //add
// void PaintWidget::copySelectedShapes()
// {
//     // Get all selected items
//     QList<QListWidgetItem *> selectedItems = shapeListWidget->selectedItems();

//     foreach (QListWidgetItem *selectedItem, selectedItems)
//     {
//         int index = shapeListWidget->row(selectedItem);

//         if (index >= 0 && index < shapeList.size())
//         {
//             // Create a copy of the selected shape
//             Shape *copiedShape = shapeList[index]->clone();
//             if (copiedShape)
//             {
//                 // Add the copied shape to the shape list
//                 shapeList << copiedShape;

//                 // Add a new item to the shapeListWidget for the copied shape
//                 QListWidgetItem *item = new QListWidgetItem(copiedShape->shapeName);
//                 shapeListWidget->addItem(item);
//                 update();
//             }
//             else
//             {
//                 QMessageBox::warning(this, tr("Error"), tr("Failed to copy shape."));
//             }
//         }
//     }
// }
void PaintWidget::copySelectedShapes()
{
    // 获取所有选中的项
    QList<QListWidgetItem*> selectedItems = shapeListWidget->selectedItems();

    // 逐个复制选中的项
    foreach (QListWidgetItem* selectedItem, selectedItems)
    {
        int index = shapeListWidget->row(selectedItem);

        if (index >= 0 && index < shapeList.size())
        {
            //调用clone函数来创建该形状的副本
            Shape *copiedShape = shapeList[index]->clone();

            //偏移复制的形状位置(可以根据需要调整偏移量)
            QPoint offset(50, 50);
            copiedShape->setStart(copiedShape->getStart() + offset);
            copiedShape->setEnd(copiedShape->getEnd() + offset);

            //test
            qDebug() << "Copied shape: " << copiedShape->shapeName;

            //将复制的形状添加到形状列表中
            shapeList.append(copiedShape);

            //将复制形状的描述添加到shapeListWidget
            QListWidgetItem *item = new QListWidgetItem(copiedShape->shapeName);
            shapeListWidget->addItem(item);
        }
    }
    update();
}
// 添加以下成员函数用于显示右键菜单
void PaintWidget::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Shape Options"), this);

    QAction *changeColorAction = contextMenu.addAction(tr("Change Color"));
    QAction *changePenWidthAction = contextMenu.addAction(tr("Change Pen Width"));

    connect(changeColorAction, &QAction::triggered, this, &PaintWidget::changeSelectedShapeColor);
    connect(changePenWidthAction, &QAction::triggered, this, &PaintWidget::changeSelectedShapePenWidth);

    contextMenu.exec(shapeListWidget->mapToGlobal(pos));
}

// 添加以下成员函数用于更改选中图形的颜色
void PaintWidget::changeSelectedShapeColor()
{
    QList<QListWidgetItem *> selectedItems = shapeListWidget->selectedItems();
    foreach (QListWidgetItem *selectedItem, selectedItems)
    {
        int index = shapeListWidget->row(selectedItem);
        if (index >= 0 && index < shapeList.size())
        {
            QColor newColor = QColorDialog::getColor(Qt::white, this, tr("Select Fill Color"));
            shapeList[index]->setFillColor(newColor);
            update();
        }
    }
}

// 添加以下成员函数用于更改选中图形的线条粗细
void PaintWidget::changeSelectedShapePenWidth()
{
    QList<QListWidgetItem *> selectedItems = shapeListWidget->selectedItems();
    foreach (QListWidgetItem *selectedItem, selectedItems)
    {
        int index = shapeListWidget->row(selectedItem);
        if (index >= 0 && index < shapeList.size())
        {
            bool ok;
            int newPenWidth = QInputDialog::getInt(this, tr("Change Pen Width"), tr("Enter new pen width:"), shapeList[index]->getPenWidth(), 1, 10, 1, &ok);
            if (ok)
            {
                shapeList[index]->setPenWidth(newPenWidth);
                update();
            }
        }
    }
}
