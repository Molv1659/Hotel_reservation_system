#ifndef CUSTOMERTOTALUSEDDIALOG_H
#define CUSTOMERTOTALUSEDDIALOG_H

#include <QDialog>

namespace Ui {
class CustomerTotalUsedDialog;
}

class CustomerTotalUsedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerTotalUsedDialog(QWidget *parent = 0);
    ~CustomerTotalUsedDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CustomerTotalUsedDialog *ui;
};

#endif // CUSTOMERTOTALUSEDDIALOG_H
