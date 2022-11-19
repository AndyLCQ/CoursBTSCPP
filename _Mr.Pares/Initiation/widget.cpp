#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
/*******************************************************************************************************/
Widget::~Widget()
{
    delete ui;
}


void Widget::on_Valider_clicked()
{
    ui->label->setText("Bienvenue");
}

void Widget::on_carre_clicked()
{
    QString contenuZoneText;
    contenuZoneText=ui->saisie->text();
    int nombre=contenuZoneText.toInt();
    nombre=nombre*nombre;
    ui->resultat->setNum(nombre);
}
