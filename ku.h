#ifndef KU_H
#define KU_H

#include <QDialog>
#include<Qstring>
#include <QTextBrowser>
#include<QPushButton>
#include <QTextStream>
#include<QSpinBox>
#include<QMessageBox>

namespace Ui {
class ku;
}

class ku : public QDialog
{
    Q_OBJECT

public:
    explicit ku(QWidget *parent = nullptr);
    ~ku();

    int trans1();
    int trans2();
    int trans3();
    int trans4();
    int trans5();

public slots:

    void get_ku1(int send_zhu_lei);

    void get_ku2(QString send_zhu_word);

    void get_ku3(QString send_zhu_num);

    void get_ku4(double*send_fu_num);

    void get_ku5(int*send_fu_sy);

    void get_ku6(int time);



private slots:

    void on_show_clicked();

    void on_delete_2_clicked();

private:
    Ui::ku *ui;
    QTextBrowser*ku_lei;
    QTextBrowser*ku_zhucitiao;
    QTextBrowser*ku_zhucitiao_number;
    QTextBrowser*ku_fun1;
    QTextBrowser*ku_fun2;
    QTextBrowser*ku_fun3;
    QTextBrowser*ku_fun4;
    QTextBrowser*ku_fuw1;
    QTextBrowser*ku_fuw2;
    QTextBrowser*ku_fuw3;
    QTextBrowser*ku_fuw4;
    QSpinBox*xuanze;

};


class ku_shengyiwu{
public:
    QString zhu_lei;
    QString zhu_word;
    QString zhu_number;
    QString fuw[4];
    QString fun[4];
};



#endif // KU_H
