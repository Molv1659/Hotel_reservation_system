#include "customerregestrationdlg.h"
#include "ui_customerregestrationdlg.h"
#include<QMessageBox>
extern QHash<QString,Customer*>  customerInfo;//customerID
CustomerRegestrationDlg::CustomerRegestrationDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerRegestrationDlg)
{
    ui->setupUi(this);
    this->setWindowTitle("Customer Registration");
}

CustomerRegestrationDlg::~CustomerRegestrationDlg()
{
    delete ui;
}

void CustomerRegestrationDlg::on_pushButton_clicked()
{
    if(ui->lineEdit->text()!=NULL&&ui->lineEdit_2->text()!=NULL&&ui->lineEdit_3->text()!=NULL)
   {
        if(customerInfo[ui->lineEdit->text()]!=NULL)
        {
          QMessageBox::information(NULL, "消息", "该用户名已被注册", QMessageBox::Yes);
        }
        else
        {
           Customer*cu=new Customer(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
           customerInfo[ui->lineEdit->text()]=cu;
           QMessageBox::information(NULL, "消息", "注册成功", QMessageBox::Yes);
           this->close();
        }
    }
    else
    {
        QMessageBox::warning(this, tr("警告"),
                          tr("请将信息填写完整"),
                          QMessageBox::Yes);
    }
}

void CustomerRegestrationDlg::on_pushButton_2_clicked()
{
   this->close();
}
