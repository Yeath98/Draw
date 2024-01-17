#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>
#include <QPoint>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QVBoxLayout>
#include <QSplitter>
#include <QListWidget>
#include <QSlider>

#include "circle.h"
#include "line.h"
#include "rect.h"
#include "triangle.h"
#include "star.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 1. 初始化所有的菜单栏，工具栏，Group，Action
    initMenusToolBarsAndActionGroups();
    initAllActions();

    // 2. 添加状态栏
    statusBar();


    // 3. 创建画布对象，居中
    paintWidget = new PaintWidget(this);
    setCentralWidget(paintWidget);


    // 4. 连接
    connectAllThings();

}

// 初始化Menu, ToolBar和QActionGroup
void MainWindow::initMenusToolBarsAndActionGroups()
{
    this->fileMenu = menuBar()->addMenu(tr("&File"));
    this->drawMenu = menuBar()->addMenu(tr("&Draw"));
    this->editMenu = menuBar()->addMenu(tr("&Edit"));
    this->helpMenu = menuBar()->addMenu(tr("&Help"));

    this->fileToolBar = this->addToolBar(tr("&File"));
    this->drawToolBar = this->addToolBar(tr("&Draw"));
    this->editToolBar = this->addToolBar(tr("&Edit"));

    this->group = new QActionGroup(this);

    // 添加一个 QSlider 到工具栏用于Pen粗细设置
    penWidthSlider = new QSlider(Qt::Horizontal);
    penWidthSlider->setRange(1, 10); // 设置线条粗细的范围
    penWidthSlider->setValue(1);     // 设置默认值
    penWidthSlider->setToolTip(tr("Set pen width"));
    penWidthSlider->setStatusTip(tr("Set pen width"));
    penWidthSlider->setFixedWidth(100); // 设置固定宽度
    drawToolBar->addWidget(penWidthSlider);

    // 添加一个 QAction 用于触发帮助消息框
    QAction *helpAction = new QAction(tr("&Operation"), this);
    helpAction->setToolTip(tr("Show help message box."));
    helpAction->setStatusTip(tr("Show help message box."));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(showHelpMessageBox()));

    // 将该 QAction 直接添加到 Help 菜单
    helpMenu->addAction(helpAction);

}

void MainWindow::showHelpMessageBox()
{
    QString helpMessage = tr("This is the help message!\n\n");
    helpMessage += tr("双击列表中的图形可以直接复制(50,50)偏移量的图形！\n");
    helpMessage += tr("右键列表中的图形可以进行修改颜色和线条粗细！\n");
    helpMessage += tr("滑轮为线条粗细！\n");
    helpMessage += tr("其余的均可根据菜单栏或提示栏直接使用！\n");
    helpMessage += tr("Draw_Tools by zihao！\n");

    QMessageBox::information(this, tr("Operation"), helpMessage);
}

// 初始化所有的Action
void MainWindow::initAllActions()
{
    // 打开Action
    this->openAction = new QAction(tr("&Open"), this);
    openAction->setToolTip(tr("Open a file."));
    openAction->setStatusTip(tr("Open a file."));
    fileMenu->addAction(openAction);
    fileToolBar->addAction(openAction);

    // 保存Action
    this->saveAction = new QAction(tr("&Save"), this);
    saveAction->setToolTip(tr("Save this file."));
    saveAction->setStatusTip(tr("Save this file."));
    fileMenu->addAction(saveAction);
    fileToolBar->addAction(saveAction);

    // 打印Action,几乎用不到
    this->printAction = new QAction(tr("&Print"), this);
    printAction->setToolTip(tr("Print to ( *.oxps  *.xps ) file."));
    printAction->setStatusTip(tr("Print to ( *.oxps  *.xps ) file."));
    fileMenu->addAction(printAction);
    fileToolBar->addAction(printAction);


    // 画线Action
    this->drawLineAction = new QAction(tr("&Line"), this);
    drawLineAction->setToolTip(tr("Draw a line."));
    drawLineAction->setStatusTip(tr("Draw a line."));
    drawLineAction->setCheckable(true);
    drawLineAction->setChecked(true);
    group->addAction(drawLineAction);
    drawToolBar->addAction(drawLineAction);
    drawMenu->addAction(drawLineAction);

    // 画矩形Action
    this->drawRectAction = new QAction(tr("&Rectangle"), this);
    drawRectAction->setToolTip(tr("Draw a rectangle."));
    drawRectAction->setStatusTip(tr("Draw a rectangle."));
    drawRectAction->setCheckable(true);
    group->addAction(drawRectAction);
    drawToolBar->addAction(drawRectAction);
    drawMenu->addAction(drawRectAction);

    // 画圆Action
    this->drawCircleAction = new QAction(tr("&Circle"), this);
    drawCircleAction->setToolTip(tr("Draw a circle."));
    drawCircleAction->setStatusTip(tr("Draw a circle."));
    drawCircleAction->setCheckable(true);
    group->addAction(drawCircleAction);
    drawToolBar->addAction(drawCircleAction);
    drawMenu->addAction(drawCircleAction);

    // 画三角形Action
    this->drawTriangleAction = new QAction(tr("&Triangle"), this);
    drawTriangleAction->setToolTip(tr("Draw a Triangle."));
    drawTriangleAction->setStatusTip(tr("Draw a Triangle."));
    drawTriangleAction->setCheckable(true);
    group->addAction(drawTriangleAction);
    drawToolBar->addAction(drawTriangleAction);
    drawMenu->addAction(drawTriangleAction);

    // 画五角星Action
    this->drawStarAction = new QAction(tr("&Star"), this);
    drawStarAction->setToolTip(tr("Draw a Star."));
    drawStarAction->setStatusTip(tr("Draw a Star."));
    drawStarAction->setCheckable(true);
    group->addAction(drawStarAction);
    drawToolBar->addAction(drawStarAction);
    drawMenu->addAction(drawStarAction);

    // 删除Action
    this->deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setToolTip(tr("Delete last shape."));
    deleteAction->setStatusTip(tr("Delete last shape."));
    editMenu->addAction(deleteAction);
    editToolBar->addAction(deleteAction);

    // 清空Action
    this->clearAllAction = new QAction(tr("&Clear All"), this);
    clearAllAction->setToolTip(tr("Clear all shapes."));
    clearAllAction->setStatusTip(tr("Clear all shapes."));
    editMenu->addAction(clearAllAction);
    editToolBar->addAction(clearAllAction);
}

// connect所有的函数
void MainWindow::connectAllThings()
{
    // 连接两个File Action
    connect(saveAction, SIGNAL(triggered()),
            this, SLOT(save()));
    connect(openAction, SIGNAL(triggered()),
            this, SLOT(open()));
    connect(printAction, SIGNAL(triggered()),
            this, SLOT(print()));

    // 连接Draw Action
    connect(drawLineAction, SIGNAL(triggered()),
            this, SLOT(drawLineActionTriggered()));
    connect(drawRectAction, SIGNAL(triggered()),
            this, SLOT(drawRectActionTriggered()));
    connect(drawCircleAction, SIGNAL(triggered()),
            this, SLOT(drawCircleActionTriggered()));
    connect(drawTriangleAction, SIGNAL(triggered()),
            this, SLOT(drawTriangleActionTriggered()));
    connect(drawStarAction, SIGNAL(triggered()),
            this, SLOT(drawStarActionTriggered()));

    // 连接两个Edit Action
    connect(clearAllAction, SIGNAL(triggered()),
            paintWidget, SLOT(clearAll()));
    connect(deleteAction, SIGNAL(triggered()),
            paintWidget, SLOT(undo()));

    // 连接 MainWindow发出的changeCurrentShape信号
    // 与 paintWidget的setCurrentShape槽
    connect(this, SIGNAL(changeCurrentShape(Shape::Code)),
            paintWidget, SLOT(setCurrentShape(Shape::Code)));

    connect(penWidthSlider, SIGNAL(valueChanged(int)),
            paintWidget, SLOT(setPenWidth(int)));

}

void MainWindow::drawLineActionTriggered()
{
    emit changeCurrentShape(Shape::Line);
}

void MainWindow::drawRectActionTriggered()
{
    emit changeCurrentShape(Shape::Rect);
}

void MainWindow::drawCircleActionTriggered()
{
    emit changeCurrentShape(Shape::Circle);
}
void MainWindow::drawTriangleActionTriggered()
{
    emit changeCurrentShape(Shape::Triangle);
}
void MainWindow::drawStarActionTriggered()
{
    emit changeCurrentShape(Shape::Star);
}


void MainWindow::open()
{
    // 1. 获取文件路径来打开文件，并检验文件是否打开。否则直接return
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    ".", tr("dat Files (*.dat)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(NULL, tr("Warning"), tr("File not opened"));
        return;
    }

    // 2. 清空数据列表
    paintWidget->shapeList.clear();
    paintWidget->shapeListWidget->clear();

    // 3. 创建一个QtextStream对象来操纵file
    QTextStream in(&file);

    // 4. 当QtextStream对象没有到末尾时，循环
    while (! in.atEnd())
    {
        // 4.1 取得文件中的shapeName, 存入s中
        QString s;
        in >> s;
        if (s == "")
            break;

        // 4.2 根据文件中shapeName的值，决定创建Shape的哪一种子对象。然后把newShape指向新创建的对象
        Shape * newShape;
        if (s == "Circle")
        {
            //创建新的Shape，对应不同图形
            newShape = new Circle(this->paintWidget);
            //背景颜色
            QString fillColorStr;
            in >> fillColorStr;
            QColor fillColor(fillColorStr);
            newShape->setFillColor(fillColor);
            //粗细
            int penWidth;
            in >> penWidth;
            newShape->setPenWidth(penWidth);

            paintWidget->shapeListWidget->addItem(newShape->shapeName);
        }
        else if (s == "Rect")
        {
            newShape = new Rect(this->paintWidget);
            //背景颜色
            QString fillColorStr;
            in >> fillColorStr;
            QColor fillColor(fillColorStr);
            newShape->setFillColor(fillColor);
            //粗细
            int penWidth;
            in >> penWidth;
            newShape->setPenWidth(penWidth);

            paintWidget->shapeListWidget->addItem(newShape->shapeName);
        }
        else if (s == "Line")
        {
            newShape = new Line(this->paintWidget);
            //背景颜色
            QString fillColorStr;
            in >> fillColorStr;
            QColor fillColor(fillColorStr);
            newShape->setFillColor(fillColor);
            //粗细
            int penWidth;
            in >> penWidth;
            newShape->setPenWidth(penWidth);

            paintWidget->shapeListWidget->addItem(newShape->shapeName);
        }
        else if (s == "Triangle")
        {
            newShape = new Triangle(this->paintWidget);
            //背景颜色
            QString fillColorStr;
            in >> fillColorStr;
            QColor fillColor(fillColorStr);
            newShape->setFillColor(fillColor);
            //粗细
            int penWidth;
            in >> penWidth;
            newShape->setPenWidth(penWidth);

            paintWidget->shapeListWidget->addItem(newShape->shapeName);
        }
        else if (s == "Star")
        {
            newShape = new Star(this->paintWidget);
            //背景颜色
            QString fillColorStr;
            in >> fillColorStr;
            QColor fillColor(fillColorStr);
            newShape->setFillColor(fillColor);
            //粗细
            int penWidth;
            in >> penWidth;
            newShape->setPenWidth(penWidth);

            paintWidget->shapeListWidget->addItem(newShape->shapeName);
        }

        // 4.3 获取文件中的四个坐标值，存入新创建的Shape的子对象中
        int sx, sy, ex, ey;
        in >> sx >> sy >> ex >> ey;
        newShape->setStart(QPoint(sx, sy));
        newShape->setEnd(QPoint(ex, ey));

        // 4.4 把创建好的Shape的子对象添加到数据列表中
        paintWidget->shapeList.append(newShape);
    }

    // 5. 刷新画布，显示出上一步添加的所有新数据。关闭文件
    paintWidget->update();
    file.close();
}

void MainWindow::save()
{
    // 1. 获取文件路径来打开文件，并检验文件是否打开。否则直接return
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    ".", tr("dat Files (*.dat)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(NULL, tr("Warning"), tr("File not saved!"));
        return;
    }

    // 2. 创建一个QtextStream对象来操纵file
    QTextStream out(&file);

    // 3. 通过循环，把数据列表中的每一个Shape对象的各项属性都写入文件中。关闭文件
    foreach (Shape *shape, paintWidget->shapeList)
    {
        // windows下换行是\r\n，unix下换行是\n，如果在行末只添加\n, 在windows下用记事本打开此文件时会丢失换行符，所以在行末添加\r\n
        out << shape->shapeName             << "\r\n"
            << shape->getFillColor().name() << "\r\n"
            << shape->getPenWidth()         << "\r\n"
            << shape->getStart().x()        << "\r\n"
            << shape->getStart().y()        << "\r\n"
            << shape->getEnd().x()          << "\r\n"
            << shape->getEnd().y()          << "\r\n";

    }
    //这里不用保存，在读取的时候，直接创建新的图形对象
    // for (int i = 0; i < paintWidget->shapeListWidget->count(); ++i)
    // {
    //     QListWidgetItem *item = paintWidget->shapeListWidget->item(i);
    //     out << item->text() << "\r\n";
    // }


    file.close();
}

//print用不到
void MainWindow::print()
{
    QPrinter printer;
    QPainter painter;
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);

        QPageLayout pageLayout = printer.pageLayout();
        QRectF pageRect = pageLayout.fullRectPoints();

        double xscale = pageRect.width() / double(this->paintWidget->width());
        double yscale = pageRect.height() / double(this->paintWidget->height());
        double scale = qMin(xscale, yscale);

        painter.translate(pageRect.x() + pageRect.width() / 2,
                          pageRect.y() + pageRect.height() / 2);
        painter.scale(scale, scale);
        painter.translate(-this->paintWidget->width() / 2, -this->paintWidget->height() / 2);

        //绘制代码，需要根据打印机的设置进行调整

        painter.end();
    }
}
