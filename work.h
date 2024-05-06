#ifndef WORK_H
#define WORK_H


#include<ctime>
#include<string>
#include<QString>
#include<QVector>
#include <algorithm>
#include <random>

using namespace std;



class Flower {
public:
    Flower() {};
    int flower_zhu = 717;
    QString zhucitiao();
    //显示出主词条的函数，下同。
    double zhunum();
    //显示主词条数值
    double shengji(int k);
    //升级函数，以升级次数k为形参，下同。
protected:
    int x=1;
};
class Feather {
public:
    Feather() {};
    int feather_zhu = 47;
    QString zhucitiao();
    double zhunum();
    double shengji(int i);
protected:
    int x = 2;
};

class Fucitiao : public Flower, public Feather {
public:
    Fucitiao() {
        fu_ming_xianshi1 = new QString[4];
        fucitiao_xianshi1 =new double[4] ;
    }
    QString fu_ming[10] = { "小生命" ,"小攻击" ,"小防御" ,"大生命","大攻击" ,"大防御","暴击","爆伤" ,"精通","充能" };
    //字符串数组，用于给fu_ming_xianshi数组初始化。
    double fucitiao_bianhua[10][4] = { {209,239,269,299},{14,16,18,19},{16,19,21,23},{4.1,4.7,5.3,5.8},{4.1,4.7,5.3,5.8} ,
    {5.1,5.8,6.6,7.3},{2.7,3.1,3.5,3.9},{5.4,6.2,7.0,7.8},{16,19,21,23},{4.5,5.2,5.8,6.5}, };
    //二维实数数组，第一维为副词条属性，第二维为每种副词条的四种数值，用于给fucitiao_xianshi数组初始化和后续的强化。
    QString* fuw();
    //副词条初始生成函数。
    double* fucitiao();
    //副词条数值生成函数
    void change(int a);
    //打乱副词条的函数
    QString* fuw_xueya(int a,int m);
    //血压模式下的副词条生成与词条属性显示。
    double* fucitiao_shengji_xueya(int i);
    //血压模式下副词条升级函数。
    void zhuan(int*);
    //将保护数据成员b1-b4传出类外。
    double* fucitiao_shengji(int i);
    //副词条升级函数
    void setf(int *arr){
        for(int i=0;i<4;i++){
        arrb[i]=arr[i];
        }
        b1=arr[0];
        b2=arr[1];
        b3=arr[2];
        b4=arr[3];
    }
    //副词条升级函数。
    ~Fucitiao(){delete[] fucitiao_xianshi1;
        delete[]fu_ming_xianshi1;
    }
protected:
    QString *fu_ming_xianshi1;
    double*fucitiao_xianshi1;
    int b1,b2,b3,b4;
    int a1,a2,a3,a4;
    int arrb[4];
    //用于自定义词条参数
    int c[2];
    //c可以选出在显示界面中不是暴击爆伤的词条代号（0-3），用于后续升级。
    int e[2];
    //e则代表非爆伤和暴击词条在副词条数组中的代号，用于后续升级。
};


class Cup {
public:
    void zhengchang(int d7,int f100);
    //将决定元素伤害的变量d7和决定主词条的变量f100转入类内。
    Cup() = default;
    //合成默认构造函数，可使派生类在无构造函数前提下生成对象。
    //通过f与100内多区间比较后生成概率，将概率转化为相应的x值，以决定主属性，下同。
    double cup_zhu_gongji = 7.0;
    double cup_zhu_shengming = 7.0;
    double cup_zhu_fangyu = 8.7;
    double cup_zhu_yuansushanghai = 7.0;
    double cup_zhu_wulisahnghai = 8.3;
    double cup_zhu_jingtong = 28;
    //主词条初始值，下同。
    double cup_zhu;
    //参与主词条运算和显示的值。
    QString a1 = "火元素伤害加成";
    QString a2 = "冰元素伤害加成";
    QString a3 = "水元素伤害加成";
    QString a4 = "岩元素伤害加成";
    QString a5 = "草元素伤害加成";
    QString a6 = "雷元素伤害加成";
    QString a7 = "风元素伤害加成";
    //元素伤害初始string。
    QString yuansushanghai;
    //参与显示的元素伤害string。
    QString zhucitiao();
    double zhunum();
    double shengji(int k);
    int showx();
    static int xx;
    //静态数据成员，用于保存产生对象时生成的x值。
    void setx(int cx);
    void sety(int cy);
protected:
    int x;
    //x为主属性决定数值，决定主词条属性，下同。
    int y;
    //y为元素伤害加成决定数值，在x的基础上选择元素伤害类型。
    int f;
    //f为100内的随机数，与x运算后共同决定圣遗物主属性。
};


class fu_Cup :public Cup {
public:
    fu_Cup(){
        fucitiao_xianshi2=new double[4] ;
        fu_ming_xianshi2=new QString[4];
    }
    void setz(int zz);
    QString fu_ming[10] = { "小生命" ,"小攻击" ,"小防御" ,"大生命","大攻击" ,"大防御","暴击","爆伤" ,"精通","充能" };
    //字符串数组，用于给fu_ming_xianshi数组初始化。
    double fucitiao_bianhua[10][4] = { {209,239,269,299},{14,16,18,19},{16,19,21,23},{4.1,4.7,5.3,5.8},{4.1,4.7,5.3,5.8} ,
    {5.1,5.8,6.6,7.3},{2.7,3.1,3.5,3.9},{5.4,6.2,7.0,7.8},{16,19,21,23},{4.5,5.2,5.8,6.5}, };
    //实数数组，用于给fucitiao_xianshi数组初始化和后续的强化
    QString* fuw();
    double* fucitiao();
    void change();
    //副词条初始生成函数。
    QString* fuw_xueya(int m);
    //进行含双爆的副词条生成的函数，m用以区分是升双爆还是不升。
    double* fucitiao_shengji_xueya(int i);
    //进行非正常状态副词条升级的函数。
    void zhuan(int*);
    double* fucitiao_shengji(int i);
    void setf(int *arr){
        for(int i=0;i<4;i++){
            arrb[i]=arr[i];
        }
        b1=arr[0];
        b2=arr[1];
        b3=arr[2];
        b4=arr[3];
    }
    //副词条升级函数。
    ~fu_Cup(){
        delete[] fucitiao_xianshi2;
        delete[]fu_ming_xianshi2;
    }
protected:
    double *fucitiao_xianshi2;
    QString *fu_ming_xianshi2;
    int b1, b2, b3, b4;
    int a1,a2,a3,a4;
    int arrb[4];
    int z;
    int c[2];
    int e[2];
};


class Head {
public:
    void zhengchang(int f100);
    Head() = default;
    double head_zhu_gongji = 7.0;
    double head_zhu_shengming = 7.0;
    double head_zhu_fangyu = 8.7;
    double head_zhu_baoji = 4.7;
    double head_zhu_baoshang = 9.3;
    double head_zhu_zhiliao = 5.4;
    double head_zhu_jingtong = 28;
    double head_zhu;
    QString zhucitiao();
    double zhunum();
    double shengji(int k);
    int showx();
    void setx(int cx);
    static int xx;
protected:
    int x;
    int f;
};


class fu_Head :public Head {
public:
    fu_Head(){
        fucitiao_xianshi3=new double[4] ;
        fu_ming_xianshi3=new QString[4];
    }
    void setz(int zz);
    QString fu_ming[10] = { "小生命" ,"小攻击" ,"小防御" ,"大生命","大攻击" ,"大防御","暴击","爆伤" ,"精通","充能" };
    double fucitiao_bianhua[10][4] = { {209,239,269,299},{14,16,18,19},{16,19,21,23},{4.1,4.7,5.3,5.8},{4.1,4.7,5.3,5.8} ,
    {5.1,5.8,6.6,7.3},{2.7,3.1,3.5,3.9},{5.4,6.2,7.0,7.8},{16,19,21,23},{4.5,5.2,5.8,6.5}, };
    QString* fuw();
    double* fucitiao();
    void change();
    double* fucitiao_shengji(int i);
    void setf(int *arr){
        for(int i=0;i<4;i++){
            arrb[i]=arr[i];
        }
        b1=arr[0];
        b2=arr[1];
        b3=arr[2];
        b4=arr[3];
    }
    QString* fuw_xueya(int m);
    double* fucitiao_shengji_xueya(int i);
    void zhuan(int*);
    ~fu_Head(){
        delete[]fucitiao_xianshi3;
        delete[]fu_ming_xianshi3;
    }
protected:
    double *fucitiao_xianshi3;
    QString *fu_ming_xianshi3;
    int b1, b2, b3, b4;
    int a1,a2,a3,a4;
    int z;
    int arrb[4];
    int c[2];
    int e[2];
};


class Hourglass {
public:
    void zhengchang(int f100);
    Hourglass()=default;
    double hourglass_zhu_chongneng = 7.8;
    double hourglass_zhu_shengming = 7.0;
    double hourglass_zhu_gongji = 7.0;
    double hourglass_zhu_fangyu = 8.7;
    double hourglass_zhu_jingtong = 28;
    double hourglass_zhu;
    QString zhucitiao();
    double zhunum();
    double shengji(int k);
    int showx();
    static int xx;
    void setx(int cx);
protected:
    int x;
    int f;
};

class fu_Hourglass :public Hourglass {
public:
    fu_Hourglass(){
        fucitiao_xianshi4=new double[4] ;
        fu_ming_xianshi4=new QString[4];
    }
    void setz(int zz);
    QString fu_ming[10] = { "小生命" ,"小攻击" ,"小防御" ,"大生命","大攻击" ,"大防御","暴击","爆伤" ,"精通","充能" };
    double fucitiao_bianhua[10][4] = { {209,239,269,299},{14,16,18,19},{16,19,21,23},{4.1,4.7,5.3,5.8},{4.1,4.7,5.3,5.8} ,
    {5.1,5.8,6.6,7.3},{2.7,3.1,3.5,3.9},{5.4,6.2,7.0,7.8},{16,19,21,23},{4.5,5.2,5.8,6.5}};
    QString* fuw();
    double* fucitiao();
    void change();
    double* fucitiao_shengji(int i);
    void setf(int *arr){
        for(int i=0;i<4;i++){
            arrb[i]=arr[i];
        }
        b1=arr[0];
        b2=arr[1];
        b3=arr[2];
        b4=arr[3];
    }
    QString* fuw_xueya(int m);
    double* fucitiao_shengji_xueya(int i);
    void zhuan(int*);
    ~fu_Hourglass(){
        delete[] fucitiao_xianshi4;
        delete[]fu_ming_xianshi4;
    }
protected:
    double *fucitiao_xianshi4;
    QString *fu_ming_xianshi4;
    int b1, b2, b3, b4;
    int a1,a2,a3,a4;
    int z;
    int arrb[4];
    int c[2];
    int e[2];
};


#endif // WORK_H
