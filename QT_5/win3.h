#ifndef WIN3_H
#define WIN3_H

#include <QDialog>

namespace Ui {
class win3;
}

class win3 : public QDialog
{
    Q_OBJECT

public:
    explicit win3(QWidget *parent = nullptr);
    ~win3();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::win3 *ui;
    double x, y, m, n, z, num1, num2, num3;
};

#endif // WIN3_H
