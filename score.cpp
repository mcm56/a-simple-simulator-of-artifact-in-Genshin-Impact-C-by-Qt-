#include "score.h"
#include "ui_score.h"

#include"work.h"

score::score(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::score)
{
    ui->setupUi(this);
}

score::~score()
{
    delete ui;
}

QString fu_ming[10] = { "小生命" ,"小攻击" ,"小防御" ,"大生命","大攻击" ,"大防御","暴击","爆伤" ,"精通","充能" };

                      double quan0,quan1,quan2,quan3,quan4,quan5,quan6,quan7,quan8,quan9;
//圣遗物评分计算方法中的类型权重。

QString fun_fens[4];
//用于显示圣遗物副词条数值的string类变量。

QString fuw_fens[4]={"123","123","123","123"};
//用于显示圣遗物副词条名称的string类变量。


double fen_num[4];
//记录圣遗物副词条数值的double类变量。
int fen_lei[4];
//记录圣遗物副词条代号的int类变量。

double e1 = 0;
double e2 = 0;
double e3 = 0;
double e4 = 0;
vector<double>fen = { e1,e2,e3,e4 };
//记录圣遗物各词条得分的vector数组和double变量。

double zongfen = 0;
//记录圣遗物总分的double变量。

QString changed1(double b);

QString changed3(int b);

void score::get(double*send_fu_num){
    for(int i=0;i<4;i++){
        fen_num[i]=send_fu_num[i];
    }
}

//get函数用于从widget.cpp中提取fu_num并赋给fen_num变量。

void score::get1(int*send_fu_sy){

    for(int i=0;i<4;i++){
        fen_lei[i]=send_fu_sy[i];
    }
}
//get1函数用于从widget.cpp中提取fu_sy并赋给fen_lei变量。

void score::on_xianshi_clicked()
{
    for(int i=0;i<4;i++){
        fun_fens[i]=changed1(fen_num[i]);
    }
    for(int i=0;i<4;i++){
        int a=fen_lei[i];
        fuw_fens[i]=fu_ming[a];
    }
    ui->fenn1->setText(fun_fens[0]);
    ui->fenn2->setText(fun_fens[1]);
    ui->fenn3->setText(fun_fens[2]);
    ui->fenn4->setText(fun_fens[3]);
    ui->fenw1->setText(fuw_fens[0]);
    ui->fenw2->setText(fuw_fens[1]);
    ui->fenw3->setText(fuw_fens[2]);
    ui->fenw4->setText(fuw_fens[3]);
}

/*显示按钮可以将fen_num变为字符串，根据fen_lei的值从fu_ming中获得相应的字符串fuw_fens，并输出当前副词条名称和数值*/

void score::on_gongji_c_toggled(bool checked)
{
    quan0=0;
    quan1=0.75;
    quan2=0;
    quan3=0;
    quan4=0.75;
    quan5=0;
    quan6=1;
    quan7=1;
    quan8=0;
    quan9=0;
}

void score::on_shengming_c_toggled(bool checked)
{
    quan0=0.8;
    quan1=0.5;
    quan2=0;
    quan3=0.8;
    quan4=0.5;
    quan5=0;
    quan6=1;
    quan7=1;
    quan8=0.75;
    quan9=0;
}

void score::on_fangyu_c_toggled(bool checked)
{
    quan0=0;
    quan1=0.5;
    quan2=1;
    quan3=0;
    quan4=0.5;
    quan5=1;
    quan6=1;
    quan7=1;
    quan8=0;
    quan9=0.3;
}

void score::on_jingtong_c_toggled(bool checked)
{
    quan0=0;
    quan1=0.75;
    quan2=0;
    quan3=0;
    quan4=0.75;
    quan5=0;
    quan6=1;
    quan7=1;
    quan8=1;
    quan9=0.55;
}

void score::on_shengming_fu_toggled(bool checked)
{
    quan0=1;
    quan1=0.5;
    quan2=0;
    quan3=1;
    quan4=0.5;
    quan5=0;
    quan6=0.5;
    quan7=0.5;
    quan8=0;
    quan9=0.75;
}

void score::on_fangyu_fu_toggled(bool checked)
{
    quan0=0;
    quan1=0;
    quan2=1;
    quan3=0;
    quan4=0;
    quan5=1;
    quan6=0.5;
    quan7=0.5;
    quan8=0;
    quan9=0.9;
}

void score::on_chongneng_fu_toggled(bool checked)
{
    quan0=1;
    quan1=0.5;
    quan2=0;
    quan3=1;
    quan4=0.5;
    quan5=0;
    quan6=0.5;
    quan7=0.5;
    quan8=0;
    quan9=0.9;
}
//根据单选框的选择不同，为quan1-quan9赋不同的值。

void score::on_pingfen_clicked()
{
    double zongfen = 0;
    for (int i = 0; i < 4; i++) {
        switch (fen_lei[i]) {
        case 0:
            fen[i] = fen_num[i] * 0.026 * 0.66 * quan0;
            break;
            //小生命得分。
        case 1:
            fen[i] = fen_num[i] * 0.398 *0.5* quan1;
            break;
            //小攻击得分。
        case 2:
            fen[i] = fen_num[i] * 0.335 * 0.66*quan2;
            break;
            //小防御得分。
        case 3:
            fen[i] = fen_num[i] * 1.33 * quan3;
            break;
            //大生命得分。
        case 4:
            fen[i] = fen_num[i] * 1.33 * quan4;
            break;
            //大攻击得分。
        case 5:
            fen[i] = fen_num[i] * 1.06*quan5;
            break;
            //大防御得分。
        case 6:
            fen[i] = fen_num[i] * 2*quan6;
            break;
            //暴击得分。
        case 7:
            fen[i] = fen_num[i]*1*quan7;
            break;
            //爆伤得分。
        case 8:
            fen[i] = fen_num[i] * 0.33 * quan8;
            break;
            //精通得分。
        case 9:
            fen[i] = fen_num[i] * 1.1979 * quan9;
            break;
            //充能得分。
        }
        zongfen += fen[i];
    }
    //评分原则：副词条数值进行相应操作后与对应权重相乘得到每个副词条分数fen[i]，后四个分数相加得到总分zongfen。

    QString fens[4];
    QString zongfens=QString::number(zongfen,'f',1);
    //将double型变量zongfen改为输出1位小数的string型变量zongfens。
    for(int i=0;i<4;i++){
        // fens[i]=changed1(fen[i]);
        QString a=QString::number(fen[i],'f',1);
        fens[i]=a;
        //借助中间变量a将double型变量fen[i]改为输出1位小数的string型变量fen[i]。

    }
    ui->fen1->setText(fens[0]);
    ui->fen2->setText(fens[1]);
    ui->fen3->setText(fens[2]);
    ui->fen4->setText(fens[3]);
    ui->fen_xianshi->setText(zongfens);
    zongfen=0;
    //每次评分完后，将后台的数据zongfen归零。
}



void score::on_outfen_clicked()
{
    close();
}

