/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *spinBox;
    QDial *dial;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLCDNumber *lcdNumber_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(400, 322);
        verticalLayout = new QVBoxLayout(MyForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(MyForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spinBox = new QSpinBox(MyForm);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(120);

        horizontalLayout_2->addWidget(spinBox);

        dial = new QDial(MyForm);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMaximum(120);

        horizontalLayout_2->addWidget(dial);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 0);"));

        horizontalLayout_5->addWidget(label);

        lcdNumber = new QLCDNumber(MyForm);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 0);\n"
"color: rgb(255, 255, 255);"));
        lcdNumber->setDigitCount(8);
        lcdNumber->setMode(QLCDNumber::Bin);

        horizontalLayout_5->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        horizontalLayout_4->addWidget(label_2);

        lcdNumber_2 = new QLCDNumber(MyForm);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        lcdNumber_2->setDigitCount(8);
        lcdNumber_2->setMode(QLCDNumber::Oct);

        horizontalLayout_4->addWidget(lcdNumber_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(MyForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout_3->addWidget(label_3);

        lcdNumber_3 = new QLCDNumber(MyForm);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        lcdNumber_3->setDigitCount(8);
        lcdNumber_3->setMode(QLCDNumber::Hex);

        horizontalLayout_3->addWidget(lcdNumber_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MyForm);
        QObject::connect(pushButton, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Conversor", Q_NULLPTR));
        label_4->setText(QApplication::translate("MyForm", "Escriu un nombre natural:", Q_NULLPTR));
        label->setText(QApplication::translate("MyForm", "Binari", Q_NULLPTR));
        label_2->setText(QApplication::translate("MyForm", "Octal", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyForm", "Hexadecimal", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyForm", "Surt", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
