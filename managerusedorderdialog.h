#ifndef MANAGERUSEDORDERDIALOG_H
#define MANAGERUSEDORDERDIALOG_H

#include <QDialog>

namespace Ui {
class ManagerUsedOrderDialog;
}

class ManagerUsedOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerUsedOrderDialog(QWidget *parent = 0);
    void refreshusedordertable();
    ~ManagerUsedOrderDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ManagerUsedOrderDialog *ui;
};

#endif // MANAGERUSEDORDERDIALOG_H
