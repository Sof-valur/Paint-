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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Image_lbl;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *New_Image;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Width_lbl;
    QLabel *Height_lbl;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *Width_num;
    QPlainTextEdit *Height_num;
    QSpacerItem *verticalSpacer;
    QPushButton *Load_Image;
    QPushButton *Save_image;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1074, 750);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/kanna.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Image_lbl = new QLabel(centralwidget);
        Image_lbl->setObjectName(QString::fromUtf8("Image_lbl"));
        Image_lbl->setGeometry(QRect(180, 40, 801, 561));
        Image_lbl->setMouseTracking(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 131, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        New_Image = new QPushButton(verticalLayoutWidget);
        New_Image->setObjectName(QString::fromUtf8("New_Image"));

        verticalLayout->addWidget(New_Image);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Width_lbl = new QLabel(verticalLayoutWidget);
        Width_lbl->setObjectName(QString::fromUtf8("Width_lbl"));
        Width_lbl->setMaximumSize(QSize(50, 30));

        horizontalLayout_2->addWidget(Width_lbl);

        Height_lbl = new QLabel(verticalLayoutWidget);
        Height_lbl->setObjectName(QString::fromUtf8("Height_lbl"));
        Height_lbl->setMaximumSize(QSize(50, 30));

        horizontalLayout_2->addWidget(Height_lbl);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Width_num = new QPlainTextEdit(verticalLayoutWidget);
        Width_num->setObjectName(QString::fromUtf8("Width_num"));
        Width_num->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(Width_num);

        Height_num = new QPlainTextEdit(verticalLayoutWidget);
        Height_num->setObjectName(QString::fromUtf8("Height_num"));
        Height_num->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(Height_num);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Load_Image = new QPushButton(verticalLayoutWidget);
        Load_Image->setObjectName(QString::fromUtf8("Load_Image"));

        verticalLayout->addWidget(Load_Image);

        Save_image = new QPushButton(verticalLayoutWidget);
        Save_image->setObjectName(QString::fromUtf8("Save_image"));

        verticalLayout->addWidget(Save_image);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1074, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PAIN", nullptr));
        Image_lbl->setText(QString());
        New_Image->setText(QCoreApplication::translate("MainWindow", "New Image", nullptr));
        Width_lbl->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        Height_lbl->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        Load_Image->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        Save_image->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
