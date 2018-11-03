#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QAudioRecorder>
#include <QMediaRecorder>
#include <QComboBox>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
 Q_OBJECT

public:
 explicit MainWindow(QWidget *parent = 0);
 virtual ~MainWindow();

private slots:
 void handleButton();

private:
 QPushButton * m_button;
 QAudioRecorder * recorder;
 QComboBox * inputDevice;
};

#endif // MAINWINDOW_H
