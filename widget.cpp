#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    money_ = 0;
    setControl();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setControl()
{
    ui->lcdNumber->display((money_));
    ui->pbCoffee->setEnabled(money_ >= 100);
    ui->pbTea->setEnabled(money_ >= 150);
    ui->pbCola->setEnabled(money_ >= 200);
}
void Widget::on_pb500_clicked()
{
    money_ += 500;
    setControl();
}

void Widget::on_pb100_clicked()
{
    money_ += 100;
    setControl();
}

void Widget::on_pb50_clicked()
{
    money_ += 50;
    setControl();
}

void Widget::on_pb10_clicked()
{
    money_ += 10;
    setControl();
}


void Widget::on_pbCoffee_clicked()
{
    money_ -= 100;
    setControl();

}

void Widget::on_pbTea_clicked()
{
    money_ -= 150;
    setControl();

}

void Widget::on_pbCola_clicked()
{
    money_ -= 200;
    setControl();

}


void Widget::on_pbReset_clicked()
{
    c_500 = 0;
    c_100 = 0;
    c_50 = 0;
    c_10 = 0;
    c_500 = money_ / 500;
    money_ = money_ - c_500 * 500;
    c_100 = money_ / 100;
    money_ = money_ - c_100 * 100;
    c_50 = money_ / 50;
    money_ = money_ - c_50 * 50;
    c_10 = money_ / 10;
    money_ = money_ - c_10 * 10;
    QString status;
    status.sprintf("***Return***\n500: %d\n100: %d\n  50: %d\n  10: %d",c_500,c_100,c_50,c_10);
    QMessageBox::information(this,tr("Info:"),status);
    setControl();
}


