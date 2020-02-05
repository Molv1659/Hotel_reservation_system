#include "addorderdialog.h"
#include "ui_addorderdialog.h"
#include<QMessageBox>
#include<QDebug>
#include<QDate>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"addroomdialog.h"
#include"customer.h"
#include"hotel.h"
#include"customerusedorderdialog.h"
#include"detailedinfodialog.h"
#include"addorderdialog.h"
#include"customerdialog.h"


extern QHash<QString,Customer*>  customerInfo;//customerID
extern QHash<QString,Order*> orderInfo;//orderID
extern QHash<QString,Hotel*> hotelInfo;//hotelID
extern QHash<QString,Manager*> managerInfo;//managerID
extern QHash<QString,Room*> roomInfo;//房间类型代码吧
extern QString loginer;
double ordID=123456;
extern QString chosingroom;

AddOrderDialog::AddOrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOrderDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Oreder the Room");
    ui->spinBox->setValue(1);
    ui->dateEdit->setDate(QDate::currentDate());

}

AddOrderDialog::~AddOrderDialog()
{
    delete ui;
}

void AddOrderDialog::on_pushButton_2_clicked()
{
    this->close();
}

void AddOrderDialog::on_pushButton_clicked()
{
    ordID+=orderInfo.size();
    Order*ord=new Order(QString("%1").arg(ordID),loginer,"待接单",roomInfo[chosingroom]->getroomID(),ui->dateEdit->date(),ui->spinBox->value(),0);
    orderInfo[QString("%1").arg(ordID)]=ord;
    QMessageBox::information(NULL, "消息", "预定成功", QMessageBox::Yes);
    emit addneworeder();
    this->close();
}
