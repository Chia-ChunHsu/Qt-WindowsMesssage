#include "mainwindow.h"
#include "ui_mainwindow.h"

 const ULONG_PTR CUSTOM_TYPE = 10000;

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
    //GetMessageW();
    //qDebug()<<"getMessage";
    MSG *msg =static_cast<MSG *>(message);

    switch(msg->message)// == WM_COPYDATA)
    {
        case WM_COPYDATA:
            //qDebug()<<"getMessage";
            //ui->label->setText("Get Message");

        COPYDATASTRUCT *cds = reinterpret_cast<COPYDATASTRUCT*>(msg->lParam);
        if (cds->dwData == CUSTOM_TYPE)
        {
            QString strMessage = QString::fromUtf8(reinterpret_cast<char*>(cds->lpData), cds->cbData);
            //QMessageBox::information(this, QStringLiteral("提示"), strMessage);
            ui->label->setText(strMessage);
            *result = 1;
            return true;
        }
            //return true;
        break;
//    default:
//        return QWidget::nativeEvent(eventType,message,result);
//        break;
    }
    return QWidget::nativeEvent(eventType,message,result);

}

void MainWindow::on_sendButton_clicked()
{
//    const QString c_strTitle = "MainWindow";

    const QString str = ui->textEditGoal->toPlainText(); //"MainWindow";
    //setWindowTitle(str);
    LPWSTR path = (LPWSTR)str.unicode();
    HWND handle =  ::FindWindowW(NULL,path);
    //
    QString filename = ui->textEditSignal->toPlainText();
    QByteArray data = filename.toUtf8();
    COPYDATASTRUCT copydata;
    copydata.dwData = CUSTOM_TYPE;  // 用户定义数据
    copydata.lpData = data.data();  //数据大小
    copydata.cbData = data.size();  // 指向数据的指针
    //
    SendMessage(handle,WM_COPYDATA,(WPARAM)0,(LPARAM)&copydata);

    //SendMessage()

    //HWND hwnd = NULL;
    //LPWSTR path = (LPWSTR)str.utf16();  //path = L"SendMessage"
    //hwnd = ::FindWindowW(NULL, path);

//    if (::IsWindow(hwnd))
//    {
//        QString filename = QStringLiteral("进程通信-Windows消息");
//        QByteArray data = filename.toUtf8();

//        COPYDATASTRUCT copydata;
//        copydata.dwData = CUSTOM_TYPE;  // 用户定义数据
//        copydata.lpData = data.data();  //数据大小
//        copydata.cbData = data.size();  // 指向数据的指针

//        HWND sender = (HWND)effectiveWinId();

//        ::SendMessage(hwnd, WM_COPYDATA, reinterpret_cast<WPARAM>(sender), reinterpret_cast<LPARAM>(&copydata));
//    }
}

void MainWindow::on_changeWButton_clicked()
{
    QString textName = ui->textEditWindows->toPlainText();
    setWindowTitle(textName);
}
