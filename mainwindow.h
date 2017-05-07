#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>
//#include <QDebug>
//#include <stdlib.h>
//#pragma comment(lib, "user32.lib")
//#include <qt_windows.h>
//#include <WinUser.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void on_sendButton_clicked();

    void on_changeWButton_clicked();



private:
    Ui::MainWindow *ui;

    const ULONG_PTR CUSTOM_TYPE = 10000;
};

#endif // MAINWINDOW_H
