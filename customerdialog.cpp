#include "customerdialog.h"
#include "ui_customerdialog.h"
#include<QMessageBox>
#include<QDebug>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"addroomdialog.h"
#include"customer.h"
#include"hotel.h"
#include"customerusedorderdialog.h"
#include"detailedinfodialog.h"
#include"addorderdialog.h"
#include"customertotaluseddialog.h"
#include"customerinfochangedialog.h"
extern QHash<QString,Customer*>  customerInfo;//customerID
extern QHash<QString,Order*> orderInfo;//orderID
extern QHash<QString,Hotel*> hotelInfo;//hotelID
extern QHash<QString,Manager*> managerInfo;//managerID
extern QHash<QString,Room*> roomInfo;//房间类型代码吧
extern QString loginer;
QString chosingroom;
int allroomNum()
{
    int num=0;
    QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

    while (i != roomInfo.constEnd())
    {
        if(i.value()->getsellable()==true)num++;
        i++;
    }
    return (num);
}

int usingorderNum(QString loginer,QHash<QString,Order*>orderInfo1)
{
    int num=0;
    QHash<QString, Order*>::const_iterator i = orderInfo1.constBegin();

    while (i != orderInfo1.constEnd())
    {
        if(loginer==i.value()->getbcustomerID()&&i.value()->getprogress()!="使用完毕"
                &&i.value()->getprogress()!="已退款"
                &&i.value()->getprogress()!="拒绝接单"
                &&i.value()->getprogress()!="已取消订单")num++;
        i++;
    }
    return (num);
}
CustomerDialog::CustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Customer");
    ui->frame->setStyleSheet("border-image:url(:/background/5.jpg)");
    refreshmyordertable();
    refreshroomtableall();
}

void CustomerDialog::refreshmyordertable()
{

    ui->tableWidget_2->setRowCount(usingorderNum(loginer,orderInfo));

    ui->tableWidget_2->setColumnCount(6);

    QHeaderView* headerView = ui->tableWidget_2->verticalHeader();

    headerView->setHidden(true); //行名隐藏
    QStringList header;

    header.append(QObject::tr("订单号"));
    header.append(QObject::tr("酒店"));
    header.append(QObject::tr("房型"));
    header.append(QObject::tr("入住日期"));
    header.append(QObject::tr("预定天数"));
    header.append(QObject::tr("订单状态"));
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    qDebug()<<"更新后有未结束订单"<<usingorderNum(loginer,orderInfo)<<"个"<<endl;
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    int j=0;

    QHash<QString, Order*>::const_iterator i = orderInfo.constBegin();

    while (i != orderInfo.constEnd())
    {
      if(loginer==i.value()->getbcustomerID()
              &&i.value()->getprogress()!="使用完毕"
              &&i.value()->getprogress()!="已退款"
              &&i.value()->getprogress()!="拒绝接单"
              &&i.value()->getprogress()!="已取消订单")
        {
          ui->tableWidget_2->setItem(j,0,new QTableWidgetItem(i.value()->getorderID(),1000));
          ui->tableWidget_2->setItem(j,1,new QTableWidgetItem(roomInfo[i.value()->getbroomID()]->gethotelName(),1001));
          ui->tableWidget_2->setItem(j,2,new QTableWidgetItem(roomInfo[i.value()->getbroomID()]->getroomType(),1000));
          ui->tableWidget_2->setItem(j,3,new QTableWidgetItem(i.value()->getliveinDate().toString("yyyy-MM-dd"),1000));
          ui->tableWidget_2->setItem(j,4,new QTableWidgetItem(QString("%1").arg(i.value()->getdayNum()),1000));
          ui->tableWidget_2->setItem(j,5,new QTableWidgetItem(i.value()->getprogress(),1000));

          j++;
        }
      i++;
    }

}

int CustomerDialog::uproomNum()
{
    int num=0;
    QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();
    if(!ui->lineEdit->text().isEmpty())
   {
        while (i != roomInfo.constEnd())
        {
            if(!ui->checkBox->isChecked())
             {
              if(i.value()->getsellable()==true&&hotelInfo[i.value()->gethotelName()]->getcity()==ui->lineEdit->text())num++;
             }
             else
            {
            if(i.value()->getsellable()==true&&i.value()->getdiscount()<10&&
                    hotelInfo[i.value()->gethotelName()]->getcity()==ui->lineEdit->text())num++;
             }
       i++;
    }
    return (num);
    }
    else
    {
        while (i != roomInfo.constEnd())
        {
            if(!ui->checkBox->isChecked())
          {
           if(i.value()->getsellable()==true)num++;
          }
           else
          {
            if(i.value()->getsellable()==true&&i.value()->getdiscount()<10)num++;
          }
       i++;
       }
     return (num);
    }
}

int CustomerDialog::downroomNum()
{
    int num=0;
    QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

    while (i != roomInfo.constEnd())
    {
        if(i.value()->getsellable()==true&&i.value()->gethotelName()==ui->lineEdit_2->text())num++;
        i++;
    }
    return (num);
}

void CustomerDialog::refreshroomtableall()
{



        ui->tableWidget->setRowCount(allroomNum());

    ui->tableWidget->setColumnCount(6);

    QHeaderView* headerView = ui->tableWidget->verticalHeader();

    headerView->setHidden(true); //行名隐藏

    QStringList header;
    header.append(QObject::tr("酒店"));
    header.append(QObject::tr("酒店地址"));
    header.append(QObject::tr("房型"));
    header.append(QObject::tr("价格"));
    header.append(QObject::tr("折扣"));
    header.append(QObject::tr("酒店评分"));
    ui->tableWidget->setHorizontalHeaderLabels(header);
    qDebug()<<"更新后共有不筛选房间商品种类"<<allroomNum()<<"种"<<endl;
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    int j=0;

    QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

    while (i != roomInfo.constEnd())
    {
      if(i.value()->getsellable()==true)
        {
          ui->tableWidget->setItem(j,0,new QTableWidgetItem(i.value()->gethotelName(),1000));
          ui->tableWidget->setItem(j,1,new QTableWidgetItem(hotelInfo[i.value()->gethotelName()]->getlocation(),1001));
          ui->tableWidget->setItem(j,2,new QTableWidgetItem(i.value()->getroomType(),1000));
          ui->tableWidget->setItem(j,3,new QTableWidgetItem(QString("%1").arg(i.value()->getprice()),1000));
          ui->tableWidget->setItem(j,4,new QTableWidgetItem(QString("%1").arg(i.value()->getdiscount()),1000));
          ui->tableWidget->setItem(j,5,new QTableWidgetItem(QString("%1").arg(hotelInfo[i.value()->gethotelName()]->getassessment()),1000));

          j++;
        }
      i++;
    }

}

void CustomerDialog::refreshroomtable2()
{

       ui->tableWidget->setRowCount(downroomNum());

        ui->tableWidget->setColumnCount(6);

        QHeaderView* headerView = ui->tableWidget->verticalHeader();

        headerView->setHidden(true); //行名隐藏
        QStringList header;
        header.append(QObject::tr("酒店"));
        header.append(QObject::tr("酒店地址"));
        header.append(QObject::tr("房型"));
        header.append(QObject::tr("价格"));
        header.append(QObject::tr("折扣"));
        header.append(QObject::tr("酒店评分"));
        ui->tableWidget->setHorizontalHeaderLabels(header);
        qDebug()<<"更新后共有该酒店房间商品种类"<<downroomNum()<<"种"<<endl;
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
         ui->tableWidget->setFocusPolicy(Qt::NoFocus);
        int j=0;

        QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

        while (i != roomInfo.constEnd())
        {
          if(i.value()->getsellable()==true&&i.value()->gethotelName()==ui->lineEdit_2->text())
            {
              ui->tableWidget->setItem(j,0,new QTableWidgetItem(i.value()->gethotelName(),1000));
              ui->tableWidget->setItem(j,1,new QTableWidgetItem(hotelInfo[i.value()->gethotelName()]->getlocation(),1001));
              ui->tableWidget->setItem(j,2,new QTableWidgetItem(i.value()->getroomType(),1000));
              ui->tableWidget->setItem(j,3,new QTableWidgetItem(QString("%1").arg(i.value()->getprice()),1000));
              ui->tableWidget->setItem(j,4,new QTableWidgetItem(QString("%1").arg(i.value()->getdiscount()),1000));
              ui->tableWidget->setItem(j,5,new QTableWidgetItem(QString("%1").arg(hotelInfo[i.value()->gethotelName()]->getassessment()),1000));

              j++;
            }
             i++;
         }


}



CustomerDialog::~CustomerDialog()
{
    delete ui;
}

void CustomerDialog::neworder()
{
    refreshmyordertable();
}

void CustomerDialog::newhotegrade()
{
    refreshroomtableall();
}


void CustomerDialog::on_pushButton_clicked()
{
    refreshroomtable1();
}

void CustomerDialog::on_pushButton_5_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="待接单")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("已取消订单");
      refreshmyordertable();
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

void CustomerDialog::on_pushButton_6_clicked()
{
    int rowindex=ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
  {
     if(orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->getprogress()=="已接单")
    {
      orderInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setprogress("申请退款");
      refreshmyordertable();
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

void CustomerDialog::on_pushButton_7_clicked()
{
    CustomerUsedOrderDialog dlg11;
    connect(&dlg11,SIGNAL(backfreshhotel()),this,SLOT(newhotegrade()));
    dlg11.exec();
}

void CustomerDialog::on_pushButton_2_clicked()
{
    refreshroomtable2();
}

void CustomerDialog::refreshroomtable1()
{
     QHash<QString,Room*> roomInfoCity;//找出这个城市的可卖roomInfoCity
      QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();
    if(!ui->lineEdit->text().isEmpty()) //输入城市了的
    {      
        while (i != roomInfo.constEnd())
        {
            if(hotelInfo[i.value()->gethotelName()]->getcity()==ui->lineEdit->text()&&i.value()->getsellable()==true)
            {
                roomInfoCity[i.value()->getroomID()]=i.value();//存疑，debug时注意，把QVariant给Room*！！！！！
            }
            i++;
        }
     }
    else
    {
        int j=0;
        while (i != roomInfo.constEnd())
        {
            if(i.value()->getsellable()==true)
            {
                qDebug()<<j++;
                roomInfoCity[i.value()->getroomID()]=i.value();//存疑，debug时注意，把QVariant给Room*！！！！！
            }
            i++;
        }
     }


        if(!ui->checkBox->isChecked())//不只看优惠の
        {
            refreshtable(roomInfoCity,ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex());
        }



        else//只看优惠の
        {
             //再在本城市找一下有优惠的
            QHash<QString,Room*> roomInfoCityDiscount;//找出这个城市的roomInfoCity
            QHash<QString, Room*>::const_iterator q = roomInfoCity.constBegin();
            while (q != roomInfoCity.constEnd())
            {
                if(q.value()->getdiscount()<10)
                {
                    roomInfoCityDiscount[q.value()->getroomID()]=q.value();//存疑，debug时注意，把QVariant给Room*！！！！！
                }
                q++;
            }

            refreshtable(roomInfoCityDiscount,ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex());

        }


}

void CustomerDialog::refreshtable(QHash<QString, Room *> roomInfo1, int a, int b)
{
    ui->tableWidget->setRowCount(uproomNum());
    ui->tableWidget->setColumnCount(6);

    QHeaderView* headerView = ui->tableWidget->verticalHeader();

    headerView->setHidden(true); //行名隐藏
        QStringList header;
        header.append(QObject::tr("酒店"));
        header.append(QObject::tr("酒店地址"));
        header.append(QObject::tr("房型"));
        header.append(QObject::tr("价格"));
        header.append(QObject::tr("折扣"));
        header.append(QObject::tr("酒店评分"));
        ui->tableWidget->setHorizontalHeaderLabels(header);
        qDebug()<<"更新后共有该城市房间商品种类"<<uproomNum()<<"种"<<endl;
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
         ui->tableWidget->setFocusPolicy(Qt::NoFocus);



         //1先把QHash拷到QMap上好排序
        QHash<QString, Room*>::const_iterator i0=roomInfo1.constBegin();
         int j0=0;
        QMap<int,Room*>copyroom;
        while(i0!=roomInfo1.constEnd())
        {
            copyroom[j0]=i0.value();
            j0++;
            i0++;
        }


        //2根据选的排序规则排好序
       if(a==0&&b==1)//酒店评分，降序
       {

           for(int i=0;i<copyroom.size();i++)
               for(int j=i;j<copyroom.size();j++)
               {
                  if(hotelInfo[copyroom[j]->gethotelName()]->getassessment()>hotelInfo[copyroom[i]->gethotelName()]->getassessment())
                  {
                      Room*temproom=copyroom[i];
                     copyroom[i]=copyroom[j];
                     copyroom[j]=temproom;
                  }
               }
       }


       else if(a==0&&b==0)//酒店评分，升序
       {

           for(int i=0;i<copyroom.size();i++)
               for(int j=i;j<copyroom.size();j++)
               {
                  if(hotelInfo[copyroom[j]->gethotelName()]->getassessment()<hotelInfo[copyroom[i]->gethotelName()]->getassessment())
                  {
                      Room*temproom=copyroom[i];
                     copyroom[i]=copyroom[j];
                     copyroom[j]=temproom;
                  }
               }
       }


       else if(a==1&&b==1)//价格，降序
       {

           for(int i=0;i<copyroom.size();i++)
               for(int j=i;j<copyroom.size();j++)
               {
                  if(copyroom[j]->getprice()>copyroom[i]->getprice())
                  {
                      Room*temproom=copyroom[i];
                     copyroom[i]=copyroom[j];
                     copyroom[j]=temproom;
                  }
               }
       }

       else if(a==1&&b==0)//价格，升序
       {

           for(int i=0;i<copyroom.size();i++)
               for(int j=i;j<copyroom.size();j++)
               {
                  if(copyroom[j]->getprice()<copyroom[i]->getprice())
                  {
                      Room*temproom=copyroom[i];
                     copyroom[i]=copyroom[j];
                     copyroom[j]=temproom;
                  }
               }
       }


       //3排好序的QMap去setitem
       for(int j=0;j<copyroom.size();j++)
       {
       ui->tableWidget->setItem(j,0,new QTableWidgetItem(copyroom[j]->gethotelName(),1000));
       ui->tableWidget->setItem(j,1,new QTableWidgetItem(hotelInfo[copyroom[j]->gethotelName()]->getlocation(),1001));
       ui->tableWidget->setItem(j,2,new QTableWidgetItem(copyroom[j]->getroomType(),1000));
       ui->tableWidget->setItem(j,3,new QTableWidgetItem(QString("%1").arg(copyroom[j]->getprice()),1000));
       ui->tableWidget->setItem(j,4,new QTableWidgetItem(QString("%1").arg(copyroom[j]->getdiscount()),1000));
       ui->tableWidget->setItem(j,5,new QTableWidgetItem(QString("%1").arg(hotelInfo[copyroom[j]->gethotelName()]->getassessment()),1000));
       }
}

void CustomerDialog::on_pushButton_3_clicked()
{
    int rowindex=ui->tableWidget->currentRow();
    if(rowindex!=-1)
    {
        QString thotel=ui->tableWidget->item(rowindex,0)->text();
        QString ttype=ui->tableWidget->item(rowindex,2)->text();
        QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();
        while (i!=roomInfo.constEnd())
      {
            if(i.value()->gethotelName()==thotel&&i.value()->getroomType()==ttype)
            {
               chosingroom=i.value()->getroomID();
               break;
            }
            i++;
      }
       DetailedInfoDialog dlg11111;
       connect(&dlg11111,SIGNAL(backrefresh()),this,SLOT(neworder()));
       dlg11111.exec();
    }
    else
    {
        QMessageBox::information(this,"注意","请先选择房间种类",QMessageBox::Yes);
    }
}

void CustomerDialog::on_pushButton_4_clicked()
{
    int rowindex=ui->tableWidget->currentRow();
    if(rowindex!=-1)
    {
        QString thotel=ui->tableWidget->item(rowindex,0)->text();
        QString ttype=ui->tableWidget->item(rowindex,2)->text();
        QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();
        while (i!=roomInfo.constEnd())
      {
            if(i.value()->gethotelName()==thotel&&i.value()->getroomType()==ttype)
            {
               chosingroom=i.value()->getroomID();
               break;
            }
            i++;
      }
      AddOrderDialog dlg111111;

      connect(&dlg111111,SIGNAL(addneworeder()),this,SLOT(neworder()));
       dlg111111.exec();

    }
    else
    {
      QMessageBox::information(this,"注意","请先选择房间种类",QMessageBox::Yes);
    }
}



void CustomerDialog::on_pushButton_8_clicked()
{
    CustomerTotalUsedDialog dlg1111111;
    dlg1111111.exec();
}

void CustomerDialog::on_pushButton_9_clicked()
{
   CustomerInfoChangeDialog dlg11111111;
   dlg11111111.exec();
}
