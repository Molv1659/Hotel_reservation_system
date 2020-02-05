#include "platformdialog.h"
#include "ui_platformdialog.h"
#include"hotel.h"
#include"room.h"
#include<QDebug>
#include<QMessageBox>
extern QHash<QString,Hotel*> hotelInfo;//hotelID
extern QHash<QString,Room*> roomInfo;
int hotelNum()
{
    int num=0;
    QHash<QString, Hotel*>::const_iterator i = hotelInfo.constBegin();

    while (i != hotelInfo.constEnd())
    {
        num++;
        i++;
    }
    return (num);
}
int roomNum()
{
    int num=0;
    QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

    while (i != roomInfo.constEnd())
    {
        num++;
        i++;
    }
    return (num);
}

void PlatformDialog::refreshhoteltable()
{
    ui->tableWidget->setRowCount(hotelNum());
   qDebug()<<"有酒店"<<hotelNum()<<"家";
    ui->tableWidget->setColumnCount(4);

    QHeaderView* headerView = ui->tableWidget->verticalHeader();

    headerView->setHidden(true); //行名隐藏
    QStringList header;
    header.append(QObject::tr("酒店名"));
    header.append(QObject::tr("酒店地址"));
    header.append(QObject::tr("酒店电话"));
    header.append(QObject::tr("运营许可"));
    ui->tableWidget->setHorizontalHeaderLabels(header);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    int j=0;

    QHash<QString, Hotel*>::const_iterator i = hotelInfo.constBegin();

    while (i != hotelInfo.constEnd())
    {

       ui->tableWidget->setItem(j,0,new QTableWidgetItem(i.value()->gethotelID(),1000));
       ui->tableWidget->setItem(j,1,new QTableWidgetItem(i.value()->getlocation(),1001));
       ui->tableWidget->setItem(j,2,new QTableWidgetItem(i.value()->gettelephone(),1002));
       QString booltext=i.value()->getworkable()? "true" : "false";
       ui->tableWidget->setItem(j,3,new QTableWidgetItem(booltext,1003));
       j++;

      i++;
    }
}

void PlatformDialog::refreshroomtable()
{
    ui->tableWidget_2->setRowCount(roomNum());
   qDebug()<<"有房间"<<roomNum()<<"种";
    ui->tableWidget_2->setColumnCount(6);

    QHeaderView* headerView = ui->tableWidget_2->verticalHeader();

    headerView->setHidden(true); //行名隐藏
    QStringList header;
    header.append(QObject::tr("房间代号"));
    header.append(QObject::tr("酒店名"));
    header.append(QObject::tr("价格"));
    header.append(QObject::tr("房型"));
    header.append(QObject::tr("总数量"));
    header.append(QObject::tr("销售许可"));
    ui->tableWidget_2->setHorizontalHeaderLabels(header);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    int j=0;

    QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

    while (i != roomInfo.constEnd())
    {
       ui->tableWidget_2->setItem(j,0,new QTableWidgetItem(i.value()->getroomID(),999));
       ui->tableWidget_2->setItem(j,1,new QTableWidgetItem(i.value()->gethotelName(),1000));
       ui->tableWidget_2->setItem(j,2,new QTableWidgetItem(QString("%1").arg(i.value()->getprice()),1001));
       ui->tableWidget_2->setItem(j,3,new QTableWidgetItem(i.value()->getroomType(),1002));
       ui->tableWidget_2->setItem(j,4,new QTableWidgetItem(QString("%1").arg(i.value()->gettotalNum()),1003));
       QString booltext=i.value()->getsellable()? "true":"false";
       ui->tableWidget_2->setItem(j,5,new QTableWidgetItem(booltext,1004));

       j++;

      i++;
    }
}

PlatformDialog::PlatformDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlatformDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Platform");
   refreshroomtable();
   refreshhoteltable();
}

PlatformDialog::~PlatformDialog()
{
    delete ui;
}

void PlatformDialog::on_pushButton_clicked()
{
   int rowindex= ui->tableWidget->currentRow();
   qDebug()<<rowindex;
   if(rowindex!=-1)
   {
     hotelInfo[ui->tableWidget->item(rowindex,0)->text()]->setworkable(true);
      refreshhoteltable();
   }
   else
   {
       QMessageBox::warning(this, tr("警告！"),
                           tr("请先选择酒店"),
                           QMessageBox::Yes);
   }

}

void PlatformDialog::on_pushButton_2_clicked()
{
    int rowindex= ui->tableWidget->currentRow();
    if(rowindex!=-1)
    {
     hotelInfo[ui->tableWidget->item(rowindex,0)->text()]->setworkable(false);
      refreshhoteltable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择酒店"),
                            QMessageBox::Yes);
    }
}

void PlatformDialog::on_pushButton_3_clicked()
{
    int rowindex= ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
    {
      roomInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setsellable(true);
       refreshroomtable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择房间"),
                            QMessageBox::Yes);
    }
}

void PlatformDialog::on_pushButton_4_clicked()
{
    int rowindex= ui->tableWidget_2->currentRow();
    if(rowindex!=-1)
    {
     roomInfo[ui->tableWidget_2->item(rowindex,0)->text()]->setsellable(false);
      refreshroomtable();
    }
    else
    {
        QMessageBox::warning(this, tr("警告！"),
                            tr("请先选择房间"),
                            QMessageBox::Yes);
    }
}
