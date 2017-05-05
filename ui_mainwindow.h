/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *ToLabel;
    QPushButton *sendButton;
    QPushButton *changeWButton;
    QTextEdit *textEditWindows;
    QTextEdit *textEditSignal;
    QTextEdit *textEditGoal;
    QLabel *getMessageLabel;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(569, 257);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ToLabel = new QLabel(centralWidget);
        ToLabel->setObjectName(QStringLiteral("ToLabel"));

        gridLayout->addWidget(ToLabel, 4, 0, 1, 1);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(sendButton, 3, 3, 1, 1);

        changeWButton = new QPushButton(centralWidget);
        changeWButton->setObjectName(QStringLiteral("changeWButton"));
        sizePolicy.setHeightForWidth(changeWButton->sizePolicy().hasHeightForWidth());
        changeWButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(changeWButton, 0, 3, 1, 1);

        textEditWindows = new QTextEdit(centralWidget);
        textEditWindows->setObjectName(QStringLiteral("textEditWindows"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEditWindows->sizePolicy().hasHeightForWidth());
        textEditWindows->setSizePolicy(sizePolicy1);
        textEditWindows->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(textEditWindows, 0, 0, 1, 3);

        textEditSignal = new QTextEdit(centralWidget);
        textEditSignal->setObjectName(QStringLiteral("textEditSignal"));
        textEditSignal->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(textEditSignal, 3, 0, 1, 3);

        textEditGoal = new QTextEdit(centralWidget);
        textEditGoal->setObjectName(QStringLiteral("textEditGoal"));
        textEditGoal->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(textEditGoal, 5, 0, 1, 2);

        getMessageLabel = new QLabel(centralWidget);
        getMessageLabel->setObjectName(QStringLiteral("getMessageLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(getMessageLabel->sizePolicy().hasHeightForWidth());
        getMessageLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(getMessageLabel, 4, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 5, 2, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 569, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ToLabel->setText(QApplication::translate("MainWindow", "To Which Window", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        changeWButton->setText(QApplication::translate("MainWindow", "Change This Window's Name", Q_NULLPTR));
        getMessageLabel->setText(QApplication::translate("MainWindow", "Get Message", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
