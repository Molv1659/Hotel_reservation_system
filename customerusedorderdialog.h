#ifndef CUSTOMERUSEDORDERDIALOG_H
#define CUSTOMERUSEDORDERDIALOG_H

#include <QDialog>

namespace Ui {
class CustomerUsedOrderDialog;
}

class CustomerUsedOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerUsedOrderDialog(QWidget *parent = 0);
    void refreshmyusedorder();
    ~CustomerUsedOrderDialog();
signals:
    void backfreshhotel();
private slots:
    void refreshmusedorder();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CustomerUsedOrderDialog *ui;
};

#endif // CUSTOMERUSEDORDERDIALOG_H
