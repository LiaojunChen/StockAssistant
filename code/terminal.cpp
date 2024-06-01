#include "terminal.h"
#include "ui_terminal.h"
#include "getstock.h"
#include"SQLstock.h"
Terminal::Terminal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Terminal)
{
    ui->setupUi(this);
}

Terminal::~Terminal()
{
    delete ui;
}

void Terminal::on_pushButton_clicked()
{
    this->close();
}
//需要根据情况在框内输出操作执行是否成功
