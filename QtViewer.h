#ifndef QTVIEWER_H
#define QTVIEWER_H

#include "../AugReal/ARViewer.h"
#include "../AugReal/AREngine.h"
#include "../AugReal/ARFrame.h"
#include <memory>
#include <QObject>

class QtViewer : public ARViewer
{
private:
    QObject* transform_;
    std::deque<QMatrix4x4> mats;

protected:
//    virtual void paintGrid(std::shared_ptr<ARFrame>& frame){}
    virtual void paintAugment(std::shared_ptr<ARFrame>& frame);

public:
    QtViewer(AREngine* engine, QObject* transform);
    virtual ~QtViewer() = default;
};

#endif // QTVIEWER_H
