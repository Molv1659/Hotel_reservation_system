#ifndef CUSTOMERREGESTRATIONDLG_H
#define CUSTOMERREGESTRATIONDLG_H
#include"customer.h"
#include <QDialog>

namespace Ui {
class CustomerRegestrationDlg;
}

class CustomerRegestrationDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerRegestrationDlg(QWidget *parent = 0);
    ~CustomerRegestrationDlg();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CustomerRegestrationDlg *ui;
};

#endif // CUSTOMERREGESTRATIONDLG_H
