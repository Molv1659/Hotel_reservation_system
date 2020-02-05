#include "managerregestrationdlg.h"
#include "ui_managerregestrationdlg.h"
#include"manager.h"
#include<QMessageBox>
#include<QDebug>
extern QString loginer;
extern QHash<QString,Manager*> managerInfo;//managerID
ManagerRegestrationDlg::ManagerRegestrationDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerRegestrationDlg)
{
    ui->setupUi(this);
    this->setWindowTitle("Manager Registration");
}

ManagerRegestrationDlg::~ManagerRegestrationDlg()
{
    delete ui;
}

void ManagerRegestrationDlg::on_pushButton_2_clicked()
{
    this->close();
}

void ManagerRegestrationDlg::on_pushButton_clicked()
{
    if(ui->lineEdit->text()!=NULL&&ui->lineEdit_2->text()!=NULL)
   {
        if(managerInfo[ui->lineEdit->text()]==NULL)
        {
            Manager*ma=new Manager(ui->lineEdit->text(),ui->lineEdit_2->text(),loginer);
           managerInfo[ui->lineEdit->text()]=ma;
           qDebug()<<loginer<<"增加管理员"<<ui->lineEdit->text();
           QMessageBox::information(NULL, "消息", "注册成功", QMessageBox::Yes);
          if( !this->close())qDebug()<<"注册后关闭管理员注册界面回到酒店界面失败";
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
