#ifndef ADDORDERDIALOG_H
#define ADDORDERDIALOG_H

#include <QDialog>

namespace Ui {
class AddOrderDialog;
}

class AddOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrderDialog(QWidget *parent = 0);
    ~AddOrderDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
signals:
    void addneworeder();
private:
    Ui::AddOrderDialog *ui;
};

#endif // ADDORDERDIALOG_H
