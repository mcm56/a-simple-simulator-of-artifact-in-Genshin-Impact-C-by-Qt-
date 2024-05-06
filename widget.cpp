#include "widget.h"
#include"work.h"
#include "./ui_widget.h"
#include"score.h"
#include"ku.h"
#include"ui_score.h"
#include<ctime>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lv->setSingleStep(4);
    //升级步长设置为4
    ui->lv->setMaximum(20);
    //上限设置为20
    ui->lv->setMinimum(0);
    //下限设置为0
    connect(this,&Widget::send,&s0,&score::get);
    connect(this,&Widget::send1,&s0,&score::get1);//连接信号与槽
    connect(this,&Widget::send_ku6,&k0,&ku::get_ku6);//
    connect(this,&Widget::send_ku1,&k0,&ku::get_ku1);//
    connect(this,&Widget::send_ku2,&k0,&ku::get_ku2);//
    connect(this,&Widget::send_ku3,&k0,&ku::get_ku3);//
    connect(this,&Widget::send_ku4,&k0,&ku::get_ku4);//
    connect(this,&Widget::send_ku5,&k0,&ku::get_ku5);//

}

Widget::~Widget()
{
    delete ui;
}


double*fuw_up;
//升级后的数值
int fu_sy[4];
//副词条编号

QString mainword_ku;//
QString mainnumber_ku;//


int A5(){
    srand(time(NULL));
    static int a5= rand() % 5 + 1;
    return a5;
    //生成5以内随机数以生成五种不同的圣遗物。
}
int D7(){
    srand(time(NULL));
    static int d7 =rand() % 7 + 1;
    //生成7以内随机数以生成七种不同的元素伤害。
    return d7;
}
int C34(){
    srand(time(NULL));
    static int c = rand() % 5 + 1;
    //生成2以内随机数以生成三或四个副词条。
    return c;
}
int F100(){
    srand(time(NULL));
    static int f100 =rand() % 100 + 1;
    //生成100以内随机数以模拟生成圣遗物的概率。
    return f100;
}
int a5=A5();
//对a5先以A5（）初始化。

void Widget::on_genghuan_clicked()
{
    vector<int>genghuan={1,2,3,4,5};
    random_shuffle(genghuan.begin(),genghuan.end());
    a5=genghuan[0];
    //每次点击更换圣遗物可以更换圣遗物种类。
}

int c34;
//3或4词条参数

int f100;

int d7;





QString changed1(double b){
    QString qs;
    QTextStream(& qs)<<b;
    return qs;
}
//将double类型转换为QString


QString changed1(int b){
    QString qs;
    QTextStream(& qs)<<b;
    return qs;
}
//重载函数，将int类型转换为QString


QString changed2(double b){
    QString qs;
    QTextStream(& qs)<<b<<"%";
    return qs;
}
//加入百分号


QString temps;
Feather feather;
Flower flower;
Hourglass hourglass;
Head head;
Cup cup;
//生成五种圣遗物的对象
fu_Cup fucitiao_cup;
fu_Head fucitiao_head;
fu_Hourglass fucitiao_hourglass;
//生成杯、头、沙三种圣遗物的副词条对象。
Fucitiao fucitiao;
//生成花、羽两种圣遗物的副词条对象
//生成五个圣遗物对象各一个



int k=0;
//0代表正常状态，1代表血压和幻想模式。

int m=0;
//0代表血压状态，1代表幻想状态。

int geshu=0;
//统计圣遗物生成次数。

bool chose=0;
//代表是否自定义
//0表示正常

static int temp=0;

int setkind;
int setmain;

void Widget::on_mode2_clicked()
{
    dia dlg;
    dlg.exec();
    int* result = dlg.showfu();
    int setfu[4];
    // 使用返回的值
    for (int i = 0; i < 4; i++) {
        setfu[i] = result[i];
    }
    delete[] result; // 手动释放内存
    setkind=dlg.showkind()+1;
    //自定义种类编号
    setmain=dlg.showmain()+1;
    //自定义主词条编号
    chose=1;
    //1表示自定义模式
    if(setkind==1||setkind==2)
    {
        //自定义花和羽毛的副词条
        fucitiao.setf(setfu);
    }
    if(setkind==3)
    {
        //自定义沙漏
        fucitiao_hourglass.setf(setfu);
        hourglass.setx(setmain);
        fucitiao_hourglass.setz(setmain);
    }
    if(setkind==4)
    {
        //自定义头
        fucitiao_head.setf(setfu);
        head.setx(setmain);
        fucitiao_head.setz(setmain);
    }
    if(setkind==5)
    {
        //自定义杯子
        fucitiao_cup.setf(setfu);
        if(setmain>=8)
        {
            cup.setx(setmain-6);
            fucitiao_cup.setz(setmain-6);
        }
        else
        {
            cup.setx(1);
            cup.sety(setmain);
            fucitiao_cup.setz(1);
        }
    }

}

void Widget::on_gaoxueye_toggled(bool checked)
{
    chose=0;
    k=1;
    m=0;
}

void Widget::on_zhengchang_toggled(bool checked)
{
    chose=0;
    k=0;
}

void Widget::on_haunxiang_toggled(bool checked)
{
    chose=0;
    k=1;
    m=1;
}

int if_save=0;
//1则可以保存，0为不能保存。


void Widget::on_createb_clicked()
{
    vector<int>cc34={1,2,3,4,5};
    random_shuffle(cc34.begin(),cc34.end());
    c34=cc34[0];
    //决定副词条为三或四词条。
    vector<int>ff100={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                         16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
                         29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
                         42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
                         55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
                         68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
                         81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93,
                         94, 95, 96, 97, 98, 99, 100};
    random_shuffle(ff100.begin(),ff100.end());
    f100=ff100[0];
    //决定主词条类型的百分比概率。
    vector<int>dd7={1,2,3,4,5,6,7};
    random_shuffle(dd7.begin(),dd7.end());
    d7=dd7[0];
    //决定元素伤害加成的类型。
    ui->lv->setValue(0);
    ui->dengji->setText("0");
   //初始等级设置为0
    QPixmap pix;
    //设置图片
    QString aname;
    //种类名称
    QString mainword;
    //主词条
    double mainnum;
    //主词条数值
    QString mainnums;
    //转换为QString形式
    QString *fuw;
    //副词条
    double *funum;
    //副词条数值


    if(chose==0){
        //正常模式初始化
        srand(time(NULL));
        c34=C34();
        hourglass.zhengchang(f100);
        head.zhengchang(f100);
        cup.zhengchang(d7,f100);
        //随机数初始化
    }
    else{
        //自定义模式初始化
        a5=setkind;
        c34=5;
    }


QMessageBox::information(this,"提示","圣遗物生成中！",QMessageBox::Close);
       if(a5==1){
        QPixmap pix1("yu.png");
        pix=pix1;//图片设置
        aname="死之羽";
        mainword=feather.zhucitiao();
        //主词条设置
        mainnum=feather.zhunum();
        //主词条数值设置
        if(chose==0){
            fucitiao.change(1);
            //正常模式下副词条的初始化
        }
        mainnums=changed1(mainnum);
        //转换为字符串形式
        switch(k){
        case 0:
            fuw=fucitiao.fuw();
            break;
        case 1:
            fuw=fucitiao.fuw_xueya(2,m);
            break;
        }
        funum=fucitiao.fucitiao();
        //副词条设置
        fucitiao.zhuan(fu_sy);
       }
       else if(a5==2){
        QPixmap pix2("hua.png");
        pix=pix2;
        aname="生之花";
        mainword=flower.zhucitiao();
        mainnum=flower.zhunum();
        if(chose==0){
            fucitiao.change(2);
        }
        mainnums=changed1(mainnum);
        switch(k){
        case 0 :
            fuw=fucitiao.fuw();
            break;
        case 1:
            fuw=fucitiao.fuw_xueya(1,m);
            break;
        }
        funum=fucitiao.fucitiao();
        fucitiao.zhuan(fu_sy);

    }
       else if(a5==3){
        QPixmap pix3("sha.png");
        pix=pix3;
        aname="时之沙";
        mainword=hourglass.zhucitiao();
        mainnum=hourglass.zhunum();
        if(chose==0){
            fucitiao_hourglass.change();
        }
        if (hourglass.showx()==5){
            mainnums=changed1(mainnum);}
        else{
            mainnums=changed2(mainnum);}
        switch(k){
        case 0:
            fuw=fucitiao_hourglass.fuw();
            break;
        case 1:
            fuw=fucitiao_hourglass.fuw_xueya(m);
            break;
        }
        funum=fucitiao_hourglass.fucitiao();
        fucitiao_hourglass.zhuan(fu_sy);

    }
       else if(a5==4){
        QPixmap pix4("guan.png");
        pix=pix4;
        aname="理之冠" ;
        mainword=head.zhucitiao();
        mainnum=head.zhunum();
        if(chose==0){
            fucitiao_head.change();
        }
        if (head.showx()==7){
            mainnums=changed1(mainnum);
        }
        else{
            mainnums=changed2(mainnum);
        }
        switch(k){
        case 0:
            fuw=fucitiao_head.fuw();
            break;
        case 1:
            fuw=fucitiao_head.fuw_xueya(m);
            break;
        }
        funum=fucitiao_head.fucitiao();
        fucitiao_head.zhuan(fu_sy);

    }
       else if(a5==5){
        QPixmap pix5("bei.png");
        pix=pix5;
        aname= "空之杯" ;
        mainword=cup.zhucitiao();
        mainnum=cup.zhunum();
        if(chose==0){
            fucitiao_cup.change();
        }
        if (cup.showx()==5){
            mainnums=changed1(mainnum);
        }
        else{
            mainnums=changed2(mainnum);
        }
        switch(k){
        case 0:
            fuw=fucitiao_cup.fuw();
            break;
        case 1:
            fuw=fucitiao_cup.fuw_xueya(m);
            break;
        }
        funum=fucitiao_cup.fucitiao();
        fucitiao_cup.zhuan(fu_sy);

    }
    QString funums[4];
    for(int j=0;j<4;j++){
        funums[j]=changed1(funum[j]);
    }
    if(geshu!=0){
        ui->fw1->setText(" ");
        ui->fw2->setText(" ");
        ui->fw3->setText(" ");
        ui->fw4->setText(" ");
        ui->fn1->setText(" ");
        ui->fn2->setText(" ");
        ui->fn3->setText(" ");
        ui->fn4->setText(" ");
    }
    mainword_ku=mainword;//
    ui->picture->setPixmap(pix);
    ui->name->setText(aname);
    ui->mw->setText(mainword);
    ui->mn->setText(mainnums);
    ui->fw1->setText(fuw[0]);
    ui->fw2->setText(fuw[1]);
    ui->fw3->setText(fuw[2]);
    ui->fn1->setText(funums[0]);
    ui->fn2->setText(funums[1]);
    ui->fn3->setText(funums[2]);
    if(c34>4){
        ui->fw4->setText(fuw[3]);
        ui->fn4->setText(funums[3]);
    }
    temps=fuw[3];
    geshu++;
    temp=0;
    if_save=1;
}






int lvnow;
   //显示当前等级
int ci=1;
void Widget::on_up_clicked()
{
    ui->dengji->setText(changed1(lvnow));
    int outlv=ui->lv->value()/4;
    int outlv_=(ui->lv->value()/4)-temp;
    if(outlv_<=0){
        QMessageBox::information(this,"错误","无效升级",QMessageBox::Close);
    }
    else{
    QMessageBox::information(this,"提示","升级成功！",QMessageBox::Close);
    double mainnum2;
    QString mainnums2;
    //升级后的副词条
    QString fuw_ups[4];
    //副词条数组
    lvnow=ui->lv->value();
    if(c34>4){
        //判断是否为3词条
        //4词条的升级办法
    if(a5==1){
        mainnum2=feather.shengji(outlv);
        //对主词条进行升级
        mainnums2=changed1(mainnum2);
        //转换为字符串
        switch(k){
        case 0:
            fuw_up=fucitiao.fucitiao_shengji(outlv_);
            break;
        case 1:
            fuw_up=fucitiao.fucitiao_shengji_xueya(outlv_);
            break;
        }
        //对副词条进行升级
        for(int j=0;j<4;j++){
        fuw_ups[j]=changed1(fuw_up[j]);
        }
    }
    else if(a5==2){
        mainnum2=flower.shengji(outlv);
         mainnums2=changed1(mainnum2);
        switch(k){
        case 0:
            fuw_up=fucitiao.fucitiao_shengji(outlv_);
            break;
        case 1:
            fuw_up=fucitiao.fucitiao_shengji_xueya(outlv_);
            break;
        }
        for(int j=0;j<4;j++){
            fuw_ups[j]=changed1(fuw_up[j]);
        }
     }
    else if(a5==3){
          mainnum2=hourglass.shengji(outlv);
         if (hourglass.showx()==5)
          {  mainnums2=changed1(mainnum2);}
         else
         {mainnums2=changed2(mainnum2);}
         switch(k){
         case 0:
             fuw_up=fucitiao_hourglass.fucitiao_shengji(outlv_);
             break;
         case 1:
             fuw_up=fucitiao_hourglass.fucitiao_shengji_xueya(outlv_);
             break;
         }
         for(int j=0;j<4;j++){
             fuw_ups[j]=changed1(fuw_up[j]);
         }
     }
     else if(a5==4){
         mainnum2=head.shengji(outlv);
         if (head.showx()==7)
         { mainnums2=changed1(mainnum2);}
         else
         {mainnums2=changed2(mainnum2);}
         switch(k){
         case 0:
             fuw_up=fucitiao_head.fucitiao_shengji(outlv_);
             break;
         case 1:
             fuw_up=fucitiao_head.fucitiao_shengji_xueya(outlv_);
             break;
         }
         for(int j=0;j<4;j++){
             fuw_ups[j]=changed1(fuw_up[j]);
         }
     }
     else if(a5==5){
         mainnum2=cup.shengji(outlv);
         if (cup.showx()==5)
         {  mainnums2=changed1(mainnum2);}
         else
         {  mainnums2=changed2(mainnum2);}
         switch(k){
         case 0:
             fuw_up=fucitiao_cup.fucitiao_shengji(outlv_);
             break;
         case 1:
             fuw_up=fucitiao_cup.fucitiao_shengji_xueya(outlv_);
             break;
         }
         for(int j=0;j<4;j++){
             fuw_ups[j]=changed1(fuw_up[j]);
         }
     }
    }
    else{
        //3词条的升级办法
        if(a5==1){
            mainnum2=feather.shengji(outlv);
            mainnums2=changed1(mainnum2);
            switch(k){
            case 0:
                fuw_up=fucitiao.fucitiao_shengji(outlv_-ci);
                break;
            case 1:
                fuw_up=fucitiao.fucitiao_shengji_xueya(outlv_-ci);
                break;
            }
            for(int j=0;j<4;j++){
                fuw_ups[j]=changed1(fuw_up[j]);
            }
        }
        if(a5==2){
            mainnum2=flower.shengji(outlv);
            mainnums2=changed1(mainnum2);
            switch(k){
            case 0:
                fuw_up=fucitiao.fucitiao_shengji(outlv_-ci);
                break;
            case 1:
                fuw_up=fucitiao.fucitiao_shengji_xueya(outlv_-ci);
                break;
            }
            for(int j=0;j<4;j++){
                fuw_ups[j]=changed1(fuw_up[j]);
            }
        }
        else if(a5==3){
            mainnum2=hourglass.shengji(outlv);
            if (hourglass.showx()==5)
            {
                mainnums2=changed1(mainnum2);
            }
            else
            {
                mainnums2=changed2(mainnum2);
            }
            switch(k){
            case 0:
                fuw_up=fucitiao_hourglass.fucitiao_shengji(outlv_-ci);
                break;
            case 1:
                fuw_up=fucitiao_hourglass.fucitiao_shengji_xueya(outlv_-ci);
                break;
            }
            for(int j=0;j<4;j++){
                fuw_ups[j]=changed1(fuw_up[j]);
            }
        }
        else if(a5==4){
            mainnum2=head.shengji(outlv);
            if (head.showx()==7)
            {
                mainnums2=changed1(mainnum2);
            }
            else
            {
                mainnums2=changed2(mainnum2);
            }
            switch(k){
            case 0:
                fuw_up=fucitiao_head.fucitiao_shengji(outlv_-ci);
                break;
            case 1:
                fuw_up=fucitiao_head.fucitiao_shengji_xueya(outlv_-ci);
                break;
            }
            for(int j=0;j<4;j++){
                fuw_ups[j]=changed1(fuw_up[j]);
            }
        }
        else if(a5==5){
            mainnum2=cup.shengji(outlv);
            if (cup.showx()==5)
            {
                mainnums2=changed1(mainnum2);
            }
            else
            {
                mainnums2=changed2(mainnum2);
            }
            switch(k){
            case 0:
                fuw_up=fucitiao_cup.fucitiao_shengji(outlv_-ci);
                break;
            case 1:
                fuw_up=fucitiao_cup.fucitiao_shengji_xueya(outlv_-ci);
                break;
            }
            for(int j=0;j<4;j++){
                fuw_ups[j]=changed1(fuw_up[j]);
            }
        }
    }
    mainnumber_ku=mainnums2;
     ui->mn->setText(mainnums2);
     ui->fw4->setText(temps);
     ui->fn1->setText(fuw_ups[0]);
     ui->fn2->setText(fuw_ups[1]);
     ui->fn3->setText(fuw_ups[2]);
     ui->fn4->setText(fuw_ups[3]);
     //设置升级后的副词条
     QString lvnow_str=changed1(lvnow);
     ui->dengji->setText(lvnow_str);
     //将等级显示在窗口
     temp=outlv;
     //记录此次点击
     ci=0;
    }
}







void Widget::on_cancelb_clicked()
{
    close();
}


void Widget::on_fen_clicked()
{
    emit send(fuw_up);
    emit send1(fu_sy);
    //emit传输数据
    if(lvnow==20){
        s0.exec();
        //打开评分窗口
    }
    else{
     QMessageBox::information(this,"错误","20级后才可评分",QMessageBox::Close);
    }
}


void Widget::on_ku_clicked()
{
    k0.exec();
    //k0为仓库窗口
}

int xu;//

int if_kong11;//
int if_kong22;//
int if_kong33;//
int if_kong44;//
int if_kong55;//

void Widget::on_save_clicked()
{
    if_kong11=k0.trans1();
    if_kong22=k0.trans2();
    if_kong33=k0.trans3();
    if_kong44=k0.trans4();
    if_kong55=k0.trans5();
//获取仓库中位置是否已满的信息
    if(ui->lv->value()==20){
        if(if_save==1){
            if(if_kong11!=1){
             xu=1;
             emit send_ku6(xu);
             emit send_ku1(a5);
             emit send_ku2(mainword_ku);
             emit send_ku3(mainnumber_ku);
             emit send_ku4(fuw_up);
             emit send_ku5(fu_sy);
             if_save=0;
             }
            else if(if_kong22!=1){
                xu=2;
                emit send_ku6(xu);
                emit send_ku1(a5);
                emit send_ku2(mainword_ku);
                emit send_ku3(mainnumber_ku);
                emit send_ku4(fuw_up);
                emit send_ku5(fu_sy);
                if_save=0;
            }
             else if(if_kong33!=1){
                 xu=3;
                 emit send_ku6(xu);
                 emit send_ku1(a5);
                 emit send_ku2(mainword_ku);
                 emit send_ku3(mainnumber_ku);
                 emit send_ku4(fuw_up);
                 emit send_ku5(fu_sy);
                 if_save=0;
             }
            else if(if_kong44!=1){
                xu=4;
                emit send_ku6(xu);
                emit send_ku1(a5);
                emit send_ku2(mainword_ku);
                emit send_ku3(mainnumber_ku);
                emit send_ku4(fuw_up);
                emit send_ku5(fu_sy);
                if_save=0;
            }
             else if(if_kong55!=1){
                 xu=5;
                 emit send_ku6(xu);
                 emit send_ku1(a5);
                 emit send_ku2(mainword_ku);
                 emit send_ku3(mainnumber_ku);
                 emit send_ku4(fuw_up);
                 emit send_ku5(fu_sy);
                 if_save=0;
             }
            else {
               QMessageBox::information(this,"错误","已达五个保存上限",QMessageBox::Close);
                }
        }
        else{
            QMessageBox::information(this,"错误","一个圣遗物只能保存一次",QMessageBox::Close);
        }
    }
    else {
        QMessageBox::information(this,"错误","只能20级时才能保存",QMessageBox::Close);
    }
}



