#include "imglabel.h"
#include <QDebug>

ImgLabel::ImgLabel(QWidget *parent): QLabel(parent)
{

}

void ImgLabel::resizeEvent(QResizeEvent *e)
{
    if(this->pixmap()){
        lsize = e->size();
        if(lsize.width()/lsize.height() >= psize.width()/psize.height()){
            this->setPixmap(pm.scaledToHeight(lsize.height()));
        }else {
            this->setPixmap(pm.scaledToWidth(lsize.width()));
//            qDebug() << "Fit for width" << endl;
        }
    }

}

void ImgLabel::resizing()
{
    if(this->pixmap()){
        if(lsize.width()/lsize.height() >= psize.width()/psize.height()){
            this->setPixmap(pm.scaledToHeight(lsize.height()));
        }else {
            this->setPixmap(pm.scaledToWidth(lsize.width()));
//            qDebug() << "Fit for width" << endl;
        }
    }
}

void ImgLabel::setPixelmap(const cv::Mat& img)
{
    ori_img = img;
    cv::Mat tmp;
    cv::inRange(img, cv::Scalar(11, 145, 32), cv::Scalar(180, 255, 255), tmp);
    QPixmap map = QPixmap::fromImage(QImage((unsigned char*) tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8));
    this->setPixmap(map);
    pm = map;
    psize = map.size();
}

