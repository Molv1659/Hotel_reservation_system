#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>
#include<QApplication>
#include<QtGui>

#include"checktrial.h"
#include"database.h"
#include<QFile>
#include"customerdialog.h"
#include"managerdialog.h"
#include"hoteldialog.h"
#include"platformdialog.h"//平台只有一个用户 用户名：Corey 密码： Corey

#include"customerregestrationdlg.h"
#include"managerregestrationdlg.h"
#include"hotelregestrationdlg.h"
#include<QPainter>
extern QHash<QString,Customer*>  customerInfo;//customerID
extern QString loginer;
extern CustomerDialog dlg00;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
    QFile file(":/new/prefix1/sample1.qss");

       file.open(QFile::ReadOnly);

       QString styleSheet = tr(file.readAll());

       qApp->setStyleSheet(styleSheet);

       ui->frame->setStyleSheet("border-image:url(:/background/3.jpg)");
     /*  QFrame *frame = new QFrame;
        //frame->setObjectName("myframe");
        frame->resize(1111,649);
        frame->setStyleSheet("QFrame#myframe{border-image:url(:/background/1.png)}" );
        frame->show();*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{

   if(ui->radioButton->isChecked())
   {
       CustomerRegestrationDlg dlg0;
         dlg0.exec();
   }
   else if(ui->radioButton_2->isChecked())
   {
        QMessageBox::warning(this, tr("警告！"),
                          tr("无权注册！"),
                          QMessageBox::Yes);
   }
    else if(ui->radioButton_3->isChecked())
   {
       HotelRegestrationDlg dlg2;

         dlg2.exec();
   }
    else if(ui->radioButton_4->isChecked())
   {
       QMessageBox::warning(this, tr("警告！"),
                           tr("无法注册平台！"),
                           QMessageBox::Yes);
   }
   else
   {
       QMessageBox::warning(this, tr(""),
                           tr("请选择身份！"),
                           QMessageBox::Yes);
   }

}

void MainWindow::on_radioButton_clicked()
{
    ui->radioButton->setChecked(true);
}

void MainWindow::on_radioButton_2_clicked()
{
   ui->radioButton_2->setChecked(true);
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->radioButton_3->setChecked(true);
}

void MainWindow::on_radioButton_4_clicked()
{
    ui->radioButton_4->setChecked(true);
}
//登陆
void MainWindow::on_pushButton_clicked()
{



    //顾客登陆
    if(ui->radioButton->isChecked())
    {
        if(checktrial(ui->lineEdit_2->text(),ui->lineEdit->text(),customerInfo))
        {
             loginer=ui->lineEdit_2->text();qDebug()<<"登陆者为"<<loginer;
             CustomerDialog dlg00;
            dlg00.exec();
        }
        else if(checktrial(ui->lineEdit_2->text(),customerInfo))
        {
            QMessageBox::warning(this, tr(""),
                                tr("密码错误"),
                                QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(this, tr(""),
                                tr("不存在此用户"),
                                QMessageBox::Yes);
        }
    }
    //酒店管理员登陆
    else if(ui->radioButton_2->isChecked())
    {
        if(checktrial(ui->lineEdit_2->text(),ui->lineEdit->text(),managerInfo))
        {
             loginer=ui->lineEdit_2->text();qDebug()<<"登陆者为"<<loginer;            
             ManagerDialog dlg11;
            dlg11.exec();
        }
        else if(checktrial(ui->lineEdit_2->text(),managerInfo))
        {
            QMessageBox::warning(this, tr(""),
                                tr("密码错误"),
                                QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(this, tr(""),
                                tr("不存在此用户"),
                                QMessageBox::Yes);
        }
    }
    //酒店登陆
   else  if(ui->radioButton_3->isChecked())
    {
        if(checktrial(ui->lineEdit_2->text(),ui->lineEdit->text(),hotelInfo))
        {
            loginer=ui->lineEdit_2->text();qDebug()<<"登陆者为"<<loginer;

        HotelDialog dlg22;
            dlg22.exec();

        }
        else if(checktrial(ui->lineEdit_2->text(),hotelInfo))
        {
            QMessageBox::warning(this, tr(""),
                                tr("密码错误"),
                                QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(this, tr(""),
                                tr("不存在此用户"),
                                QMessageBox::Yes);
        }
    }
   else  if(ui->radioButton_4->isChecked())
    {
        if(ui->lineEdit_2->text()=="Corey"&&ui->lineEdit->text()=="Corey")
         {
                PlatformDialog dlg33;
              dlg33.exec();
        }
        else
        {
            QMessageBox::warning(this, tr(""),
                                tr("登陆失败"),
                                QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::warning(NULL, tr(""),
                            tr("请选择身份！"),
                            QMessageBox::Yes);
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    connection();
    writeall();
    disconnection();
}
