#include "customertotaluseddialog.h"
#include "ui_customertotaluseddialog.h"
#include<QMessageBox>
#include<QDebug>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"addroomdialog.h"
#include"customer.h"
#include"hotel.h"
#include"customergradedialog.h"
extern QHash<QString,Customer*>  customerInfo;//customerID
extern QHash<QString,Order*> orderInfo;//orderID
extern QHash<QString,Hotel*> hotelInfo;//hotelID
extern QHash<QString,Manager*> managerInfo;//managerID
extern QHash<QString,Room*> roomInfo;//房间类型代码吧
extern QString loginer;
int customertotalusedorderNum(QString loginer,QHash<QString,Order*>orderInfo1)
{
    int num=0;
    QHash<QString, Order*>::const_iterator i = orderInfo1.constBegin();

    while (i != orderInfo1.constEnd())
    {
        if(loginer==i.value()->getbcustomerID()&&i.value()->getprogress()!="待接单"
                &&i.value()->getprogress()!="已接单"
                &&i.value()->getprogress()!="使用中"
                &&i.value()->getprogress()!="申请退款")num++;
        i++;
    }
    return (num);
}

CustomerTotalUsedDialog::CustomerTotalUsedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerTotalUsedDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Historical Order");
    ui->tableWidget->setRowCount(customertotalusedorderNum(loginer,orderInfo));

      ui->tableWidget->setColumnCount(7);

      QHeaderView* headerView = ui->tableWidget->verticalHeader();

      headerView->setHidden(true); //行名隐藏
      QStringList header;
      header.append(QObject::tr("订单号"));
      header.append(QObject::tr("酒店"));
      header.append(QObject::tr("房型"));
      header.append(QObject::tr("入住日期"));
      header.append(QObject::tr("预定天数"));
      header.append(QObject::tr("订单状态"));
      header.append(QObject::tr("评分"));
      ui->tableWidget->setHorizontalHeaderLabels(header);
      qDebug()<<"更新后有结束订单"<<customertotalusedorderNum(loginer,orderInfo)<<"个"<<endl;
      ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
      ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
       ui->tableWidget->setFocusPolicy(Qt::NoFocus);
      int j=0;

      QHash<QString, Order*>::const_iterator i = orderInfo.constBegin();

      while (i != orderInfo.constEnd())
      {
        if(loginer==i.value()->getbcustomerID()
                &&i.value()->getprogress()!="待接单"
                &&i.value()->getprogress()!="已接单"
                &&i.value()->getprogress()!="使用中"
                &&i.value()->getprogress()!="申请退款")
          {
            ui->tableWidget->setItem(j,0,new QTableWidgetItem(i.value()->getorderID(),1000));
            ui->tableWidget->setItem(j,1,new QTableWidgetItem(roomInfo[i.value()->getbroomID()]->gethotelName(),1001));
            ui->tableWidget->setItem(j,2,new QTableWidgetItem(roomInfo[i.value()->getbroomID()]->getroomType(),1000));
            ui->tableWidget->setItem(j,3,new QTableWidgetItem(i.value()->getliveinDate().toString("yyyy-MM-dd"),1000));
            ui->tableWidget->setItem(j,4,new QTableWidgetItem(QString("%1").arg(i.value()->getdayNum()),1000));
            ui->tableWidget->setItem(j,5,new QTableWidgetItem(i.value()->getprogress(),1000));
            ui->tableWidget->setItem(j,6,new QTableWidgetItem(QString("%1").arg(i.value()->getgrade()),1000));

            j++;
          }
        i++;
      }

}

CustomerTotalUsedDialog::~CustomerTotalUsedDialog()
{
    delete ui;
}

void CustomerTotalUsedDialog::on_pushButton_clicked()
{
    this->close();
}
