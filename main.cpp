#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtMultimedia>
#include "FrameInterceptor.h"
#include <string>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    QObject* rootItem = engine.rootObjects().front();
    QObject* camera = rootItem->findChild<QObject*>("videoCamera");

    QVideoProbe probe;
    probe.setSource(qvariant_cast<QCamera*>(camera->property("mediaObject")));

    QObject* transform = rootItem->findChild<QObject*>("objectTransform");
    FrameInterceptor inter(transform);
    QObject* screen = rootItem->findChild<QObject*>("screen");

    inter.probe = &probe;
    QObject::connect(screen, SIGNAL(capture()), &inter, SLOT(captured()));
    QObject::connect(&probe, SIGNAL(videoFrameProbed(QVideoFrame)), &inter, SLOT(frameProcessor(QVideoFrame)));

    auto n = app.exec();

//    for (auto i = 0; i < inter.engine.frameQueue.size(); ++i)
//    {
//        cv::imshow(std::to_string(i), inter.engine.frameQueue[i]->frame);
//    }
//    cv::waitKey();

    return n;
}
