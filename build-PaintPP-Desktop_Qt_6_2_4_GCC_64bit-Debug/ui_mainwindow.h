/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Image_lbl;
    QFrame *verticalFrame_2;
    QGridLayout *gridLayout_2;
    QFrame *formFrame;
    QGridLayout *gridLayout;
    QLabel *Width_lbl;
    QLabel *Height_lbl;
    QPlainTextEdit *Height_num;
    QPlainTextEdit *Width_num;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Color_bttn;
    QPushButton *Input_bttn;
    QVBoxLayout *verticalLayout;
    QPushButton *New_Image;
    QPushButton *Load_Image;
    QPushButton *Save_image;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1021, 622);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/kanna.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 210);\n"
"border-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Image_lbl = new QLabel(centralwidget);
        Image_lbl->setObjectName(QString::fromUtf8("Image_lbl"));
        Image_lbl->setGeometry(QRect(0, 0, 810, 550));
        Image_lbl->setMaximumSize(QSize(810, 550));
        Image_lbl->setCursor(QCursor(Qt::CrossCursor));
        Image_lbl->setMouseTracking(true);
        Image_lbl->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(136, 138, 133);\n"
""));
        verticalFrame_2 = new QFrame(centralwidget);
        verticalFrame_2->setObjectName(QString::fromUtf8("verticalFrame_2"));
        verticalFrame_2->setGeometry(QRect(820, 0, 191, 311));
        verticalFrame_2->setAutoFillBackground(false);
        verticalFrame_2->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-color: rgb(46, 52, 54);"));
        gridLayout_2 = new QGridLayout(verticalFrame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formFrame = new QFrame(verticalFrame_2);
        formFrame->setObjectName(QString::fromUtf8("formFrame"));
        gridLayout = new QGridLayout(formFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Width_lbl = new QLabel(formFrame);
        Width_lbl->setObjectName(QString::fromUtf8("Width_lbl"));
        Width_lbl->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(Width_lbl, 0, 1, 1, 1);

        Height_lbl = new QLabel(formFrame);
        Height_lbl->setObjectName(QString::fromUtf8("Height_lbl"));
        Height_lbl->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(Height_lbl, 0, 2, 1, 1);

        Height_num = new QPlainTextEdit(formFrame);
        Height_num->setObjectName(QString::fromUtf8("Height_num"));
        Height_num->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(Height_num, 1, 2, 1, 1);

        Width_num = new QPlainTextEdit(formFrame);
        Width_num->setObjectName(QString::fromUtf8("Width_num"));
        Width_num->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(Width_num, 1, 1, 1, 1);


        gridLayout_2->addWidget(formFrame, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Color_bttn = new QPushButton(verticalFrame_2);
        Color_bttn->setObjectName(QString::fromUtf8("Color_bttn"));

        verticalLayout_2->addWidget(Color_bttn);

        Input_bttn = new QPushButton(verticalFrame_2);
        Input_bttn->setObjectName(QString::fromUtf8("Input_bttn"));

        verticalLayout_2->addWidget(Input_bttn);


        gridLayout_2->addLayout(verticalLayout_2, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        New_Image = new QPushButton(verticalFrame_2);
        New_Image->setObjectName(QString::fromUtf8("New_Image"));

        verticalLayout->addWidget(New_Image);

        Load_Image = new QPushButton(verticalFrame_2);
        Load_Image->setObjectName(QString::fromUtf8("Load_Image"));

        verticalLayout->addWidget(Load_Image);

        Save_image = new QPushButton(verticalFrame_2);
        Save_image->setObjectName(QString::fromUtf8("Save_image"));

        verticalLayout->addWidget(Save_image);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PAIN", nullptr));
        Image_lbl->setText(QString());
        Width_lbl->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        Height_lbl->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        Color_bttn->setText(QCoreApplication::translate("MainWindow", "Select Color", nullptr));
        Input_bttn->setText(QCoreApplication::translate("MainWindow", "Select Input", nullptr));
        New_Image->setText(QCoreApplication::translate("MainWindow", "New Image", nullptr));
        Load_Image->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        Save_image->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
