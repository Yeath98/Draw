#include <QApplication>
#include <QScreen>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    // 获取屏幕的分辨率
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    w.setWindowTitle(QObject::tr("DrawTools_Yyzh"));
    w.resize(screenGeometry.width(), screenGeometry.height());

    w.show();
    return app.exec();
}
