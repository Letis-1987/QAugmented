#ifndef FRAMEINTECEPTOR_H
#define FRAMEINTECEPTOR_H

#include <QObject>

class FrameInteceptor : public QObject
{
    Q_OBJECT
public:
    explicit FrameInteceptor(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FRAMEINTECEPTOR_H