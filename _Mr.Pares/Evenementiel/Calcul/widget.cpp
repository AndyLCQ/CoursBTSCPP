#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_EditNombre_returnPressed()
{
    QString contenuZoneText;
    contenuZoneText=ui->EditNombre->text();
    float nombre;
    nombre= contenuZoneText.toFloat();


    ui->LabInverse->setNum(calcul.inverse(nombre));
}

void Widget::on_butValid_clicked()
{
    QString contenuZoneNumerateur, contenuZoneDenominateur;
    contenuZoneNumerateur = ui->EditNum->text();
    contenuZoneDenominateur = ui->EditDen->text();
    int nombreNumerateur = contenuZoneNumerateur.toInt();
    int nombreDenominateur = contenuZoneDenominateur.toInt();
    ui->LabReste->setNum(calcul.reste(nombreNumerateur, nombreDenominateur));
    ui->LabQuotient->setNum(calcul.quotient(nombreNumerateur, nombreDenominateur));
}

void Widget::on_pushButton_clicked()
{
    QString contenuZone1, contenuZone2, contenuZone3, contenuZone4;
    contenuZone1=ui->Editn1->text();
    contenuZone2=ui->Editn2->text();
    contenuZone3=ui->Editn3->text();
    contenuZone4=ui->Editn4->text();
    float contenuZ1=contenuZone1.toFloat();
    float contenuZ2=contenuZone2.toFloat();
    float contenuZ3=contenuZone3.toFloat();
    float contenuZ4=contenuZone4.toFloat();
    ui->LabMini->setNum(calcul.min(contenuZ1, contenuZ2, contenuZ3, contenuZ4));
    ui->LabMaxi->setNum(calcul.max(contenuZ1, contenuZ2, contenuZ3, contenuZ4));

}
