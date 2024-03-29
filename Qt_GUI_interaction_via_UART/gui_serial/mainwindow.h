#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_btnconnect_clicked();


    void Mytimer_timeout();

    void on_btn_Close_clicked();

    void on_btnSend_Data_clicked();

    void on_btnClear_Send_Data_clicked();
    void Serial_DataReceived();

    void on_btnClearData_Display_clicked();

    void on_btnClearData_plot_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
