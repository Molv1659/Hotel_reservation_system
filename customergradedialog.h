#ifndef CUSTOMERGRADEDIALOG_H
#define CUSTOMERGRADEDIALOG_H

#include <QDialog>

namespace Ui {
class CustomerGradeDialog;
}

class CustomerGradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerGradeDialog(QWidget *parent = 0);
    ~CustomerGradeDialog();

signals:
    void gradenew();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CustomerGradeDialog *ui;
};

#endif // CUSTOMERGRADEDIALOG_H
