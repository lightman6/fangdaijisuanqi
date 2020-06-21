#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"win1.h"
#include"win2.h"
#include"win3.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    win1 *a;
    win2 *b;
    win3 *c;
};
#endif // WIDGET_H
