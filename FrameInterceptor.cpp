#include "FrameInterceptor.h"
#include <opencv2/opencv.hpp>
#include <exception>
#include "QtViewer.h"
#include <iostream>

cv::Mat FrameInterceptor::qFrameToMat(QVideoFrame frame)
{
    cv::Mat m;
    switch (frame.pixelFormat()) {
    case QVideoFrame::PixelFormat::Format_YUV420P:
        frame.map(QAbstractVideoBuffer::MapMode::ReadOnly);
        m = cv::Mat(frame.height() + frame.height() / 2, frame.width(), CV_8UC1, frame.bits());
        cv::cvtColor(m, m, CV_YUV2BGRA_I420);
        frame.unmap();
        cv::flip(m, m, 1);
    break;
    case QVideoFrame::PixelFormat::Format_YV12:
        frame.map(QAbstractVideoBuffer::MapMode::ReadOnly);
        m = cv::Mat(frame.height() + frame.height() / 2, frame.width(), CV_8UC1, frame.bits());
        cv::cvtColor(m, m, CV_YUV2RGBA_NV12);
        frame.unmap();
        break;
    default:
        throw std::runtime_error("Bad pixel format");
        break;
    }
    return m;
}

FrameInterceptor::FrameInterceptor(QObject* transform, QObject *parent) : QObject(parent)
{
    delete engine.viewer;
    engine.viewer = new QtViewer(&engine, transform);
// Hard code !!!
    cv::FileStorage fs;
    fs.open("./../AugReal/Samples/CameraMatrix.xml", cv::FileStorage::READ);
    fs["CamMat"]>>engine.cameraMatrix;
    fs.release();
    fs.open("./../AugReal/Samples/DistortionMatrix.xml", cv::FileStorage::READ);
    fs["DistMat"]>>engine.distortionMatrix;
    fs.release();
}

void FrameInterceptor::frameProcessor(QVideoFrame frame)
{
    std::cout<<"Start slot"<<std::endl;
//    disconnect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(frameProcessor(QVideoFrame)));
//    cv::imshow("First frame", qFrameToMat(frame));
    if (capture)
    {
        engine.setOrigin(qFrameToMat(frame));
        capture = false;
//        cv::imshow("Origin", qFrameToMat(frame));
//        connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), SLOT(frameProcessor(QVideoFrame)));
        std::cout<<"End slot"<<std::endl;
        return;
    }
    engine.setNextFrame(qFrameToMat(frame));
//    cv::imshow("First frame", engine.frameQueue.front()->frame);
//    cv::waitKey(33);
    
//    if (!engine.sampleQueue.empty())
//    {
//        cv::imshow("Sample frame", engine.sampleQueue.front()->frame);
//    }

//    connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), SLOT(frameProcessor(QVideoFrame)));
    std::cout<<"End slot"<<std::endl;
}

void FrameInterceptor::captured()
{
    capture = true;
}
