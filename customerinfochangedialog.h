#ifndef CUSTOMERINFOCHANGEDIALOG_H
#define CUSTOMERINFOCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
class CustomerInfoChangeDialog;
}

class CustomerInfoChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerInfoChangeDialog(QWidget *parent = 0);
    ~CustomerInfoChangeDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CustomerInfoChangeDialog *ui;
};

#endif // CUSTOMERINFOCHANGEDIALOG_H
