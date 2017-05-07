#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG *msg =static_cast<MSG *>(message);

    switch(msg->message)
    {
        case WM_COPYDATA:

        COPYDATASTRUCT *cds = reinterpret_cast<COPYDATASTRUCT*>(msg->lParam);
        if (cds->dwData == CUSTOM_TYPE)
        {
            QString strMessage = QString::fromUtf8(reinterpret_cast<char*>(cds->lpData), cds->cbData);
            ui->label->setText(strMessage);
            *result = 1;
            return true;
        }
        break;
    }
    return QWidget::nativeEvent(eventType,message,result);
}

void MainWindow::on_sendButton_clicked()
{
    const QString str = ui->textEditGoal->toPlainText(); //"MainWindow";
    LPWSTR path = (LPWSTR)str.unicode();
    HWND handle =  ::FindWindowW(NULL,path);
    QString filename = ui->textEditSignal->toPlainText();
    QByteArray data = filename.toUtf8();
    COPYDATASTRUCT copydata;
    copydata.dwData = CUSTOM_TYPE;  // 用户定义数据
    copydata.lpData = data.data();  //数据大小
    copydata.cbData = data.size();  // 指向数据的指针
    SendMessage(handle,WM_COPYDATA,(WPARAM)0,(LPARAM)&copydata);
}

void MainWindow::on_changeWButton_clicked()
{
    QString textName = ui->textEditWindows->toPlainText();
    setWindowTitle(textName);
}
