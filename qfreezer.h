#ifndef QFREEZER_H
#define QFREEZER_H

#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTime>
#include <QThread>
#include <QMessageBox>
#include <QVector>
#include <QLabel>

#include "FreezeThread.h"


class QFreezer : public QWidget {
    Q_OBJECT
public:
    QFreezer(QWidget *parent = 0);
    ~QFreezer();

private:
    QHBoxLayout *layout_;
    QLabel *label_;
    QSpinBox *timeBox_;
    QPushButton *startButton_;
    typedef QVector<FreezeThread *> Threads;

    void busyLoop(const int ms);

private slots:
    void freeze();
};

#endif // QFREEZER_H
