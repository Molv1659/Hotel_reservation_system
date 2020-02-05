#include "customerinfochangedialog.h"
#include "ui_customerinfochangedialog.h"
#include"customer.h"
#include<QMessageBox>
extern QHash<QString,Customer*> customerInfo;
extern QString loginer;
CustomerInfoChangeDialog::CustomerInfoChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerInfoChangeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Change Customer Infomation");
    ui->lineEdit->setText(customerInfo[loginer]->getcustomerPassport());
    ui->lineEdit_2->setText(customerInfo[loginer]->getmobilePhone());
}

CustomerInfoChangeDialog::~CustomerInfoChangeDialog()
{
    delete ui;
}

void CustomerInfoChangeDialog::on_pushButton_2_clicked()
{
    this->close();
}

void CustomerInfoChangeDialog::on_pushButton_clicked()
{
    customerInfo[loginer]->setcustomerPassport(ui->lineEdit->text());
    customerInfo[loginer]->setmobilePhone(ui->lineEdit_2->text());
    QMessageBox::information(this,"消息","修改成功",QMessageBox::Yes);
    this->close();

}
