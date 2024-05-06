#ifndef SCORE_H
#define SCORE_H

#include <QDialog>
#include <QTextBrowser>
#include<QPushButton>
#include<Qstring>
#include <QTextStream>

namespace Ui {
class score;
}

class score : public QDialog
{
    Q_OBJECT

public:
    explicit score(QWidget *parent = nullptr);
    ~score();

private slots:
    void on_pingfen_clicked();

    void on_xianshi_clicked();

    void on_gongji_c_toggled(bool checked);

    void on_shengming_c_toggled(bool checked);

    void on_fangyu_c_toggled(bool checked);

    void on_jingtong_c_toggled(bool checked);

    void on_shengming_fu_toggled(bool checked);

    void on_fangyu_fu_toggled(bool checked);

    void on_chongneng_fu_toggled(bool checked);

    void on_buttonBox_accepted();

    void on_outfen_clicked();

public slots:
    void get(double*send_fu_num);
    //public槽函数，用于接收信号

    void get1(int*send_fu_sy);
    //public槽函数

private:
    Ui::score *ui;
    QTextBrowser*fenw1;
    QTextBrowser*fenw2;
    QTextBrowser*fenw3;
    QTextBrowser*fenw4;
    QTextBrowser*fenn1;
    QTextBrowser*fenn2;
    QTextBrowser*fenn3;
    QTextBrowser*fenn4;
    QTextBrowser*fen1;
    QTextBrowser*fen2;
    QTextBrowser*fen3;
    QTextBrowser*fen4;
    QTextBrowser*xianshi;

};

#endif // SCORE_H
