/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *bSet7;
    QPushButton *bSet5;
    QPushButton *bSet6;
    QPushButton *bSet3;
    QPushButton *bSet4;
    QPushButton *bSet1;
    QPushButton *bSet2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(800, 600);
        Dialog->setStyleSheet(QLatin1String("QLCDNumber\n"
"{\n"
"border : 3px solid gray;\n"
"}\n"
"QPushButton\n"
"{\n"
"\n"
"background-color:gray;\n"
"border-radius:4px;\n"
"\n"
"\n"
"}"));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 550, 541, 41));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(1);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bSet7 = new QPushButton(gridLayoutWidget);
        bSet7->setObjectName(QStringLiteral("bSet7"));
        bSet7->setCursor(QCursor(Qt::PointingHandCursor));
        bSet7->setStyleSheet(QStringLiteral("background:gray;"));

        gridLayout->addWidget(bSet7, 0, 6, 1, 1);

        bSet5 = new QPushButton(gridLayoutWidget);
        bSet5->setObjectName(QStringLiteral("bSet5"));
        bSet5->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bSet5, 0, 4, 1, 1);

        bSet6 = new QPushButton(gridLayoutWidget);
        bSet6->setObjectName(QStringLiteral("bSet6"));
        bSet6->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bSet6, 0, 5, 1, 1);

        bSet3 = new QPushButton(gridLayoutWidget);
        bSet3->setObjectName(QStringLiteral("bSet3"));
        bSet3->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bSet3, 0, 2, 1, 1);

        bSet4 = new QPushButton(gridLayoutWidget);
        bSet4->setObjectName(QStringLiteral("bSet4"));
        bSet4->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bSet4, 0, 3, 1, 1);

        bSet1 = new QPushButton(gridLayoutWidget);
        bSet1->setObjectName(QStringLiteral("bSet1"));
        bSet1->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bSet1, 0, 0, 1, 1);

        bSet2 = new QPushButton(gridLayoutWidget);
        bSet2->setObjectName(QStringLiteral("bSet2"));
        bSet2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bSet2, 0, 1, 1, 1);

        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(654, 65, 131, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("MS Sans Serif"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QFont font1;
        font1.setPointSize(14);
        lcdNumber->setFont(font1);

        verticalLayout->addWidget(lcdNumber);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        bSet7->setText(QString());
        bSet5->setText(QString());
        bSet6->setText(QString());
        bSet3->setText(QString());
        bSet4->setText(QString());
        bSet1->setText(QString());
        bSet2->setText(QString());
        label->setText(QApplication::translate("Dialog", "Round", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
