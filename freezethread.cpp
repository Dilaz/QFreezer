#include "freezethread.h"


// Constructor
FreezeThread::FreezeThread(const int ms, QObject *parent)
    : QThread(parent), ms_(ms) {
}

// Overloaded run-method
void FreezeThread::run() {
    // Time-variable
    QTime time;
    // Start the timer
    time.start();

    // Busy loop
    while (time.elapsed() < ms_) {
        // Do nothing
    }
}
