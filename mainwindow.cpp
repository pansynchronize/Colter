#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorwidget.h"
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About"), tr("Author: X Pan"));
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionHSV_triggered()
{
    HSVWidget* hsvwidget = new HSVWidget();
    QLayoutItem* child = ui->verticalLayout->takeAt(0);
    if(child->widget())
        delete child->widget();
    delete child;
    ui->verticalLayout->addWidget(hsvwidget);
    cv::Mat img = cv::imread("image.png");
    cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
    hsvwidget->setPixelMap(img);
}

void MainWindow::on_actionHSL_triggered()
{
    HLSWidget* hlswidget = new HLSWidget();
    QLayoutItem* child = ui->verticalLayout->takeAt(0);
    if(child->widget())
        delete child->widget();
    delete child;
    ui->verticalLayout->addWidget(hlswidget);
    cv::Mat img = cv::imread("image.png");
    cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
    hlswidget->setPixelMap(img);
}

void MainWindow::on_actionBGR_triggered()
{
    BGRWidget* bgrwidget = new BGRWidget();
    QLayoutItem* child = ui->verticalLayout->takeAt(0);
    if(child->widget())
        delete child->widget();
    delete child;
    ui->verticalLayout->addWidget(bgrwidget);
    cv::Mat img = cv::imread("image.png");
    cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
    bgrwidget->setPixelMap(img);
}
