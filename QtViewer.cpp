#include "QtViewer.h"
#include <QMatrix4x4>
#include <opencv2/opencv.hpp>
#include <iostream>

void QtViewer::paintAugment(std::shared_ptr<ARFrame> &frame)
{
    Q_UNUSED(frame);
    if (engine->frameQueue.empty()) return;

    cv::Mat vm = cv::Mat::zeros(4, 4, CV_64F);
    cv::Mat rot;
    cv::Rodrigues(engine->frameQueue.front()->rvec, rot);

    std::cout<<"Rvec "<<engine->frameQueue.front()->rvec<<std::endl;
//    std::cout<<rot<<std::endl;
    std::cout<<"Tvec "<<engine->frameQueue.front()->tvec<<std::endl;

    for(unsigned int row=0; row<3; ++row)
    {
       for(unsigned int col=0; col<3; ++col)
       {
          vm.at<double>(row, col) = rot.at<double>(row, col);
       }
//       vm.at<double>(row, 3) = engine->frameQueue.front()->tvec.at<double>(row, 0);
    }
    vm.at<double>(3, 0) = 0.0f;
    vm.at<double>(3, 1) = 0.0f;
    vm.at<double>(3, 2) = 0.0f;
    vm.at<double>(3, 3) = 1.0f;

    cv::Mat cvToGl = cv::Mat::zeros(4, 4, CV_64F);
    cvToGl.at<double>(0, 0) = 1.0f;
    cvToGl.at<double>(1, 1) = -1.0f; // Invert the y axis
    cvToGl.at<double>(2, 2) = -1.0f; // invert the z axis
    cvToGl.at<double>(3, 3) = 1.0f;
    vm = cvToGl * vm;

    QMatrix4x4 mat(vm.at<double>(0, 0),
                   vm.at<double>(0, 1),
                   vm.at<double>(0, 2),
                   vm.at<double>(0, 3),

                   vm.at<double>(1, 0),
                   vm.at<double>(1, 1),
                   vm.at<double>(1, 2),
                   vm.at<double>(1, 3),

                   vm.at<double>(2, 0),
                   vm.at<double>(2, 1),
                   vm.at<double>(2, 2),
                   vm.at<double>(2, 3),

                   vm.at<double>(3, 0),
                   vm.at<double>(3, 1),
                   vm.at<double>(3, 2),
                   vm.at<double>(3, 3));

//    mat = mat.transposed();

//    mats.push_front(mat);
//    if (mats.size() > 10)
//        mats.pop_back();
//    for (int i = 1; i < mats.size(); ++i)
//        mat += mats[i];
//    mat /= mats.size();

    qDebug()<<mat;
    transform_->setProperty("matrix", QVariant(mat));
//    cv::imshow("OpenCV", engine->frameQueue.front()->frame);

//    cv::Mat img = engine->frameQueue.front()->frame.clone();
//    std::vector<cv::Point3f> cubeOrig{cv::Point3f(0, 0, 0),
//                                      cv::Point3f(10, 0, 0),
//                                      cv::Point3f(10, 10, 0),
//                                      cv::Point3f(0, 10, 0),
//                                      cv::Point3f(0, 0, 10),
//                                      cv::Point3f(10, 0, 10),
//                                      cv::Point3f(10, 10, 10),
//                                      cv::Point3f(0, 10, 10)};
//    std::vector<cv::Point2f> cube;
//    cv::projectPoints(cubeOrig, engine->frameQueue.front()->rvec, engine->frameQueue.front()->tvec, engine->cameraMatrix, engine->distortionMatrix, cube);
//    for (int i = 0; i < 7; ++i)
//    {
//        cv::line(img, cube[i], cube[i+1], cv::Scalar(0, 255, 0));
//    }
//    cv::imshow("cube", img);
}

QtViewer::QtViewer(AREngine *engine, QObject *transform) : ARViewer(engine)
{
    this->transform_ = transform;
//    paintGridFlag = true;
}
