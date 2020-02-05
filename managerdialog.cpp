#include "managerdialog.h"
#include "ui_managerdialog.h"
#include<QMessageBox>
#include<QDebug>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"hotel.h"
#include"addroomdialog.h"
#include"customer.h"
#include"managerusedorderdialog.h"
extern QHash<QString,Customer*>  customerInfo;
extern QHash<QString,Room*> roomInfo;
extern QHash<QString,Order*> orderInfo;
extern QHash<QString,Manager*> managerInfo;
extern QHash<QString,Hotel*>hotelInfo;
extern QString loginer;
int oroomNum(QString a,QHash<QString,Room*>roomInfo1)
{
    int num=0;
    QHash<QString, Room*>::const_iterator i = roomInfo1.constBegin();

    while (i != roomInfo1.constEnd())
    {
        if(a==i.value()->gethotelName())num++;
        i++;
    }
    return (num);
}
//a是酒管理员所属酒店名,判断与订单得到的房间名再得酒店名是否相等,且是没有结束的订单
int oorderNum(QString a,QHash<QString,Order*>orderInfo1)
{
    int num=0;
    QHash<QString, Order*>::const_iterator i = orderInfo1.constBegin();

    while (i != orderInfo1.constEnd())
    {
        if(a==roomInfo[i.value()->getbroomID()]->gethotelName()&&i.value()->getprogress()!="使用完毕"
                &&i.value()->getprogress()!="已退款"&&i.value()->getprogress()!="拒绝接单"
                &&i.value()->getprogress()!="已取消订单")num++;
        i++;
    }
    return (num);
}
ManagerDialog::ManagerDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::ManagerDialog)
{
    ui->setupUi(this);  
     ui->frame->setStyleSheet("border-image:url(:/background/81.jpg)");
    this->setWindowTitle("Manager");
    refreshoroomtable();
    refreshoordertable();
}

void ManagerDialog::refreshoroomtable()
{

    ui->tableWidget->setRowCount(oroomNum(managerInfo[loginer]->getbHotelname(),roomInfo));

    ui->tableWidget->setColumnCount(7);

    QHeaderView* headerView = ui->tableWidget->verticalHeader();

    headerView->setHidden(true); //行名隐藏
    QStringList header;
    header.append(QObject::tr("房间代号"));
    header.append(QObject::tr("价格"));
    header.append(QObject::tr("房型"));
    header.append(QObject::tr("总量"));
    header.append(QObject::tr("当前余量"));
    header.append(QObject::tr("优惠"));
    header.append(QObject::tr("销售许可"));
    ui->tableWidget->setHorizontalHeaderLabels(header);
    qDebug()<<"更新后有房间"<<oroomNum(managerInfo[loginer]->getbHotelname(),roomInfo)<<"种"<<endl;
    int j=0;
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

    while (i != roomInfo.constEnd())
    {
      if(i.value()->gethotelName()==managerInfo[loginer]->getbHotelname())
        {
          ui->tableWidget->setItem(j,0,new QTableWidgetItem(i.value()->getroomID(),1000));
          ui->tableWidget->setItem(j,1,new QTableWidgetItem(QString("%1").arg(i.value()->getprice()),1001));
          ui->tableWidget->setItem(j,2,new QTableWidgetItem(i.value()->getroomType(),1000));
          ui->tableWidget->setItem(j,3,new QTableWidgetItem(QString("%1").arg(i.value()->gettotalNum()),1000));
          ui->tableWidget->setItem(j,4,new QTableWidgetItem(QString("%1").arg(i.value()->getremainingNum()),1000));
          ui->tableWidget->setItem(j,5,new QTableWidgetItem(QString("%1").arg(i.value()->getdiscount()),1000));
          QString sellabletext=i.value()->getsellable() ? "true":"false";
          ui->tableWidget->setItem(j,6,new QTableWidgetItem(sellabletext,1000));

          j++;
        }
      i++;
    }

}

void ManagerDialog::refreshoordertable()
{

    ui->tableWidget_2->setRowCount(oorderNum(managerInfo[loginer]->getbHotelname(),orderInfo));

    ui->tableWidget_2->setColumnCount(7);

    QHeaderView* headerView = ui->tableWidget_2->verticalHeader();

    headerView->setHidden(true); //行名隐藏
    QStringList header;
    header.append(QObject::tr("订单号"));
    header.append(QObject::tr("房间代号"));
    header.append(QObject::tr("顾客名"));
    header.append(QObject::tr("顾客电话"));
    header.append(QObject::tr("入住日期"));
    header.append(QObject::tr("预定天数"));
    header.append(QObject::tr("订单状态"));
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    qDebug()<<"更新后有未结束订单"<<oorderNum(managerInfo[loginer]->getbHotelname(),orderInfo)<<"笔"<<endl;
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    int j=0;

    QHash<QString, Order*>::const_iterator i = orderInfo.constBegin();

    while (i != orderInfo.constEnd())
    {
      if(roomInfo[i.value()->getbroomID()]->gethotelName()==managerInfo[loginer]->getbHotelname()
              &&i.value()->getprogress()!="使用完毕"
              &&i.value()->getprogress()!="已退款"
              &&i.value()->getprogress()!="拒绝接单"
              &&i.value()->getprogress()!="已取消订单")
        {
          ui->tableWidget_2->setItem(j,0,new QTableWidgetItem(i.value()->getorderID(),1000));
          ui->tableWidget_2->setItem(j,1,new QTableWidgetItem(i.value()->getbroomID(),1001));
          ui->tableWidget_2->setItem(j,2,new QTableWidgetItem(i.value()->getbcustomerID(),1000));
          ui->tableWidget_2->setItem(j,3,new QTableWidgetItem(customerInfo[i.value()->getbcustomerID()]->getmobilePhone(),1000));
          ui->tableWidget_2->setItem(j,4,new QTableWidgetItem(i.value()->getliveinDate().toString("yyyy-MM-dd"),1000));
          ui->tableWidget_2->setItem(j,5,new QTableWidgetItem(QString("%1").arg(i.value()->getdayNum()),1000));
          ui->tableWidget_2->setItem(j,6,new QTableWidgetItem(i.value()->getprogress(),1000));

          j++;
        }
      i++;
    }

}

ManagerDialog::~ManagerDialog()
{
    delete ui;
}


void ManagerDialog::on_pushButton_clicked()
{
    if(hotelInfo[managerInfo[loginer]->getbHotelname()]->getworkable()==true)
  {AddRoomDialog dlg3333;
  dlg3333.exec();
  refreshoroomtable();}
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                          tr("未得到营业许可！"),
                          QMessageBox::Yes);
    }

}



void ManagerDialog::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()!=NULL)
    {
        int rowindex=ui->tableWidget->currentRow();
        if(rowindex!=-1)
       {
            roomInfo[ui->tableWidget->item(rowindex,0)->text()]->setprice(ui->lineEdit->text().toFloat());
            QMessageBox::information(NULL, "消息", "更改成功", QMessageBox::Yes);
            refreshoroomtable();
        }
        else
        {
            QMessageBox::information(NULL, "注意", "请选择房间", QMessageBox::Yes);
        }
    }
    else
    {

       QMessageBox::information(NULL, "注意", "请先输入更改价格", QMessageBox::Yes);
    }
}

void ManagerDialog::on_pushButton_3_clicked()
{
    if(ui->lineEdit_2->text()!=NULL)
    {
        int rowindex=ui->tableWidget->currentRow();
        if(rowindex!=-1)
        {
            int changenum=ui->lineEdit_2->text().toInt()-roomInfo[ui->tableWidget->item(rowindex,0)->text()]->gettotalNum();
            if(changenum+roomInfo[ui->tableWidget->item(rowindex,0)->text()]->getremainingNum()<0)
        {
            QMessageBox::warning(this, tr("警告！"),
                              tr("总量不能少于正在被使用房间的数量！"),
                              QMessageBox::Yes);
        }
        else
        {
        roomInfo[ui->tableWidget->item(rowindex,0)->text()]->settotalNum(ui->lineEdit_2->text().toInt());
        roomInfo[ui->tableWidget->item(rowindex,0)->text()]->setremainingNum(roomInfo[ui->tableWidget->item(rowindex,0)->text()]->getremainingNum()+changenum);

        QMessageBox::information(NULL, "消息", "更改成功", QMessageBox::Yes);
        refreshoroomtable();
        }
        }
        else
        {
             QMessageBox::information(NULL, "注意", "请先选择房间", QMessageBox::Yes);
        }
    }
    else
    {
       QMessageBox::information(NULL, "注意", "请先输入更改总房数", QMessageBox::Yes);
    }
}

void ManagerDialog::on_pushButton_4_clicked()
{
    if(ui->lineEdit_3->text()!=NULL)
    {
        int rowindex=ui->tableWidget->currentRow();
        if(rowindex!=-1)
       {
            roomInfo[ui->tableWidget->item(rowindex,0)->text()]->setdiscount(ui->lineEdit_3->text().toFloat());
            QMessageBox::information(NULL, "消息", "更改成功", QMessageBox::Yes);
            refreshoroomtable();
        }
        else
        {
             QMessageBox::information(NULL, "注意", "请先选择房间", QMessageBox::Yes);
        }

    }
    else
    {

       QMessageBox::information(NULL, "注意", "请先输入更改的折扣", QMessageBox::Yes);
    }
}


void ManagerDialog::on_pushButton_5_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="待接单")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("已接单");
      refreshoordertable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("只能对未接单的订单执行此操作"),
                            QMessageBox::Yes);
    }
   }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择订单"),
                            QMessageBox::Yes);
    }

}

void ManagerDialog::on_pushButton_6_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="待接单")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("拒绝接单");
       refreshoordertable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("只能对未接单的订单执行此操作"),
                            QMessageBox::Yes);
    }
   }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择订单"),
                            QMessageBox::Yes);
    }
}

void ManagerDialog::on_pushButton_7_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="申请退款")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("已退款");
       refreshoordertable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("只能对申请退款的订单执行此操作"),
                            QMessageBox::Yes);
    }
   }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择订单"),
                            QMessageBox::Yes);
    }

}

void ManagerDialog::on_pushButton_8_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="申请退款")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("已接单");
       refreshoordertable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("只能对申请退款的订单执行此操作"),
                            QMessageBox::Yes);
    }
   }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择订单"),
                            QMessageBox::Yes);
    }

}

void ManagerDialog::on_pushButton_10_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="已接单")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("使用中");

      roomInfo[orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getbroomID()]->setremainingNum( roomInfo[orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getbroomID()]->getremainingNum()-1);
       refreshoordertable();
       refreshoroomtable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("只能对已接单的订单执行此操作"),
                            QMessageBox::Yes);
    }
   }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择订单"),
                            QMessageBox::Yes);
    }

}

void ManagerDialog::on_pushButton_11_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="使用中")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("使用完毕");

      roomInfo[orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getbroomID()]->setremainingNum( roomInfo[orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getbroomID()]->getremainingNum()+1);
       refreshoordertable();
       refreshoroomtable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("只能对使用中的订单执行此操作"),
                            QMessageBox::Yes);
    }
   }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择订单"),
                            QMessageBox::Yes);
    }

}

void ManagerDialog::on_pushButton_9_clicked()
{
    ManagerUsedOrderDialog dlg3333;
    dlg3333.exec();
}
