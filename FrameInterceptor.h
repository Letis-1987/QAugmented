#ifndef FRAMEINTRECEPTOR_H
#define FRAMEINTRECEPTOR_H

#include <QObject>
#include <QtMultimedia>
#include "../AugReal/AREngine.h"
#include <opencv2/opencv.hpp>

class FrameInterceptor : public QObject
{
    Q_OBJECT
private:

    cv::Mat qFrameToMat(QVideoFrame frame);

    bool capture = false;

public:
    explicit FrameInterceptor(QObject *transform, QObject *parent = nullptr);
    AREngine engine;
    QVideoProbe *probe;

signals:

public slots:
    void frameProcessor(QVideoFrame frame);
    void captured();
};

#endif // FRAMEINTRECEPTOR_H
