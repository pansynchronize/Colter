#ifndef IMGLABEL_H
#define IMGLABEL_H
#include <QLabel>
#include <QResizeEvent>
#include <opencv2/opencv.hpp>

class ImgLabel: public QLabel
{
public:
    ImgLabel(QWidget* parent=nullptr);
    void resizeEvent(QResizeEvent *) override;
    void resizing();
    void setPixelmap(const cv::Mat& img);

    cv::Mat ori_img;
    QPixmap pm;
    QSize psize;
    QSize lsize;
};

#endif // IMGLABEL_H
