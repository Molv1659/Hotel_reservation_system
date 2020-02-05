#include "managerusedorderdialog.h"
#include "ui_managerusedorderdialog.h"
#include<QMessageBox>
#include<QDebug>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"addroomdialog.h"
#include"customer.h"
extern QHash<QString,Customer*>  customerInfo;
extern QHash<QString,Room*> roomInfo;
extern QHash<QString,Order*> orderInfo;
extern QHash<QString,Manager*> managerInfo;
extern QString loginer;
int usedorderNum(QString a,QHash<QString,Order*>orderInfo1)
{
    int num=0;
    QHash<QString, Order*>::const_iterator i = orderInfo1.constBegin();

    while (i != orderInfo1.constEnd())
    {
        if(a==roomInfo[i.value()->getbroomID()]->gethotelName()&&i.value()->getprogress()!="待接单"
                &&i.value()->getprogress()!="已接单"&&i.value()->getprogress()!="使用中"
                &&i.value()->getprogress()!="申请退款")num++;
        i++;
    }
    return (num);
}
ManagerUsedOrderDialog::ManagerUsedOrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerUsedOrderDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Historical Order");
    refreshusedordertable();
}

void ManagerUsedOrderDialog::refreshusedordertable()
{
    ui->tableWidget->setRowCount(usedorderNum(managerInfo[loginer]->getbHotelname(),orderInfo));

    ui->tableWidget->setColumnCount(8);

    QHeaderView* headerView = ui->tableWidget->verticalHeader();

    headerView->setHidden(true); //行名隐藏
    QStringList header;
    header.append(QObject::tr("订单号"));
    header.append(QObject::tr("房间代号"));
    header.append(QObject::tr("顾客名"));
    header.append(QObject::tr("顾客电话"));
    header.append(QObject::tr("入住日期"));
    header.append(QObject::tr("预定天数"));
    header.append(QObject::tr("订单状态"));
    header.append(QObject::tr("评分"));
    ui->tableWidget->setHorizontalHeaderLabels(header);
    qDebug()<<"更新后有结束订单"<<usedorderNum(managerInfo[loginer]->getbHotelname(),orderInfo)<<"笔"<<endl;
    int j=0;

    QHash<QString, Order*>::const_iterator i = orderInfo.constBegin();

    while (i != orderInfo.constEnd())
    {
      if(roomInfo[i.value()->getbroomID()]->gethotelName()==managerInfo[loginer]->getbHotelname()
              &&i.value()->getprogress()!="待接单"
              &&i.value()->getprogress()!="已接单"
              &&i.value()->getprogress()!="使用中"
              &&i.value()->getprogress()!="申请退款")
        {
          ui->tableWidget->setItem(j,0,new QTableWidgetItem(i.value()->getorderID(),1000));
          ui->tableWidget->setItem(j,1,new QTableWidgetItem(i.value()->getbroomID(),1001));
          ui->tableWidget->setItem(j,2,new QTableWidgetItem(i.value()->getbcustomerID(),1000));
          ui->tableWidget->setItem(j,3,new QTableWidgetItem(customerInfo[i.value()->getbcustomerID()]->getmobilePhone(),1000));
          ui->tableWidget->setItem(j,4,new QTableWidgetItem(i.value()->getliveinDate().toString("yyyy-MM-dd"),1000));
          ui->tableWidget->setItem(j,5,new QTableWidgetItem(QString("%1").arg(i.value()->getdayNum()),1000));
          ui->tableWidget->setItem(j,6,new QTableWidgetItem(i.value()->getprogress(),1000));
          ui->tableWidget->setItem(j,7,new QTableWidgetItem(QString("%1").arg(i.value()->getgrade()),1000));


          j++;
        }
      i++;
    }
}

ManagerUsedOrderDialog::~ManagerUsedOrderDialog()
{
    delete ui;
}

void ManagerUsedOrderDialog::on_pushButton_clicked()
{
    this->close();
}
