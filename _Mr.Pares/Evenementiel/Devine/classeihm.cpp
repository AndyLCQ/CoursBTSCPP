#include "classeihm.h"
#include "ui_classeihm.h"

classeIHM::classeIHM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classeIHM)
{
    ui->setupUi(this);
}

classeIHM::~classeIHM()
{
    delete ui;
}
