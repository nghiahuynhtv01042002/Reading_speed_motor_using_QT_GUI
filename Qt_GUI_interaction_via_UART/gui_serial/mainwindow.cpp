#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTimer>
#include <QVector>



QSerialPort* mySerialPort = new QSerialPort;
QString dataOut ;

int left_encoder =0;
int right_encoder = 0 ;
int pre_left_encoder = 0;
int pre_right_encoder = 0;
QVector<double> time_X = {0}, VR_data ={0} ,VL_data{0};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowTitle("Serial Control");

    // set comport in laptop appear on combox_Port_Name
    foreach(auto &portInfo, QSerialPortInfo::availablePorts()){
        ui->combox_Port_Name->addItem(portInfo.portName());
    }
    // add Baudrate_value into combox_Baudrate

    QStringList Baudrate_list = {"115200","9600","4800","2400","1200"};
    ui->combox_Baudrate->addItems(Baudrate_list);
    // add databits into comBox_Data_Bits
    QStringList databits_list = {"8","7","6"};
    ui->comBox_Data_Bits->addItems(databits_list);
    // add stopbits into combox_Stop_Bits
    QStringList stopbits_list = {"One","Two"};
    ui->combox_Stop_Bits->addItems(stopbits_list);
    // add Paritybits into combox_Stopbit
    QStringList Parity_list ={"None","Odd","Even"};
    ui->combox_Parity_bits->addItems(Parity_list);
    //enable some button
    ui->btnconnect->setEnabled(true);
    ui->btn_Close->setEnabled(false);
    ui->lbl_Status_Comport->setText("OFF");
    ui->lbl_Status_Comport->setStyleSheet("color: black;background-color: grey;");
    //config graph
    ui->Plot_chart->addGraph();
    ui->Plot_chart->addGraph();

    ui->Plot_chart->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
    ui->Plot_chart->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->Plot_chart->graph(1)->setPen(QPen(Qt::blue));

//    ui->Plot_chart->addGraph();
    ui->Plot_chart->graph(1)->setScatterStyle(QCPScatterStyle::ssDot);
    ui->Plot_chart->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->Plot_chart->graph(1)->setPen(QPen(Qt::red));

    ui->Plot_chart->xAxis->setLabel("time(s)");
    ui->Plot_chart->yAxis->setLabel("velocity(rpm)");
    ui->Plot_chart->xAxis->setRange(0,1000);
    ui->Plot_chart->yAxis->setRange(-100,100);
    ui->Plot_chart->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


//    qDebug()<<titleWindow;
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox closemsgBox(QMessageBox::Question,"Question","Do You Want To Exit???",QMessageBox::Yes| QMessageBox::No);
    closemsgBox.setDefaultButton(QMessageBox::No);
    int ret = closemsgBox.exec();
    if(ret ==QMessageBox::No){
        event->ignore();
    }
}


void MainWindow::on_btnconnect_clicked() {
//    ui->list_data->addItem("iam TXN");

//    if(mySerialPort == nullptr){
//        mySerialPort->close();
//        delete mySerialPort;
//    }
    // config serial port with data took from comboxs
    mySerialPort = new QSerialPort(this);
    mySerialPort->setPortName(ui->combox_Port_Name->currentText());
    mySerialPort->setBaudRate(ui->combox_Baudrate->currentText().toInt());
    mySerialPort->setDataBits(static_cast<QSerialPort::DataBits>(ui->comBox_Data_Bits->currentText().toInt()));
    mySerialPort->setStopBits(static_cast<QSerialPort::StopBits>(ui->combox_Stop_Bits->currentText().toInt()));
    mySerialPort->setParity(static_cast<QSerialPort::Parity>(ui->combox_Parity_bits->currentText().toInt()));

    mySerialPort->open(QIODevice::ReadWrite);
    connect(mySerialPort, SIGNAL(readyRead()), this, SLOT(Serial_DataReceived()));
    if(mySerialPort->isOpen()){
        ui->btnconnect->setEnabled(false);
        ui->btn_Close->setEnabled(true);
        ui->lbl_Status_Comport->setText("ON");
        ui->lbl_Status_Comport->setStyleSheet("color: black;background-color: green;");
    }
    else{
       ui->btnconnect->setEnabled(false);
       ui->btn_Close->setEnabled(true);
       ui->lbl_Status_Comport->setText("OFF");
       ui->lbl_Status_Comport->setStyleSheet("color: black;background-color: grey;");
       QMessageBox::warning(this,"Warning","Port is not conected!!");
    }

}

void MainWindow::Mytimer_timeout(){

}

void MainWindow::on_btn_Close_clicked()
{
    if(mySerialPort->isOpen()){
        mySerialPort->close();
        ui->btnconnect->setEnabled(true);
        ui->btn_Close->setEnabled(false);
        ui->lbl_Status_Comport->setText("OFF");
        ui->lbl_Status_Comport->setStyleSheet("color: black;background-color: grey;");
    }
}


void MainWindow::on_btnSend_Data_clicked()
{
    if(mySerialPort->isOpen()){
        dataOut = ui->txtEdit_Send_Data->toPlainText() + "\n";
        mySerialPort->write(dataOut.toUtf8());
        ui->listWidget_data_display->addItem("DATA SEND:");
        ui->listWidget_data_display->addItem(dataOut.trimmed()); //cut off '\n'

    }else{
        QMessageBox::warning(this,"Warning","Port is not conected!!");
    }
}

void MainWindow::on_btnClear_Send_Data_clicked()
{
    ui->txtEdit_Send_Data->clear();
}
void MainWindow::Serial_DataReceived()
{
// If you don't want it to be colorful, just use this code below. :VV;
//    ui->listWidget_data_display->addItem("DATA RECIEVE:");
//    ui->listWidget_data_display->addItem(mySerialPort->readAll());

    QString data_receive = mySerialPort->readAll();

    int split_index1 = data_receive.indexOf(":");
    int split_index2 = data_receive.indexOf("#");
    int split_index3 = data_receive.indexOf(":",split_index2+1);
    int split_index4 = data_receive.indexOf("#",split_index3+1);

    if (split_index1 != -1 && split_index2 != -1 && split_index3 != -1 && split_index4 != -1) {
        // Lấy phần tử con chuỗi từ sau ký tự ':' đến trước ký tự '#'
        QString left_value = data_receive.mid(split_index1 + 1,split_index2 - split_index1 - 1);
        QString right_value = data_receive.mid(split_index3+1,split_index4-split_index3 -1);
        // Chuyển đổi các giá trị từ kiểu chuỗi sang kiểu số nguyên
        left_encoder = left_value.toInt();
        right_encoder = right_value.toInt();
        // In ra giá trị đã đọc được
        qDebug() << "Left encoder:" << left_encoder;
        qDebug() << "Right encoder:" << right_encoder;

    }
    else {
        qDebug() << "Không tìm thấy ký tự phân tách trong chuỗi.";
    }
    double VL = 0;
    double VR = 0;
    if(time_X.last() >1){
        VL = (double)(left_encoder - pre_left_encoder)*60/(1030);
        VR = (double)(right_encoder - pre_right_encoder)*60/(1030);
    }
//    double VL = (double)(left_encoder - pre_left_encoder)*60/(1030);
//    double VR = (double)(right_encoder - pre_right_encoder)*60/(1030);

    VL_data.append(VL);
    VR_data.append(VR);
//    if(time_X.last() <1){
//        VL_data.removeFirst();
//        VR_data.removeFirst();
//    }


    QListWidgetItem *item_recieve1 = new QListWidgetItem("DATA RECIEVE:");
    item_recieve1->setForeground(QBrush(Qt::darkGreen)); // Change color here
    ui->listWidget_data_display->addItem(item_recieve1);

    QListWidgetItem *item_recieve2 = new QListWidgetItem(data_receive.trimmed());
    item_recieve2->setForeground(QBrush(Qt::darkGreen)); // Change color here
    ui->listWidget_data_display->addItem(item_recieve2);

    QListWidgetItem *item_recieve3 = new QListWidgetItem("Vl:"+QString::number(VL));
    item_recieve3->setForeground(QBrush(Qt::darkRed)); // Change color here
    ui->listWidget_data_display->addItem(item_recieve3);

    QListWidgetItem *item_recieve4 = new QListWidgetItem("VR:"+QString::number(VR));
    item_recieve4->setForeground(QBrush(Qt::darkRed)); // Change color here
    ui->listWidget_data_display->addItem(item_recieve4);
    pre_left_encoder = left_encoder;
    pre_right_encoder = right_encoder;
    // plot graph

    time_X.append(double(time_X.last() +1));
    if(time_X.last() > 1){
        ui->Plot_chart->graph(0)->setData(time_X,VL_data);
        ui->Plot_chart->graph(1)->setData(time_X,VR_data);
        ui->Plot_chart->rescaleAxes();
        ui->Plot_chart->replot();
        ui->Plot_chart->update();
    }

}


void MainWindow::on_btnClearData_Display_clicked()
{
   ui->listWidget_data_display->clear();
}


void MainWindow::on_btnClearData_plot_clicked()
{
    time_X.clear();
    VL_data.clear();
    VR_data.clear();
    ui->Plot_chart->graph(0)->data()->clear();
    ui->Plot_chart->graph(1)->data()->clear();
//    ui->Plot_chart->rescaleAxes();
    ui->Plot_chart->replot();
    ui->Plot_chart->update();
}

