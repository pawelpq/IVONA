/********************************************************************
*AUTOR: pawelpq(pawelpq@gmail.com)
*DATA: lipiec 2011
*
*Klasa okna dialogowego do wstawiania parametrów z wykorzystaniem klasy QDialog
*
********************************************************************/
#include "wstaw.h"
#include "ui_wstaw.h"
#include <QMessageBox>

wstaw::wstaw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wstaw)
{
    ui->setupUi(this);
/* £¹czy sygna³ z przycisku OK okna formularza z funkcj¹ slotu w tej¿e klasie */
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(slotOk()));
/*£¹czy sygna³ klikniêcia od przycisku 'Anuluj'  z funkcja slotu */
    connect(ui->anuluj,SIGNAL(clicked()),this,SLOT(slotCancel()));
}

wstaw::~wstaw()
{
    delete ui;

}
/************  Funkcje SET/GET **********************
*Konwencja nazewnicza:
*set/getParamNameX - pobiera/wstawia tekst w etykiecie(label) X po lewej stronie paska tekstowego
                     Etykiety numerowane od góry. Pierwsza etykieta to 0.
                     etykieta i pole tekstowe "fraza" NIE jest parametrem
*set/getParamValueX - pobiera/wstawia wartoœæ parametru z pola tekstowego X
                      NIE dotyczy frazy
*set/getText - pobiera/wstawia tekst z pola tekstowego odpowiedzilnego za fraze do której
               wstawiane s¹ parametry
*set/getTextName -pobiera/wstawia etykiete "frazy" (label pierwszy od góry)
******************************************************/
void wstaw::setParamName1(QString name){
    ui->paramName1->setText(name);
}

void wstaw::setParamName2(QString name){
    ui->paramName2->setText(name);
}

void wstaw::setParamValue1(QString value){
    ui->paramValue1->setText(value);
}

void wstaw::setParamValue2(QString value){
    ui->paramValue2->setText(value);
}

void wstaw::setTextName(QString text){
    ui->labelText->setText(text);
}
void wstaw::setText(QString text){
    ui->text->setText(text);
}

QString wstaw::getParamName1(){
  return ui->paramName1->text();
}

QString wstaw::getParamName2(){
    return ui->paramName2->text();
}

QString wstaw::getParamValue1(){
    return ui->paramValue1->text();
}

QString wstaw::getParamValue2(){
    return ui->paramValue2->text();
}
QString wstaw::getTextName(){
    return ui->labelText->text();
}

QString wstaw::getText(){
    return ui->text->text();
}
/*******************************************
  Funkcje slotów dla sygna³u clicked() z przycisków "ok" i "Anuluj"
  Same funkcje slotów zawieraja sygna³y wybrowadzane na zewn¹trz klasy
  Dodatkowo slotCancel zamyka okno dialogowe
 *******************************************/

void wstaw::slotOk(){
    emit sygnalOk();
}

void wstaw::slotCancel(){
    emit sygnalCancel();
    close();
}
