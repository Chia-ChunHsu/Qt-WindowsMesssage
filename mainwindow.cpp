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

    QString sendMSG = ui->textEditSignal->toPlainText();
    QByteArray data = sendMSG.toUtf8();
    COPYDATASTRUCT copydata;
    copydata.dwData = CUSTOM_TYPE;  // 用户定义数据
    copydata.cbData = data.size();  //Data Size
    copydata.lpData = data.data();  //Data Pointer

    effectiveWinId();
    SendMessage(handle,WM_COPYDATA,(WPARAM)NULL,(LPARAM)&copydata);
}

void MainWindow::on_changeWButton_clicked()
{
    QString textName = ui->textEditWindows->toPlainText();
    setWindowTitle(textName);
}
