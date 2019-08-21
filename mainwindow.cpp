#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorwidget.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>

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
    if(!file.isEmpty()){
        HSVWidget* hsvwidget = new HSVWidget();
        QLayoutItem* child = ui->verticalLayout->takeAt(0);
        if(child->widget())
            delete child->widget();
        delete child;
        ui->verticalLayout->addWidget(hsvwidget);
        cv::Mat img = cv::imread(file.toStdString());
        cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
        hsvwidget->setPixelMap(img);
    }else{
        QMessageBox::warning(this, tr("Warning"), tr("Open a file first!"));
    }
}

void MainWindow::on_actionHSL_triggered()
{
    if(!file.isEmpty()){
        HLSWidget* hlswidget = new HLSWidget();
        QLayoutItem* child = ui->verticalLayout->takeAt(0);
        if(child->widget())
            delete child->widget();
        delete child;
        ui->verticalLayout->addWidget(hlswidget);
        cv::Mat img = cv::imread(file.toStdString());
        cv::cvtColor(img, img, cv::COLOR_BGR2HLS);
        hlswidget->setPixelMap(img);
    }else{
        QMessageBox::warning(this, tr("Warning"), tr("Open a file first!"));
    }
}

void MainWindow::on_actionBGR_triggered()
{
    if(!file.isEmpty()){
        BGRWidget* bgrwidget = new BGRWidget();
        QLayoutItem* child = ui->verticalLayout->takeAt(0);
        if(child->widget())
            delete child->widget();
        delete child;
        ui->verticalLayout->addWidget(bgrwidget);
        cv::Mat img = cv::imread(file.toStdString());
    //    cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
        bgrwidget->setPixelMap(img);
    }else{
        QMessageBox::warning(this, tr("Warning"), tr("Open a file first!"));
    }
}

void MainWindow::on_actionOpen_triggered()
{
    file = QFileDialog::getOpenFileName(this, tr("Images"), tr("Open image"), tr("Image (*.jpg *.png *.jpeg)"));
    if(!file.isEmpty()){
        on_actionBGR_triggered();
    }
}
