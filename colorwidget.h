#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QSlider>
#include "imglabel.h"

class ColorWidget: public QWidget
{
public:
    ColorWidget(QWidget* parent=nullptr);
    virtual void setPixelMap(const cv::Mat& img) = 0;
    virtual void setPixelMap(int val) = 0;
    cv::Mat origin;
};

class HSVWidget: public ColorWidget{
public:
    HSVWidget(QWidget* parent=nullptr);
    void setPixelMap(const cv::Mat &img) override;
    void setPixelMap(int val) override;
private:
    using SliderPtr = QSlider*;
    QFormLayout* fl;
    QVBoxLayout* vb;
    SliderPtr hue_low_slider, sat_low_slider, val_low_slider;
    SliderPtr hue_high_slider, sat_high_slider, val_high_slider;
public:
    ImgLabel imgLabel;

};

class HLSWidget: public ColorWidget{
public:
    HLSWidget(QWidget* parent=nullptr);
    void setPixelMap(const cv::Mat &img) override;
    void setPixelMap(int val) override;
private:
    using SliderPtr = QSlider*;
    QFormLayout* fl;
    QVBoxLayout* vb;
    SliderPtr hue_low_slider, sat_low_slider, lum_low_slider;
    SliderPtr hue_high_slider, sat_high_slider, lum_high_slider;
public:
    ImgLabel imgLabel;

};

class BGRWidget: public ColorWidget{
public:
    BGRWidget(QWidget* parent=nullptr);
    void setPixelMap(const cv::Mat &img) override;
    void setPixelMap(int val) override;
private:
    using SliderPtr = QSlider*;
    QFormLayout* fl;
    QVBoxLayout* vb;
    SliderPtr blue_low_slider, green_low_slider, red_low_slider;
    SliderPtr blue_high_slider, green_high_slider, red_high_slider;
public:
    ImgLabel imgLabel;

};

#endif // COLORWIDGET_H
