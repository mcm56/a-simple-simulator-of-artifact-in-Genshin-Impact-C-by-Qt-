#ifndef DIA_H
#define DIA_H

#include <QDialog>
#include<QComboBox>
#include<QStringList>

namespace Ui {
class dia;
}

class dia : public QDialog
{
    Q_OBJECT

public:
    explicit dia(QWidget *parent = nullptr);
    ~dia();

    int showkind();

    int showmain();

    void tip(int a);

    void setfu(QStringList stl);

    int*showfu();

private slots:

    void on_dia_accepted();

    void on_ok1_clicked();

    void on_ok_clicked();

    void on_ok2_clicked();

    void on_pb_clicked();

    void on_out_clicked();

private:
    Ui::dia *ui;
    QComboBox*chosekind;
    QComboBox*chosemain;
    QComboBox*a1;
    QComboBox*a2;
    QComboBox*a3;
    QComboBox*a4;
};

#endif // DIA_H
