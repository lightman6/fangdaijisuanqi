#include "widget.h"
#include "ui_widget.h"
#include"win1.h"
#include"win2.h"
#include"win3.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    a=new win1(this);
    a->setModal(true);
    a->exec();
}

void Widget::on_pushButton_2_clicked()
{
    b=new win2(this);
    b->setModal(true);
    b->exec();
}

void Widget::on_pushButton_3_clicked()
{
    c=new win3(this);
    c->setModal(true);
    c->exec();
}
