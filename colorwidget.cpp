#include "colorwidget.h"
#include <QDebug>

ColorWidget::ColorWidget(QWidget *parent): QWidget(parent)
{

}

HSVWidget::HSVWidget(QWidget *parent): ColorWidget(parent)
{
    vb = new QVBoxLayout(this);
    fl = new QFormLayout;
    hue_low_slider = new QSlider(Qt::Orientation::Horizontal);
    sat_low_slider = new QSlider(Qt::Orientation::Horizontal);
    val_low_slider = new QSlider(Qt::Orientation::Horizontal);
    hue_high_slider = new QSlider(Qt::Orientation::Horizontal);
    sat_high_slider = new QSlider(Qt::Orientation::Horizontal);
    val_high_slider = new QSlider(Qt::Orientation::Horizontal);
    hue_low_slider->setRange(0, 180);
    sat_low_slider->setRange(0, 255);
    val_low_slider->setRange(0, 255);
    hue_high_slider->setRange(0, 180);
    hue_high_slider->setValue(180);
    sat_high_slider->setRange(0, 255);
    sat_high_slider->setValue(255);
    val_high_slider->setRange(0, 255);
    val_high_slider->setValue(255);
    fl->addRow("Hue_lower", hue_low_slider);
    fl->addRow("Hue_upper", hue_high_slider);
    fl->addRow("Saturation_lower", sat_low_slider);
    fl->addRow("Saturation_upper", sat_high_slider);
    fl->addRow("Value_lower", val_low_slider);
    fl->addRow("Value_upper", val_high_slider);
    vb->addWidget(&imgLabel);
    vb->addLayout(fl);
    vb->setStretch(0, 1);
    vb->setStretch(1, 0);
    QList<QSlider*> lst{hue_low_slider, hue_high_slider, sat_low_slider, sat_high_slider, val_low_slider, val_high_slider};
    for(auto* slider : lst){
        slider->setTickInterval(1);
        connect(slider, &QSlider::valueChanged, this, [this, slider](int val){
            slider->setValue(val);
            setPixelMap(val);
        });
    }
}

void HSVWidget::setPixelMap(const cv::Mat &img)
{
    origin = img;
    cv::Mat tmp;
    cv::inRange(img, cv::Scalar(hue_low_slider->value(), sat_low_slider->value(), val_low_slider->value()),
                cv::Scalar(hue_high_slider->value(), sat_high_slider->value(), val_high_slider->value()),
                tmp);
    QPixmap map = QPixmap::fromImage(QImage((unsigned char*) tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8));
    imgLabel.setPixmap(map);
    imgLabel.pm = map;
    imgLabel.psize = map.size();
}

void HSVWidget::setPixelMap(int val)
{
    cv::Mat tmp;
    cv::inRange(origin, cv::Scalar(hue_low_slider->value(), sat_low_slider->value(), val_low_slider->value()),
                cv::Scalar(hue_high_slider->value(), sat_high_slider->value(), val_high_slider->value()),
                tmp);
    QPixmap map = QPixmap::fromImage(QImage((unsigned char*) tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8));
    imgLabel.setPixmap(map);
    imgLabel.pm = map;
    imgLabel.resizing();
}

HLSWidget::HLSWidget(QWidget *parent): ColorWidget(parent)
{
    vb = new QVBoxLayout(this);
    fl = new QFormLayout;
    hue_low_slider = new QSlider(Qt::Orientation::Horizontal);
    sat_low_slider = new QSlider(Qt::Orientation::Horizontal);
    lum_low_slider = new QSlider(Qt::Orientation::Horizontal);
    hue_high_slider = new QSlider(Qt::Orientation::Horizontal);
    sat_high_slider = new QSlider(Qt::Orientation::Horizontal);
    lum_high_slider = new QSlider(Qt::Orientation::Horizontal);
    hue_low_slider->setRange(0, 180);
    sat_low_slider->setRange(0, 255);
    lum_low_slider->setRange(0, 255);
    hue_high_slider->setRange(0, 180);
    hue_high_slider->setValue(180);
    sat_high_slider->setRange(0, 255);
    sat_high_slider->setValue(255);
    lum_high_slider->setRange(0, 255);
    lum_high_slider->setValue(255);
    fl->addRow("Hue_lower", hue_low_slider);
    fl->addRow("Hue_upper", hue_high_slider);
    fl->addRow("Saturation_lower", sat_low_slider);
    fl->addRow("Saturation_upper", sat_high_slider);
    fl->addRow("Luminance_lower", lum_low_slider);
    fl->addRow("Luminance_upper", lum_high_slider);
    vb->addWidget(&imgLabel);
    vb->addLayout(fl);
    vb->setStretch(0, 1);
    vb->setStretch(1, 0);
}

void HLSWidget::setPixelMap(const cv::Mat &img)
{

    origin = img;
    cv::Mat tmp;
    cv::inRange(img, cv::Scalar(hue_low_slider->value(), lum_low_slider->value(), sat_low_slider->value()),
                cv::Scalar(hue_high_slider->value(), lum_high_slider->value(), sat_high_slider->value()),
                tmp);

    QPixmap map = QPixmap::fromImage(QImage((unsigned char*) tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8));
    imgLabel.setPixmap(map);
    imgLabel.pm = map;
}

void HLSWidget::setPixelMap(int)
{
    cv::Mat tmp;
    cv::inRange(origin, cv::Scalar(hue_low_slider->value(), lum_low_slider->value(), sat_low_slider->value()),
                cv::Scalar(hue_high_slider->value(), lum_high_slider->value(), sat_high_slider->value()),
                tmp);

    QPixmap map = QPixmap::fromImage(QImage((unsigned char*) tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8));
    imgLabel.setPixmap(map);
    imgLabel.pm = map;
    imgLabel.resizing();
}

BGRWidget::BGRWidget(QWidget *parent): ColorWidget(parent)
{
    vb = new QVBoxLayout(this);
    fl = new QFormLayout;
    blue_low_slider = new QSlider(Qt::Orientation::Horizontal);
    green_low_slider = new QSlider(Qt::Orientation::Horizontal);
    red_low_slider = new QSlider(Qt::Orientation::Horizontal);
    blue_high_slider = new QSlider(Qt::Orientation::Horizontal);
    green_high_slider = new QSlider(Qt::Orientation::Horizontal);
    red_high_slider = new QSlider(Qt::Orientation::Horizontal);
    blue_low_slider->setRange(0, 255);
    green_low_slider->setRange(0, 255);
    red_low_slider->setRange(0, 255);
    blue_high_slider->setRange(0, 255);
    blue_high_slider->setValue(255);
    green_high_slider->setRange(0, 255);
    green_high_slider->setValue(255);
    red_high_slider->setRange(0, 255);
    red_high_slider->setValue(255);
    fl->addRow("Blue_lower", blue_low_slider);
    fl->addRow("Blue_upper", blue_high_slider);
    fl->addRow("Green_lower", green_low_slider);
    fl->addRow("Green_upper", green_high_slider);
    fl->addRow("Red_lower", red_low_slider);
    fl->addRow("Red_upper", red_high_slider);
    vb->addWidget(&imgLabel);
    vb->addLayout(fl);
    vb->setStretch(0, 1);
    vb->setStretch(1, 0);
}

void BGRWidget::setPixelMap(const cv::Mat &img)
{
    origin = img;
    cv::Mat tmp;
    cv::inRange(img, cv::Scalar(blue_low_slider->value(), green_low_slider->value(), red_low_slider->value()),
                cv::Scalar(blue_high_slider->value(), green_high_slider->value(), red_high_slider->value()),
                tmp);

    QPixmap map = QPixmap::fromImage(QImage((unsigned char*) tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8));
    imgLabel.setPixmap(map);
    imgLabel.pm = map;

}

void BGRWidget::setPixelMap(int)
{
    cv::Mat tmp;
    cv::inRange(origin, cv::Scalar(blue_low_slider->value(), green_low_slider->value(), red_low_slider->value()),
                cv::Scalar(blue_high_slider->value(), green_high_slider->value(), red_high_slider->value()),
                tmp);

    QPixmap map = QPixmap::fromImage(QImage((unsigned char*) tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_Grayscale8));
    imgLabel.setPixmap(map);
    imgLabel.pm = map;
    imgLabel.resizing();
}
