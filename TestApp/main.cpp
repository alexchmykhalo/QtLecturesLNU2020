#include "mainwindow.h"

#include <QtWidgets/QApplication>

#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;

    QPushButton *button = new QPushButton(&widget);
    button->setGeometry(30, 30, 100, 50);
    button->setText("PUSH ME!");

    QObject::connect(button, &QPushButton::clicked,
                     &widget, &QWidget::close);

    widget.show();

    return a.exec();
}
