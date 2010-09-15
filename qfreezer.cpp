#include "qfreezer.h"

// Constructor
QFreezer::QFreezer(QWidget *parent) : QWidget(parent) {
    // Logo
    setWindowIcon(QIcon("ice.png"));

    // Create layout
    layout_ = new QHBoxLayout(this);

    // Create widgets
    label_ = new QLabel("Freeze for:", this);
    timeBox_ = new QSpinBox(this);
    startButton_ = new QPushButton(tr("Start"), this);

    // Setup QSpinBox
    timeBox_->setRange(0, 10000);
    timeBox_->setSingleStep(100);
    timeBox_->setSuffix(" ms");

    // Add widgets to layout
    layout_->addWidget(label_);
    layout_->addWidget(timeBox_);
    layout_->addWidget(startButton_);

    // Set layout to widget
    setLayout(layout_);

    // Join the signal
    QObject::connect(startButton_, SIGNAL(clicked()), this, SLOT(freeze()));

}

// Destructor
QFreezer::~QFreezer() {
    timeBox_->deleteLater();
    startButton_->deleteLater();
    layout_->deleteLater();
}

//
// Private slots
//

void QFreezer::freeze() {
    // Variables
    Threads threads;

    // Create N threads
    for (int i = 0; i < QThread::idealThreadCount(); i++) {
        FreezeThread *ft = new FreezeThread(timeBox_->value(), this);
        threads.push_back(ft);
    }

    // Time critical priority
    QThread::currentThread()->setPriority(QThread::TimeCriticalPriority);

    // Start the threads
    for (Threads::iterator iter = threads.begin(); iter != threads.end(); iter++) {
        (*iter)->start(QThread::TimeCriticalPriority);
    }

    // Wait for them to finish
    for (Threads::iterator iter = threads.begin(); iter != threads.end(); iter++) {
        (*iter)->wait();
    }

    // End time critical priority
    QThread::currentThread()->setPriority(QThread::NormalPriority);

    // Delete threads
    for (Threads::iterator iter = threads.begin(); iter != threads.end(); iter++) {
        // Delete & set to zero
        delete *iter;
        *iter = 0;
    }
}
