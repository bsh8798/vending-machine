#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeButtonState();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::changeMoney(int value) {
    money += value;
    ui->lcdNumber->display(money);
    changeButtonState();
}

void Widget::changeButtonState() {
    ui->pbCoffie->setEnabled(100 <= money);
    ui->pbMilkCoffie->setEnabled(150 <= money);
    ui->pbTea->setEnabled(200 <= money);
    ui->pbReset->setEnabled(0 < money);
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}
void Widget::on_pb50_clicked()
{
    changeMoney(50);
}
void Widget::on_pb100_clicked()
{
    changeMoney(100);
}
void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffie_clicked()
{
    changeMoney(-100);
}
void Widget::on_pbMilkCoffie_clicked()
{
    changeMoney(-150);
}
void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int moneys[4] = {500, 100, 50, 10};
    int cash[4] = {0, 0, 0, 0};
    QString message = QString("");

    for(int i = 0; i < sizeof(moneys)/sizeof(moneys[0]); i++) {
        cash[i] = money / moneys[i];
        money %= moneys[i];

        if(cash[i] != 0) {
            message += QString("%1won - %2\n")
                           .arg(moneys[i])
                           .arg(cash[i]);
        }
    }

    QMessageBox mb;
    mb.information(this, "Return money", message);
    changeMoney(-money);
}

