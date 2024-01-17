QT       += core gui
QT       += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawTools_Yyzh
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    circle.cpp \
    line.cpp \
    paintwidget.cpp \
    rect.cpp \
    shape.cpp \
    star.cpp \
    triangle.cpp


HEADERS  += mainwindow.h \
    circle.h \
    line.h \
    paintwidget.h \
    rect.h \
    shape.h \
    star.h \
    triangle.h


