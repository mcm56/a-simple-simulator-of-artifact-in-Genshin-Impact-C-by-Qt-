#include "dia.h"
#include "qmessagebox.h"
#include "ui_dia.h"



dia::dia(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dia)
{
    ui->setupUi(this);
    QStringList addk;
    addk<<"羽"<<"花"<<"沙"<<"冠"<<"杯";
    //建立种类的QStingList变量
    ui->chosekind->addItems(addk);
    //将数据加入QComboBox选择框
    ui->chosekind->setCurrentIndex(0);
    //初始序号设置为0
    connect(ui->ok,&QPushButton::clicked,this,&dia::on_pb_clicked);
}


dia::~dia()
{
    delete ui;
}


void dia::on_dia_accepted(){

}

void dia::on_ok1_clicked()
{
    ui->chosemain->clear();
    int kind=ui->chosekind->currentIndex();
    QStringList addmain_hour;
    QStringList addmain_cup;
    QStringList addmain_head;
    addmain_hour<<"充能"<<"生命"<<"攻击"<<"防御"<<"精通";
    addmain_head<<"攻击"<<"生命"<<"防御"<<"治疗加成"<<"暴击"<<"暴伤"<<"精通";
    addmain_cup<<"火元素伤害加成"<<"冰元素伤害加成"<<"水元素伤害加成"<< "岩元素伤害加成"<<"草元素伤害加成"<<"雷元素伤害加成"<<"风元素伤害加成"
                   <<"生命"<<"攻击"<<"防御"<<"精通" <<"物理伤害加成";
    if(kind==0){
        ui->chosemain->addItem("攻击");
    }
    else if(kind==1){
        ui->chosemain->addItem("生命");
    }
    else if(kind==2){
        ui->chosemain->addItems(addmain_hour);
    }
    else if(kind==3){
        ui->chosemain->addItems(addmain_head);
    }
    else if(kind==4){
        ui->chosemain->addItems(addmain_cup);
    }
    ui->chosemain->setCurrentIndex(0);
}



int dia::showkind(){
    return ui->chosekind->currentIndex();
}

int dia::showmain(){
    return ui->chosemain->currentIndex();
}

int* dia::showfu(){
    int* afu = new int[4];
    afu[0]=ui->a1->currentIndex();
    afu[1]=ui->a2->currentIndex();
    afu[2]=ui->a3->currentIndex();
    afu[3]=ui->a4->currentIndex();
    return afu;
}
//传出数据


void dia::on_ok_clicked()
{
    int w1=ui->a1->currentIndex();
    int w2=ui->a2->currentIndex();
    int w3=ui->a3->currentIndex();
    int w4=ui->a4->currentIndex();
    if(w1==w2||w1==w3||w1==w4||w2==w3||w2==w4||w3==w4){
        //判断各副词条是否有重复
        QMessageBox::information(this,"错误","重复词条",QMessageBox::Close);
    }
    else{
        QMessageBox::information(this,"提示","自定义已完成！",QMessageBox::Close);
    }
}

void dia::setfu(QStringList stl){
    ui->a1->addItems(stl);
    ui->a2->addItems(stl);
    ui->a3->addItems(stl);
    ui->a4->addItems(stl);
    //设置副词条
}




void dia::on_ok2_clicked()
{
   QStringList adfu={ "小生命" ,"小攻击" ,"小防御" ,"大生命","大攻击" ,"大防御","暴击","暴伤" ,"精通","充能" };
            //"小生命"0 ,"小攻击" 1,"小防御"2 ,"大生命"3,"大攻击"4 ,"大防御"5,"暴击"6,"暴伤"7 ,"精通"8,"充能"9
   setfu(adfu);
   ui->a1->setCurrentIndex(0);
   ui->a2->setCurrentIndex(1);
   ui->a3->setCurrentIndex(2);
   ui->a4->setCurrentIndex(3);
}



void dia::tip(int a){
    int w1=ui->a1->currentIndex();
    int w2=ui->a2->currentIndex();
    int w3=ui->a3->currentIndex();
    int w4=ui->a4->currentIndex();
        if(w1==a||w2==a||w3==a||w4==a){
        //判断是否与主词条重复
            QMessageBox::information(this,"错误","重复词条",QMessageBox::Close);
        }
        else{
            QMessageBox::information(this,"提示","按退出结束自定义",QMessageBox::Close);
        }
}


void dia::on_pb_clicked()
{
//用于判断是否与主词条重复
    int kind=ui->chosekind->currentIndex();
    int main=ui->chosemain->currentIndex();
    if(kind==0)
    {
        tip(1);
    }
    else if(kind==1)
    {
        tip(0);
    }
    else if(kind==2)
    {
        if(main==0)
        {
            tip(9);
        }
        else if(main==1){
            tip(3);
        }
        else if(main==2)
        {
            tip(4);
        }
        else if(main==3)
        {
            tip(5);
        }
        else if(main==4)
        {
            tip(8);
        }
    }
    else if(kind==3)
    {
        if(main==0)
        {
            tip(4);
        }
        else if(main==1){
            tip(3);
        }
        else if(main==2)
        {
            tip(5);
        }
        else if(main==3)
        {
           QMessageBox::information(this,"提示","按确认结束自定义",QMessageBox::Close);
        }
        else if(main==4)
        {
            tip(6);
        }
        else if(main==5)
        {
            tip(7);
        }
        else if(main==4)
        {
            tip(8);
        }
    }
    else if(kind==2)
    {
        if(main<=6||main==11)
        {
            QMessageBox::information(this,"提示","按确认结束自定义",QMessageBox::Close);
        }
        else if(main==7){
            tip(3);
        }
        else if(main==2)
        {
            tip(4);
        }
        else if(main==3)
        {
            tip(5);
        }
        else if(main==4)
        {
            tip(8);
        }
    }
}


void dia::on_out_clicked()
{
    close();
}

