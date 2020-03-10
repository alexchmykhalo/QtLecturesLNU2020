#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->makeConnectionPushButton, &QPushButton::clicked,
            this, &MainWindow::makeConnection);

    connect(ui->horizontalSlider, &QSlider::sliderMoved,
            this, &MainWindow::showSliderValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMessage()
{
    QMessageBox::information(this, "MyCustomMessage",
                             "Hello!");
}

void MainWindow::makeConnection()
{
    connect(ui->messagePushButton, &QPushButton::clicked,
            this, &MainWindow::showMessage);
}

void MainWindow::showSliderValue(int value)
{
    ui->label->setText(QString("Value: %1").arg(value));
}

