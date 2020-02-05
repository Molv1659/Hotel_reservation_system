#include "hotelregestrationdlg.h"
#include "ui_hotelregestrationdlg.h"
#include"hotel.h"
#include<QMessageBox>
extern QHash<QString,Hotel*> hotelInfo;

HotelRegestrationDlg::HotelRegestrationDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotelRegestrationDlg)
{
    ui->setupUi(this);
    this->setWindowTitle("Hotel Registration");
}

HotelRegestrationDlg::~HotelRegestrationDlg()
{
    delete ui;
}

void HotelRegestrationDlg::on_pushButton_2_clicked()
{
    this->close();
}

void HotelRegestrationDlg::on_pushButton_clicked()
{
    if(ui->lineEdit->text()!=NULL&&ui->lineEdit_2->text()!=NULL&&ui->lineEdit_3->text()!=NULL&&ui->lineEdit_4->text()!=NULL)
   {
        if(hotelInfo[ui->lineEdit->text()]==NULL)
        {
            Hotel*cu=new Hotel(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_5->text(),ui->lineEdit_4->text());
           hotelInfo[ui->lineEdit->text()]=cu;
           QMessageBox::information(NULL, "消息", "注册成功", QMessageBox::Yes);
           this->close();
        }
        else
        {
            QMessageBox::information(NULL, "消息", "该用户名已被注册", QMessageBox::Yes);
        }

    }
    else
    {
        QMessageBox::warning(this, tr("警告"),
                          tr("请将信息填写完整"),
                          QMessageBox::Yes);
    }
}
