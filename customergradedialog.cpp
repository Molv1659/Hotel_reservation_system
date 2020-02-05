#include "customergradedialog.h"
#include "ui_customergradedialog.h"
#include<QMessageBox>
#include<QDebug>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"hotel.h"
#include"addroomdialog.h"
#include"customer.h"
#include"managerusedorderdialog.h"
extern QString chosingorder;
extern QHash<QString,Customer*>  customerInfo;//customerID
extern QHash<QString,Order*> orderInfo;//orderID
extern QHash<QString,Hotel*> hotelInfo;//hotelID
extern QHash<QString,Manager*> managerInfo;//managerID
extern QHash<QString,Room*> roomInfo;//房间类型代码吧
CustomerGradeDialog::CustomerGradeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerGradeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Assess the Oreder");
}

CustomerGradeDialog::~CustomerGradeDialog()
{
    delete ui;
}

void CustomerGradeDialog::on_pushButton_2_clicked()
{
    this->close();
}

void CustomerGradeDialog::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        orderInfo[chosingorder]->setgrade(1);
        Hotel*hotelt= hotelInfo[roomInfo[orderInfo[chosingorder]->getbroomID()]->gethotelName()];
        hotelt->setassessment((1+hotelt->getassessNum()*hotelt->getassessment())/(hotelt->getassessNum()+1));
        hotelt->setassessNum(hotelt->getassessNum()+1);
        QMessageBox::information(this,"注意","评价成功",QMessageBox::Yes);
        emit gradenew();
        this->close();
    }
    else if(ui->radioButton_2->isChecked())
    {
        orderInfo[chosingorder]->setgrade(2);
        Hotel*hotelt= hotelInfo[roomInfo[orderInfo[chosingorder]->getbroomID()]->gethotelName()];
        hotelt->setassessment((2+hotelt->getassessNum()*hotelt->getassessment())/(hotelt->getassessNum()+1));
        hotelt->setassessNum(hotelt->getassessNum()+1);
        QMessageBox::information(this,"注意","评价成功",QMessageBox::Yes);
        emit gradenew();
        this->close();
    }
    else if(ui->radioButton_3->isChecked())
    {
        orderInfo[chosingorder]->setgrade(3);
        Hotel*hotelt= hotelInfo[roomInfo[orderInfo[chosingorder]->getbroomID()]->gethotelName()];
        hotelt->setassessment((3+hotelt->getassessNum()*hotelt->getassessment())/(hotelt->getassessNum()+1));
        hotelt->setassessNum(hotelt->getassessNum()+1);
        QMessageBox::information(this,"注意","评价成功",QMessageBox::Yes);
        emit gradenew();
        this->close();
    }
    else if(ui->radioButton_4->isChecked())
    {
        orderInfo[chosingorder]->setgrade(4);
        Hotel*hotelt= hotelInfo[roomInfo[orderInfo[chosingorder]->getbroomID()]->gethotelName()];
        hotelt->setassessment((4+hotelt->getassessNum()*hotelt->getassessment())/(hotelt->getassessNum()+1));
        hotelt->setassessNum(hotelt->getassessNum()+1);
        QMessageBox::information(this,"注意","评价成功",QMessageBox::Yes);
        emit gradenew();
        this->close();
    }
    else if(ui->radioButton_5->isChecked())
    {
        orderInfo[chosingorder]->setgrade(5);
        Hotel*hotelt= hotelInfo[roomInfo[orderInfo[chosingorder]->getbroomID()]->gethotelName()];
        hotelt->setassessment((5+hotelt->getassessNum()*hotelt->getassessment())/(hotelt->getassessNum()+1));
        hotelt->setassessNum(hotelt->getassessNum()+1);
        QMessageBox::information(this,"注意","评价成功",QMessageBox::Yes);
        emit gradenew();
        this->close();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请选择分数！"),
                            QMessageBox::Yes);
    }

}
