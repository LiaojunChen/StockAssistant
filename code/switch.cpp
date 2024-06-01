#include "switch.h"
#include "ui_switch.h"
#include "getstock.h"
#include"SQLstock.h"
Switch::Switch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Switch)
{
    ui->setupUi(this);
}

Switch::~Switch()
{
    delete ui;
}
//研究一下combo box里面怎么加入已有的对象
