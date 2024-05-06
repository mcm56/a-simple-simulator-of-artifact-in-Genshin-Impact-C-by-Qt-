#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QProgressBar>
#include <QTextBrowser>
#include<QString>
#include<QTextStream>
#include<QLabel>
#include<QSpinBox>
#include<QPicture>
#include<QMessageBox>
#include"dia.h"
#include"ui_dia.h"
#include"score.h"
#include"ui_score.h"
#include"ku.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


signals:

    void send(double*send_fu_num);
    //信号的发出者，用于将词条数据输入s0

    void send1(int*send_fu_sy);
    //信号的发出者，用于将词条数值数据输入s0

    void send_ku1(int send_zhu_lei);//

    void send_ku2(QString send_zhu_word);//

    void send_ku3(QString send_zhu_num);//

    void send_ku4(double*send_fu_num);//

    void send_ku5(int*send_fu_sy);//

    void send_ku6(int time);//

private slots:

    void on_up_clicked();

    void on_createb_clicked();

    void on_cancelb_clicked();

    void on_mode2_clicked();

    void on_fen_clicked();

    void on_gaoxueye_toggled(bool checked);

    void on_zhengchang_toggled(bool checked);

    void on_haunxiang_toggled(bool checked);

    void on_genghuan_clicked();

    void on_ku_clicked();

    void on_save_clicked();


private:
    Ui::Widget *ui;
    QTextBrowser*mw;
    QTextBrowser*mn;
    QTextBrowser*fw1;
    QTextBrowser*fn1;
    QTextBrowser*fw2;
    QTextBrowser*fn2;
    QTextBrowser*fw3;
    QTextBrowser*fn3;
    QTextBrowser*fw4;
    QTextBrowser*fn4;
    QTextBrowser*name;
    QLabel*picture;
    QSpinBox*lv;
    score s0;
     ku k0;//
};
#endif // WIDGET_H
