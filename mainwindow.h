#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <text.h>
#include <QTextDocument>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTextDocument *doc;
QString textWstaw;
    wstaw okno;
private slots:
  //sloty od menu aplikacji. Nazwy generowane przez Qt Designer
    void on_actionNowy_triggered(); //slot wybrania z menu "Nowy Szablon"
    void on_actionZapisz_triggered(); //slot wybrania "Zapisz"
  //sloty od przycisków funkcyjnych w sekcji WSTAW
    void on_przerwaButton_clicked();
    void on_podbicieButton_clicked();
  //slot przysisku OK w oknie dialogowym - jest to slot sygna³u zewnêtrznego zdefinownego
  //przez urzytkownika - nie implementuje go klasa QDialog
    void slotOknoOk();
};

#endif // MAINWINDOW_H
