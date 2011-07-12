#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    doc=new QTextDocument();
    doc->setPlainText("pawelpqpqp");
    //zwi¹zanie wska¿nika na egzemplarz klasy QTextDocument z oknem GUI
    //zmiany poczynione w oknie aktulizuja doc
    ui->textEdit->setDocument(doc);

    connect(&okno,SIGNAL(sygnalOk()),this,SLOT(slotOknoOk()));

   }

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_actionZapisz_triggered()
{
    QFile file("in.txt");
       if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
           return;
       QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();

}

void MainWindow::on_actionNowy_triggered()
{
    QFile szablon("szablon.txt");
    if (!szablon.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            doc->setPlainText("B³¹d odczytu szablonu");
    }
        else{
            QTextStream out(&szablon);
            ui->textEdit->setPlainText(out.readAll());
          }
}


void MainWindow::slotOknoOk(){

   textWstaw=QString(okno.getText()).arg(okno.getParamValue1().toInt());
   //Wstawienie tekstu w miejsu na które wskazuje kursor
     ui->textEdit->textCursor().insertText(textWstaw);
     okno.close();
}

void MainWindow::on_przerwaButton_clicked()
{
    okno.setWindowTitle(tr("Przerwa"));
    okno.setParamName1(tr("Czas:"));
    okno.setText(tr("<break time=\" %1s\"/>"));
    okno.exec();
}

void MainWindow::on_podbicieButton_clicked()
{
    okno.exec();
}
