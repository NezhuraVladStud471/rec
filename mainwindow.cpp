#include "mainwindow.h"
#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QUrl>

#define path "D:/Recording/record"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    recorder = new QAudioRecorder(this);
    m_button = new QPushButton("Rec", this);
    m_button->setGeometry(QRect(QPoint(100, 200), QSize(200, 50)));
    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));
    inputDevice = new QComboBox(this);
    inputDevice->setGeometry(QRect(QPoint(100, 90), QSize(200, 30)));
    inputDevice->addItems(recorder->audioInputs());
    this->resize(450, 400);
}

void MainWindow::handleButton()
{
    if (recorder->state() == QMediaRecorder::StoppedState){

        recorder->setAudioInput(recorder->defaultAudioInput());
        if (inputDevice->currentIndex() != -1)
            recorder->setAudioInput((inputDevice->itemData(inputDevice->currentIndex())).toString());

        QAudioEncoderSettings format;
        format.setSampleRate(11025);
        format.setChannelCount(1);
        format.setBitRate(64000);
        format.setCodec("audio/pcm");
        format.setQuality(QMultimedia::HighQuality);

        recorder->setEncodingSettings(format, QVideoEncoderSettings(), "audio/x-wav");
        recorder->setOutputLocation(QUrl::fromLocalFile(path));
        recorder->record();
        m_button->setText("Stop");
    }
    else {
        recorder->stop();
        m_button->setText("Rec");
    }
}

MainWindow::~MainWindow()
{

}
