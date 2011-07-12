#ifndef WSTAW_H
#define WSTAW_H

#include <QDialog>
#include <QString>
namespace Ui {
    class wstaw;
}

class wstaw : public QDialog
{
    Q_OBJECT

public:
    explicit wstaw(QWidget *parent = 0);
    ~wstaw();
    void setParamName1(QString name);
    void setParamName2(QString name);
    void setParamValue1(QString value);
    void setParamValue2(QString value);
    void setText(QString text);
    void setTextName(QString text);


    QString getParamName1();
    QString getParamName2();
    QString getParamValue1();
    QString getParamValue2();
    QString getText();
    QString getTextName();

    Ui::wstaw *ui;
signals:
    void sygnalOk();
    void sygnalCancel();
public slots:
    void slotOk();
    void slotCancel();
};

#endif // WSTAW_H
