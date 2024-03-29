/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *grbox_Comport_Control;
    QLabel *lbl_Port_Name;
    QLabel *lbl_Baudrate;
    QLabel *lbl_Data_Bits;
    QLabel *lbl_Stop_Bits;
    QLabel *lbl_Parity_Bits;
    QComboBox *combox_Port_Name;
    QComboBox *combox_Baudrate;
    QComboBox *comBox_Data_Bits;
    QComboBox *combox_Stop_Bits;
    QComboBox *combox_Parity_bits;
    QGroupBox *grbox_Display_Data;
    QPushButton *btnClearData_Display;
    QListWidget *listWidget_data_display;
    QGroupBox *grbox_Comport_Status;
    QPushButton *btnconnect;
    QPushButton *btn_Close;
    QLabel *lbl_Status_Comport;
    QGroupBox *groupBox_4;
    QPushButton *btnClear_Send_Data;
    QPushButton *btnSend_Data;
    QTextEdit *txtEdit_Send_Data;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(710, 619);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        grbox_Comport_Control = new QGroupBox(centralwidget);
        grbox_Comport_Control->setObjectName("grbox_Comport_Control");
        grbox_Comport_Control->setGeometry(QRect(40, 30, 261, 271));
        lbl_Port_Name = new QLabel(grbox_Comport_Control);
        lbl_Port_Name->setObjectName("lbl_Port_Name");
        lbl_Port_Name->setGeometry(QRect(20, 30, 91, 20));
        lbl_Baudrate = new QLabel(grbox_Comport_Control);
        lbl_Baudrate->setObjectName("lbl_Baudrate");
        lbl_Baudrate->setGeometry(QRect(20, 70, 91, 20));
        lbl_Data_Bits = new QLabel(grbox_Comport_Control);
        lbl_Data_Bits->setObjectName("lbl_Data_Bits");
        lbl_Data_Bits->setGeometry(QRect(20, 110, 91, 20));
        lbl_Stop_Bits = new QLabel(grbox_Comport_Control);
        lbl_Stop_Bits->setObjectName("lbl_Stop_Bits");
        lbl_Stop_Bits->setGeometry(QRect(20, 150, 91, 20));
        lbl_Parity_Bits = new QLabel(grbox_Comport_Control);
        lbl_Parity_Bits->setObjectName("lbl_Parity_Bits");
        lbl_Parity_Bits->setGeometry(QRect(20, 190, 91, 20));
        combox_Port_Name = new QComboBox(grbox_Comport_Control);
        combox_Port_Name->setObjectName("combox_Port_Name");
        combox_Port_Name->setGeometry(QRect(120, 30, 101, 25));
        combox_Baudrate = new QComboBox(grbox_Comport_Control);
        combox_Baudrate->setObjectName("combox_Baudrate");
        combox_Baudrate->setGeometry(QRect(120, 70, 101, 25));
        comBox_Data_Bits = new QComboBox(grbox_Comport_Control);
        comBox_Data_Bits->setObjectName("comBox_Data_Bits");
        comBox_Data_Bits->setGeometry(QRect(120, 110, 101, 25));
        combox_Stop_Bits = new QComboBox(grbox_Comport_Control);
        combox_Stop_Bits->setObjectName("combox_Stop_Bits");
        combox_Stop_Bits->setGeometry(QRect(120, 150, 101, 25));
        combox_Parity_bits = new QComboBox(grbox_Comport_Control);
        combox_Parity_bits->setObjectName("combox_Parity_bits");
        combox_Parity_bits->setGeometry(QRect(120, 190, 101, 25));
        grbox_Display_Data = new QGroupBox(centralwidget);
        grbox_Display_Data->setObjectName("grbox_Display_Data");
        grbox_Display_Data->setGeometry(QRect(320, 20, 351, 551));
        btnClearData_Display = new QPushButton(grbox_Display_Data);
        btnClearData_Display->setObjectName("btnClearData_Display");
        btnClearData_Display->setGeometry(QRect(130, 500, 93, 29));
        listWidget_data_display = new QListWidget(grbox_Display_Data);
        listWidget_data_display->setObjectName("listWidget_data_display");
        listWidget_data_display->setGeometry(QRect(10, 40, 341, 451));
        grbox_Comport_Status = new QGroupBox(centralwidget);
        grbox_Comport_Status->setObjectName("grbox_Comport_Status");
        grbox_Comport_Status->setGeometry(QRect(40, 310, 261, 121));
        btnconnect = new QPushButton(grbox_Comport_Status);
        btnconnect->setObjectName("btnconnect");
        btnconnect->setGeometry(QRect(20, 40, 93, 29));
        btn_Close = new QPushButton(grbox_Comport_Status);
        btn_Close->setObjectName("btn_Close");
        btn_Close->setGeometry(QRect(20, 80, 93, 29));
        lbl_Status_Comport = new QLabel(grbox_Comport_Status);
        lbl_Status_Comport->setObjectName("lbl_Status_Comport");
        lbl_Status_Comport->setGeometry(QRect(150, 30, 91, 71));
        QFont font;
        font.setPointSize(18);
        lbl_Status_Comport->setFont(font);
        lbl_Status_Comport->setTextFormat(Qt::MarkdownText);
        lbl_Status_Comport->setAlignment(Qt::AlignCenter);
        lbl_Status_Comport->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(40, 440, 271, 131));
        btnClear_Send_Data = new QPushButton(groupBox_4);
        btnClear_Send_Data->setObjectName("btnClear_Send_Data");
        btnClear_Send_Data->setGeometry(QRect(140, 80, 93, 29));
        btnSend_Data = new QPushButton(groupBox_4);
        btnSend_Data->setObjectName("btnSend_Data");
        btnSend_Data->setGeometry(QRect(20, 80, 93, 29));
        txtEdit_Send_Data = new QTextEdit(groupBox_4);
        txtEdit_Send_Data->setObjectName("txtEdit_Send_Data");
        txtEdit_Send_Data->setGeometry(QRect(20, 30, 241, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 710, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        grbox_Comport_Control->setTitle(QCoreApplication::translate("MainWindow", "Comport Control", nullptr));
        lbl_Port_Name->setText(QCoreApplication::translate("MainWindow", "Port Name", nullptr));
        lbl_Baudrate->setText(QCoreApplication::translate("MainWindow", "Baudrate", nullptr));
        lbl_Data_Bits->setText(QCoreApplication::translate("MainWindow", "Data Bits", nullptr));
        lbl_Stop_Bits->setText(QCoreApplication::translate("MainWindow", "Stop bits", nullptr));
        lbl_Parity_Bits->setText(QCoreApplication::translate("MainWindow", "Parity Bits", nullptr));
        grbox_Display_Data->setTitle(QCoreApplication::translate("MainWindow", "Display \304\220ata", nullptr));
        btnClearData_Display->setText(QCoreApplication::translate("MainWindow", "Clear data", nullptr));
        grbox_Comport_Status->setTitle(QCoreApplication::translate("MainWindow", "Comport Status", nullptr));
        btnconnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        btn_Close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        lbl_Status_Comport->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Send Data", nullptr));
        btnClear_Send_Data->setText(QCoreApplication::translate("MainWindow", "Clear data", nullptr));
        btnSend_Data->setText(QCoreApplication::translate("MainWindow", "Send Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
