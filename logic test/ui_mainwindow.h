/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *IP;
    QLineEdit *_IP;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Port;
    QSpinBox *_Port;
    QPushButton *ButtonClient;
    QPushButton *ButtonServer;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *Nickname;
    QTextEdit *Chat;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *Message;
    QLabel *label_3;
    QPushButton *pushButton_Send;
    QPushButton *pushButton_Connect;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1395, 757);
        MainWindow->setStyleSheet(QLatin1String("#centralwidget {\n"
"    background-color: rgba(219, 38, 38,0.6);\n"
"}\n"
"QPushButton#pushButton{\n"
"   \n"
"border: 4px solid gray;\n"
"background-color: rgba(178,178,178,0.5);\n"
"border-radius:10px;\n"
"}\n"
"\n"
"\n"
"QPushButton#ButtonClient\n"
"{\n"
"border : 2px solid gray;\n"
"border-radius: 10px;\n"
"color: gray;\n"
"\n"
"}\n"
"QPushButton#ButtonServer\n"
"{\n"
"border : 2px solid gray;\n"
"border-radius: 10px;\n"
"color :gray;\n"
"\n"
"\n"
"}\n"
"\n"
"QWidget#widget\n"
"{\n"
"border : 4px solid gray;\n"
"border-radius: 13px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(980, 580, 381, 131));
        QFont font;
        font.setPointSize(25);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(900, 380, 416, 148));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        QFont font1;
        font1.setPointSize(24);
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox_2 = new QCheckBox(horizontalLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Sans Serif"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        checkBox_2->setFont(font2);

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(horizontalLayoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        checkBox_3->setFont(font3);

        verticalLayout->addWidget(checkBox_3);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font4;
        font4.setFamily(QStringLiteral("MS Sans Serif"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        checkBox->setFont(font4);

        verticalLayout->addWidget(checkBox);


        horizontalLayout_4->addLayout(verticalLayout);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 281, 141));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 213, 56));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        IP = new QLabel(layoutWidget);
        IP->setObjectName(QStringLiteral("IP"));
        QFont font5;
        font5.setPointSize(10);
        IP->setFont(font5);

        horizontalLayout_8->addWidget(IP);

        _IP = new QLineEdit(layoutWidget);
        _IP->setObjectName(QStringLiteral("_IP"));

        horizontalLayout_8->addWidget(_IP);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        Port = new QLabel(layoutWidget);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setFont(font5);

        horizontalLayout_9->addWidget(Port);

        _Port = new QSpinBox(layoutWidget);
        _Port->setObjectName(QStringLiteral("_Port"));
        _Port->setMaximum(5000);

        horizontalLayout_9->addWidget(_Port);


        verticalLayout_3->addLayout(horizontalLayout_9);

        ButtonClient = new QPushButton(centralwidget);
        ButtonClient->setObjectName(QStringLiteral("ButtonClient"));
        ButtonClient->setGeometry(QRect(320, 40, 93, 28));
        ButtonClient->setFont(font3);
        ButtonClient->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonServer = new QPushButton(centralwidget);
        ButtonServer->setObjectName(QStringLiteral("ButtonServer"));
        ButtonServer->setGeometry(QRect(320, 100, 93, 28));
        ButtonServer->setFont(font3);
        ButtonServer->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 180, 426, 531));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font5);

        horizontalLayout_5->addWidget(label_2);

        Nickname = new QLineEdit(layoutWidget1);
        Nickname->setObjectName(QStringLiteral("Nickname"));
        Nickname->setClearButtonEnabled(false);

        horizontalLayout_5->addWidget(Nickname);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        Chat = new QTextEdit(layoutWidget1);
        Chat->setObjectName(QStringLiteral("Chat"));
        Chat->setFrameShape(QFrame::NoFrame);

        verticalLayout_2->addWidget(Chat);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        Message = new QLineEdit(layoutWidget1);
        Message->setObjectName(QStringLiteral("Message"));

        horizontalLayout_7->addWidget(Message);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font5);

        horizontalLayout_7->addWidget(label_3);

        pushButton_Send = new QPushButton(layoutWidget1);
        pushButton_Send->setObjectName(QStringLiteral("pushButton_Send"));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        pushButton_Send->setFont(font6);

        horizontalLayout_7->addWidget(pushButton_Send);

        pushButton_Connect = new QPushButton(layoutWidget1);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setFont(font6);

        horizontalLayout_7->addWidget(pushButton_Connect);


        verticalLayout_2->addLayout(horizontalLayout_7);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(640, 20, 471, 290));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font7;
        font7.setPointSize(48);
        font7.setBold(true);
        font7.setWeight(75);
        label_5->setFont(font7);

        verticalLayout_4->addWidget(label_5);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font8;
        font8.setFamily(QStringLiteral("Andalus"));
        font8.setPointSize(72);
        label_4->setFont(font8);

        verticalLayout_4->addWidget(label_4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Let's GO..", 0));
        label->setText(QApplication::translate("MainWindow", "Choose Grid size ", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "7 x 7", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "6 x 6", 0));
        checkBox->setText(QApplication::translate("MainWindow", "5 x 5", 0));
        IP->setText(QApplication::translate("MainWindow", "IP Adresse ", 0));
        Port->setText(QApplication::translate("MainWindow", "Port", 0));
        ButtonClient->setText(QApplication::translate("MainWindow", "Client", 0));
        ButtonServer->setText(QApplication::translate("MainWindow", "Server", 0));
        label_2->setText(QApplication::translate("MainWindow", "Nickname", 0));
        label_3->setText(QApplication::translate("MainWindow", "Message :", 0));
        pushButton_Send->setText(QApplication::translate("MainWindow", "Send", 0));
        pushButton_Connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_5->setText(QApplication::translate("MainWindow", "                  4", 0));
        label_4->setText(QApplication::translate("MainWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
