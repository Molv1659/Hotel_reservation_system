#include "hotelinfochangedialog.h"
#include "ui_hotelinfochangedialog.h"
#include"hotel.h"
#include<QMessageBox>
#include<QDebug>
extern QHash<QString,Hotel*>hotelInfo;
extern QString loginer;
HotelInfoChangeDialog::HotelInfoChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotelInfoChangeDialog)
{

    ui->setupUi(this); 
    this->setWindowTitle("Change Hotel Infomation");
    ui->lineEdit_2->setText(hotelInfo[loginer]->gethotelPassport());
    ui->lineEdit_3->setText(hotelInfo[loginer]->getlocation());
    ui->lineEdit_4->setText(hotelInfo[loginer]->gettelephone());
    ui->lineEdit->setText(hotelInfo[loginer]->gethotelPictureAddress());
}

HotelInfoChangeDialog::~HotelInfoChangeDialog()
{
    delete ui;
}

void HotelInfoChangeDialog::on_pushButton_2_clicked()
{
    this->close();
}

void HotelInfoChangeDialog::on_pushButton_clicked()
{
         hotelInfo[loginer]->sethotelPictureAddress(ui->lineEdit->text());
         hotelInfo[loginer]->sethotelPassport(ui->lineEdit_2->text());
         hotelInfo[loginer]->setlocation(ui->lineEdit_3->text());
         hotelInfo[loginer]->settelephone(ui->lineEdit_4->text());
         QMessageBox::information(NULL, "消息", "更改成功", QMessageBox::Yes);
    this->close();

}
