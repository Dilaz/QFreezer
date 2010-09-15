#ifndef FREEZETHREAD_H
#define FREEZETHREAD_H

#include <QThread>
#include <QTime>

class FreezeThread : public QThread {
public:
    FreezeThread(const int ms, QObject *parent);
    void run();

private:
    int ms_;
};

#endif // FREEZETHREAD_H
