//有时间的话增加一个可以更改酒店信息的界面
#include "hoteldialog.h"
#include "ui_hoteldialog.h"
#include<QMessageBox>
#include"manager.h"
#include"managerregestrationdlg.h"
#include"hotelinfochangedialog.h"
#include<QDebug>
#include<QObject>
#include"hotel.h"
extern QString loginer;
extern QHash<QString,Manager*>managerInfo;
extern QHash<QString,Hotel*> hotelInfo;//hotelID
int managerNum(QString name1,QHash<QString,Manager*>managerInfo1)
{
    int s=0;
    QHash<QString, Manager*>::const_iterator i = managerInfo1.constBegin();
         while (i != managerInfo1.constEnd())

         {

             if(i.value()->getbHotelname()==name1) s++;
             i++;
         }
    return(s);
}
HotelDialog::HotelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotelDialog)
{

    ui->setupUi(this);
    this->setWindowTitle("Hotel");
    ui->lineEdit->setText(QString("%1").arg(hotelInfo[loginer]->getassessment(),1000));
    qDebug()<<"打开时有管理员"<<managerNum(loginer,managerInfo)<<"名"<<endl;
    refreshmanagertable();

}

void HotelDialog::refreshmanagertable()
{
    ui->tableWidget->setRowCount(managerNum(loginer,managerInfo));

    ui->tableWidget->setColumnCount(2);

    QHeaderView* headerView = ui->tableWidget->verticalHeader();

    headerView->setHidden(true); //行名隐藏
    QStringList header;
    header.append(QObject::tr("管理员"));
    header.append(QObject::tr("密码"));
    ui->tableWidget->setHorizontalHeaderLabels(header);
    qDebug()<<"更新后有管理员"<<managerNum(loginer,managerInfo)<<"名"<<endl;
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    int j=0;

    QHash<QString, Manager*>::const_iterator i = managerInfo.constBegin();

    while (i != managerInfo.constEnd())
    {
      if(i.value()->getbHotelname()==loginer)
        {
          ui->tableWidget->setItem(j,0,new QTableWidgetItem(i.value()->getmanagerID(),1000));
          ui->tableWidget->setItem(j,1,new QTableWidgetItem(i.value()->getmanagerPassport(),1001));
          j++;
        }
      i++;
    }
}


HotelDialog::~HotelDialog()
{
    delete ui;
}

void HotelDialog::on_pushButton_clicked()
{
   ManagerRegestrationDlg dlg11;

   dlg11.exec();


   refreshmanagertable();
}

void HotelDialog::on_pushButton_2_clicked()
{
    int rowindex=ui->tableWidget->currentRow();
    if(rowindex!=-1)
    {
        qDebug()<<rowindex;
    managerInfo.remove(ui->tableWidget->item(rowindex,0)->text());

    ui->tableWidget->removeRow(rowindex);

    refreshmanagertable();
    }
}

void HotelDialog::on_pushButton_3_clicked()
{
   HotelInfoChangeDialog dlg333;

   dlg333.exec();
}
