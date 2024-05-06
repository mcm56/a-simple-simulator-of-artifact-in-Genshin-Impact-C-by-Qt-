#include "ku.h"
#include "ui_ku.h"
#include"work.h"

ku::ku(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ku)
{
    ui->setupUi(this);
    ui->xuanze->setMaximum(5);
    ui->xuanze->setMinimum(1);
    connect(ui->xuanze,&QSpinBox::valueChanged,this,&ku::on_show_clicked);
    connect(ui->delete_2,&QPushButton::clicked,this,&ku::on_show_clicked);
}

ku::~ku()
{
    delete ui;
}


int xu_ku;
//其数值1-5代表了仓库位置1-5。

ku_shengyiwu ku1,ku2,ku3,ku4,ku5;
//生成5个对象作为仓库的五个位置。

int if_kong1=0;
int if_kong2=0;
int if_kong3=0;
int if_kong4=0;
int if_kong5=0;
//if_kong用于记录仓库该位置此时状态。
//初始为0，代表仓库内此时为空；1则为有。

int ku::trans1(){
    return if_kong1;
}

int ku::trans2(){
    return if_kong2;
}

int ku::trans3(){
    return if_kong3;
}

int ku::trans4(){
    return if_kong4;
}

int ku::trans5(){
    return if_kong5;
}
//trans函数用于将ku.cpp中的if_kong变量导入widget.cpp中。


QString changed1(double b);

QString fu_mings[10] = { "小生命" ,"小攻击" ,"小防御" ,"大生命","大攻击" ,"大防御","暴击","爆伤" ,"精通","充能" };


QString lei;
//显示圣遗物类型的string变量。

QString zhuword;
//显示圣遗物主词条名称的string变量。

QString zhunumber;
//显示圣遗物主词条数值的string变量。

double ku_fu_num[4];
//记录圣遗物副词条数值的double变量。

QString ku_fu_nums[4];
//显示圣遗物副词条数值的string变量。

int ku_fu_sy[4];
//记录圣遗物副词条代号的int变量。

QString ku_fu_word[4];
//显示圣遗物副词条名称的string变量。

void ku::get_ku6(int time){
    xu_ku=time;
}
//get_ku6函数用于从widget.cpp中提取变量xu的值并将其赋给xu_ku。

void ku::get_ku1(int send_zhu_lei){
    switch(send_zhu_lei){
    case 1:
        lei="死之羽";
        break;
    case 2:
        lei="生之花";
        break;
    case 3:
        lei="时之沙";
        break;
    case 4:
        lei="理之冠";
        break;
    case 5:
        lei="空之杯";
        break;
}
    switch(xu_ku){
    case 1:
        ku1.zhu_lei=lei;
        if_kong1=1;
        break;
    case 2:
        ku2.zhu_lei=lei;
        if_kong2=1;
        break;
    case 3:
        ku3.zhu_lei=lei;
        if_kong3=1;
        break;
    case 4:
        ku4.zhu_lei=lei;
        if_kong4=1;
        break;
    case 5:
        ku5.zhu_lei=lei;
        if_kong5=1;
        break;
    }
}
/*ku_get1函数用于从widget.cpp中提取a5，根据其数值赋给lei相应的字符串，后switch将根据xu_ku的数值决定将lei赋给某对象的zhu_lei数据成员，并将对应的if_kong改为状态为满。*/

void ku::get_ku2(QString send_zhu_word){
    zhuword=send_zhu_word;
    switch(xu_ku){
    case 1:
        ku1.zhu_word=zhuword;
        break;
    case 2:
        ku2.zhu_word=zhuword;
        break;
    case 3:
        ku3.zhu_word=zhuword;
        break;
    case 4:
        ku4.zhu_word=zhuword;
        break;
    case 5:
        ku5.zhu_word=zhuword;
        break;
    }
}
/*ku_get2函数以zhuword为中间变量将widget.cpp中的mainword_ku变量提取出来，并用switch根据xu_ku的数值决定将zhuword赋给某对象的zhu_word数据成员。*/

void ku::get_ku3(QString send_zhu_num){
    zhunumber=send_zhu_num;
    switch(xu_ku){
    case 1:
        ku1.zhu_number=zhunumber;
        break;
    case 2:
        ku2.zhu_number=zhunumber;
        break;
    case 3:
        ku3.zhu_number=zhunumber;
        break;
    case 4:
        ku4.zhu_number=zhunumber;
        break;
    case 5:
        ku5.zhu_number=zhunumber;
        break;
    }
}
/*ku_get3函数以zhunumber为中间变量将widget.cpp中的mainnumber_ku变量提取出来，并用switch根据xu_ku的数值决定将zhunumber赋给某对象的zhu_number数据成员。*/

void ku::get_ku4(double*send_fu_num){
    for(int i=0;i<4;i++){
        ku_fu_num[i]=send_fu_num[i];
    }
    for(int i=0;i<4;i++){
        ku_fu_nums[i]=changed1(ku_fu_num[i]);
    }
    switch(xu_ku){
    case 1:
        for(int i=0;i<4;i++){
            ku1.fun[i]=ku_fu_nums[i];
        }
        break;
    case 2:
        for(int i=0;i<4;i++){
            ku2.fun[i]=ku_fu_nums[i];
        }
        break;
    case 3:
        for(int i=0;i<4;i++){
            ku3.fun[i]=ku_fu_nums[i];
        }
        break;
    case 4:
        for(int i=0;i<4;i++){
            ku4.fun[i]=ku_fu_nums[i];
        }
        break;
    case 5:
        for(int i=0;i<4;i++){
            ku5.fun[i]=ku_fu_nums[i];
        }
        break;
    }
}
/*ku_get4函数以ku_fu_num为中间变量将widget.cpp中的fu_num变量提取出来，接着用changed1函数将其转为string类型的ku_fu_nums，并用switch根据xu_ku的数值决定将ku_fu_nums赋给某对象的fun数据成员。*/

void ku::get_ku5(int*send_fu_sy){
    for(int i=0;i<4;i++){
        ku_fu_sy[i]=send_fu_sy[i];
    }
    for(int i=0;i<4;i++){
        int a=ku_fu_sy[i];
        ku_fu_word[i]=fu_mings[a];
    }
    switch(xu_ku){
    case 1:
        for(int i=0;i<4;i++){
            ku1.fuw[i]=ku_fu_word[i];
        }
        break;
    case 2:
        for(int i=0;i<4;i++){
            ku2.fuw[i]=ku_fu_word[i];
        }
        break;
    case 3:
        for(int i=0;i<4;i++){
            ku3.fuw[i]=ku_fu_word[i];
        }
        break;
    case 4:
        for(int i=0;i<4;i++){
            ku4.fuw[i]=ku_fu_word[i];
        }
        break;
    case 5:
        for(int i=0;i<4;i++){
            ku5.fuw[i]=ku_fu_word[i];
        }
        break;
    }
}
/*ku_get5函数以ku_fu_sy为中间变量将widget.cpp中的fu_sy变量提取出来，根据fu_sy的值从fu_ming中获得相应的字符串ku_fu_word，并用switch根据xu_ku的数值决定将ku_fu_word赋给某对象的fuw数据成员。*/


void ku::on_show_clicked()
{
    switch(ui->xuanze->value()){
    case 1:
        ui->ku_lei->setText(ku1.zhu_lei);
        ui->ku_zhucitiao->setText(ku1.zhu_word);
        ui->ku_zhucitiao_number->setText(ku1.zhu_number);
        ui->ku_fun1->setText(ku1.fun[0]);
        ui->ku_fun2->setText(ku1.fun[1]);
        ui->ku_fun3->setText(ku1.fun[2]);
        ui->ku_fun4->setText(ku1.fun[3]);
        ui->ku_fuw1->setText(ku1.fuw[0]);
        ui->ku_fuw2->setText(ku1.fuw[1]);
        ui->ku_fuw3->setText(ku1.fuw[2]);
        ui->ku_fuw4->setText(ku1.fuw[3]);
        break;
    case 2:
        ui->ku_lei->setText(ku2.zhu_lei);
        ui->ku_zhucitiao->setText(ku2.zhu_word);
        ui->ku_zhucitiao_number->setText(ku2.zhu_number);
        ui->ku_fun1->setText(ku2.fun[0]);
        ui->ku_fun2->setText(ku2.fun[1]);
        ui->ku_fun3->setText(ku2.fun[2]);
        ui->ku_fun4->setText(ku2.fun[3]);
        ui->ku_fuw1->setText(ku2.fuw[0]);
        ui->ku_fuw2->setText(ku2.fuw[1]);
        ui->ku_fuw3->setText(ku2.fuw[2]);
        ui->ku_fuw4->setText(ku2.fuw[3]);
        break;
    case 3:
        ui->ku_lei->setText(ku3.zhu_lei);
        ui->ku_zhucitiao->setText(ku3.zhu_word);
        ui->ku_zhucitiao_number->setText(ku3.zhu_number);
        ui->ku_fun1->setText(ku3.fun[0]);
        ui->ku_fun2->setText(ku3.fun[1]);
        ui->ku_fun3->setText(ku3.fun[2]);
        ui->ku_fun4->setText(ku3.fun[3]);
        ui->ku_fuw1->setText(ku3.fuw[0]);
        ui->ku_fuw2->setText(ku3.fuw[1]);
        ui->ku_fuw3->setText(ku3.fuw[2]);
        ui->ku_fuw4->setText(ku3.fuw[3]);
        break;
    case 4:
        ui->ku_lei->setText(ku4.zhu_lei);
        ui->ku_zhucitiao->setText(ku4.zhu_word);
        ui->ku_zhucitiao_number->setText(ku4.zhu_number);
        ui->ku_fun1->setText(ku4.fun[0]);
        ui->ku_fun2->setText(ku4.fun[1]);
        ui->ku_fun3->setText(ku4.fun[2]);
        ui->ku_fun4->setText(ku4.fun[3]);
        ui->ku_fuw1->setText(ku4.fuw[0]);
        ui->ku_fuw2->setText(ku4.fuw[1]);
        ui->ku_fuw3->setText(ku4.fuw[2]);
        ui->ku_fuw4->setText(ku4.fuw[3]);
        break;
    case 5:
        ui->ku_lei->setText(ku5.zhu_lei);
        ui->ku_zhucitiao->setText(ku5.zhu_word);
        ui->ku_zhucitiao_number->setText(ku5.zhu_number);
        ui->ku_fun1->setText(ku5.fun[0]);
        ui->ku_fun2->setText(ku5.fun[1]);
        ui->ku_fun3->setText(ku5.fun[2]);
        ui->ku_fun4->setText(ku5.fun[3]);
        ui->ku_fuw1->setText(ku5.fuw[0]);
        ui->ku_fuw2->setText(ku5.fuw[1]);
        ui->ku_fuw3->setText(ku5.fuw[2]);
        ui->ku_fuw4->setText(ku5.fuw[3]);
        break;
    }
}
//根据滚轮xuanze的1-5的值，分别显示仓库中1-5位置的数据。

void ku::on_delete_2_clicked()
{
    switch(ui->xuanze->value()){
    case 1:
        if(if_kong1==1){
            ku1.zhu_lei=" ";
            ku1.zhu_word=" ";
            ku1.zhu_number=" ";
            ku1.fun[0]=" ";
            ku1.fun[1]=" ";
            ku1.fun[2]=" ";
            ku1.fun[3]=" ";
            ku1.fuw[0]=" ";
            ku1.fuw[1]=" ";
            ku1.fuw[2]=" ";
            ku1.fuw[3]=" ";
            if_kong1=0;
        }
        else{
            QMessageBox::information(this,"错误","该位置为空",QMessageBox::Close);
        }
        break;
    case 2:
        if(if_kong2==1){
            ku2.zhu_lei=" ";
            ku2.zhu_word=" ";
            ku2.zhu_number=" ";
            ku2.fun[0]=" ";
            ku2.fun[1]=" ";
            ku2.fun[2]=" ";
            ku2.fun[3]=" ";
            ku2.fuw[0]=" ";
            ku2.fuw[1]=" ";
            ku2.fuw[2]=" ";
            ku2.fuw[3]=" ";
            if_kong2=0;
        }
        else{
            QMessageBox::information(this,"错误","该位置为空",QMessageBox::Close);
        }
        break;
    case 3:
        if(if_kong3==1){
            ku3.zhu_lei=" ";
            ku3.zhu_word=" ";
            ku3.zhu_number=" ";
            ku3.fun[0]=" ";
            ku3.fun[1]=" ";
            ku3.fun[2]=" ";
            ku3.fun[3]=" ";
            ku3.fuw[0]=" ";
            ku3.fuw[1]=" ";
            ku3.fuw[2]=" ";
            ku3.fuw[3]=" ";
            if_kong3=0;
        }
        else{
            QMessageBox::information(this,"错误","该位置为空",QMessageBox::Close);
        }
        break;
    case 4:
        if(if_kong4==1){
            ku4.zhu_lei=" ";
            ku4.zhu_word=" ";
            ku4.zhu_number=" ";
            ku4.fun[0]=" ";
            ku4.fun[1]=" ";
            ku4.fun[2]=" ";
            ku4.fun[3]=" ";
            ku4.fuw[0]=" ";
            ku4.fuw[1]=" ";
            ku4.fuw[2]=" ";
            ku4.fuw[3]=" ";
            if_kong4=0;
        }
        else{
            QMessageBox::information(this,"错误","该位置为空",QMessageBox::Close);
        }
        break;
    case 5:
        if(if_kong5==1){
            ku5.zhu_lei=" ";
            ku5.zhu_word=" ";
            ku5.zhu_number=" ";
            ku5.fun[0]=" ";
            ku5.fun[1]=" ";
            ku5.fun[2]=" ";
            ku5.fun[3]=" ";
            ku5.fuw[0]=" ";
            ku5.fuw[1]=" ";
            ku5.fuw[2]=" ";
            ku5.fuw[3]=" ";
            if_kong5=0;
        }
        else{
            QMessageBox::information(this,"错误","该位置为空",QMessageBox::Close);
        }
        break;
    }
}
//根据滚轮xuanze的1-5的值，分别将仓库中1-5位置的数据改为“ ”，并将相应的if_kong改为0，即空。若该位置为空，即已经删过一次，if_kong为0，则跳出弹窗显示

