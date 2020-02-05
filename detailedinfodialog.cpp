#include "detailedinfodialog.h"
#include "ui_detailedinfodialog.h"
#include<QMessageBox>
#include<QDebug>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"hotel.h"
#include"addroomdialog.h"
#include"customer.h"
#include"managerusedorderdialog.h"
#include"addroomdialog.h"
#include"addorderdialog.h"
#include <QLabel>
#include<QImage>
extern QHash<QString,Customer*>  customerInfo;
extern QHash<QString,Room*> roomInfo;
extern QHash<QString,Order*> orderInfo;
extern QHash<QString,Manager*> managerInfo;
extern QHash<QString,Hotel*>hotelInfo;
extern QString loginer;
extern QString chosingroom;
DetailedInfoDialog::DetailedInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailedInfoDialog)
{
    ui->setupUi(this);
     ui->frame->setStyleSheet("border-image:url(:/background/9.jpg)");
    this->setWindowTitle("Detailed Infomation");
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
   // ui->label->setScaledContents(true);
    QImage Image;
     //酒店图
        Image.load(hotelInfo[roomInfo[chosingroom]->gethotelName()]->gethotelPictureAddress());
        QPixmap pixmap = QPixmap::fromImage(Image);
        int with = ui->label->width();
        int height = ui->label->height();
       // QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
        ui->label->setPixmap(fitpixmap);

      //房间图
     QImage Image1;
    Image1.load(roomInfo[chosingroom]->getpictureAddress());
    QPixmap pixmap1 = QPixmap::fromImage(Image1);
    int with1 = ui->label_6->width();
   int   height1 = ui->label_6->height();
   // QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap fitpixmap1 = pixmap1.scaled(with1, height1, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
   ui->label_6->setPixmap(fitpixmap1);
   // ui->label_6->setPixmap(QPixmap(roomInfo[chosingroom]->getpictureAddress()));
    ui->lineEdit->setText(roomInfo[chosingroom]->gethotelName());
    ui->lineEdit_2->setText(hotelInfo[roomInfo[chosingroom]->gethotelName()]->getlocation());
    ui->lineEdit_3->setText(QString("%1").arg(hotelInfo[roomInfo[chosingroom]->gethotelName()]->getassessment()));
    ui->lineEdit_4->setText(hotelInfo[roomInfo[chosingroom]->gethotelName()]->gettelephone());
    ui->lineEdit_5->setText(roomInfo[chosingroom]->getroomType());
    ui->lineEdit_6->setText(QString("%1").arg(roomInfo[chosingroom]->getprice()));
    ui->lineEdit_7->setText(QString("%1").arg(roomInfo[chosingroom]->getprice()*roomInfo[chosingroom]->getdiscount()/10.0));
    ui->textEdit->setText(roomInfo[chosingroom]->getdiscribe());
}

DetailedInfoDialog::~DetailedInfoDialog()
{
    delete ui;
}

void DetailedInfoDialog::on_pushButton_2_clicked()
{
    emit backrefresh();
    this->close();
}

void DetailedInfoDialog::on_pushButton_clicked()
{
   AddOrderDialog dlg111111;

   dlg111111.exec();
}
