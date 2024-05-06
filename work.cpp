
#include"work.h"
QString Flower::zhucitiao() {
   QString word="生命";
   return word;
}
double Flower::zhunum(){
    return flower_zhu;
}
double Flower::shengji(int k) {
    int a[5] = { 1530,2342,3154,3966,4780};
    //存放着圣遗物主属性4-20级的各个数值，下同。
    flower_zhu = a[k-1];
    return flower_zhu;
}
QString Feather::zhucitiao() {
   QString word= "攻击";
   return word;
}
double Feather::zhunum(){
    return feather_zhu;
}
double Feather::shengji(int k) {
    int b[5] = { 101,153,205,257,311 };
    feather_zhu = b[k-1];
    return feather_zhu;
}

void Fucitiao::change(int a){
    vector<int>fu = { 1,2,3,4,5,6,7,8,9,10};
    //生成含有1-10的动态数组，作为10个副词条。
    switch (a) {
    case 1:
        fu.erase(fu.begin());
        break;
    case 2:
        fu.erase(fu.begin() + 1);
        break;
    }
    /*花主词条为小生命，代号为1，羽主词条为小攻击，代号为2。
    由此甄别主词条，并将其代号从数组fu中删除*/
    random_shuffle(fu.begin(),fu.end());
    //将数组fu随机打乱。
    b1 = fu[0]-1;
    b2 = fu[1]-1;
    b3 = fu[2]-1;
    b4 = fu[3]-1;
    arrb[0]=b1;
    arrb[1]=b2;
    arrb[2]=b3;
    arrb[3]=b4;
    //由于数组从0开始，故将数组fu中的4个不相同随机数提取出来后进行减一后作为副词条数值数组参数作为类的成员。
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
    //生成四个0-3的随机数，在每个副词条中1-4等级中任选。
}

QString* Fucitiao::fuw() {
     for (int i = 0; i<4; i++) {
        int k = arrb[i];
        //由于数组从0开始，故将数组fu中的4个不相同随机数提取出来后进行减一后作为副词条名称数组参数。
        fu_ming_xianshi1[i] = fu_ming[k];
        //对fu_ming_xianshi数组初始化。
    }
    return fu_ming_xianshi1;
    // 将洗牌后的值赋给返回的数组

}


QString* Fucitiao::fuw_xueya(int a,int m){
    vector<int>fu = { 7,8,1,2,3,4,5,6,9,10 };
    //将fu数组改为暴击爆伤前置，并将后续数组打乱。
    switch (a) {
    case 1:
        fu.erase(fu.begin() + 2);
        break;
    case 2:
        fu.erase(fu.begin() + 3);
        break;
    }
    random_shuffle(fu.begin() + 2, fu.end());
    vector<int>fu_ = {1,2,3,4};
    for (int i = 0; i < 4; i++) {
        fu_[i] = fu[i];
    }
    random_shuffle(fu_.begin() , fu_.end());
    //重新提取前四个数组成数组并打乱，做到既含双爆又是乱序。
    b1 = fu_[0] - 1;
    b2 = fu_[1] - 1;
    b3 = fu_[2] - 1;
    b4 = fu_[3] - 1;
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
    for (int i = 0; i < 4; i++) {
        int k = fu_[i] - 1;
        fu_ming_xianshi1[i] = fu_ming[k];
    }
    vector<int>bb = { b1,b2,b3,b4 };
    int cc = 0;
    switch(m){
    case 0:
        for (int i = 0; i < 4; i++) {
            if (bb[i] != 6 && bb[i] != 7) {
                c[cc] = i;
                cc++;
                //选出非双爆词条在显示界面的代号。
            }
        }
        break;
    case 1:
        for (int i = 0; i < 4; i++) {
            if (bb[i] == 6 || bb[i] == 7) {
                c[cc] = i;
                cc++;
                //选出双爆词条在显示界面的代号。
            }
        }
        break;
    }
    for (int i = 0; i < 2; i++) {
        e[i] = bb[c[i]];
        //选出非双爆词条在副词条数组中的代号。
    }
    return fu_ming_xianshi1;
}


double* Fucitiao::fucitiao(){
    fucitiao_xianshi1[0] = fucitiao_bianhua[b1][a1];
    fucitiao_xianshi1[1] = fucitiao_bianhua[b2][a2];
    fucitiao_xianshi1[2] = fucitiao_bianhua[b3][a3];
    fucitiao_xianshi1[3] = fucitiao_bianhua[b4][a4];
    //对fucitiao_xianshi数组初始化。
    return fucitiao_xianshi1;
}

double* Fucitiao::fucitiao_shengji(int i) {
    for(int m=0;m<i;m++){
    int s = rand() % 4 ;
    //随机升级
    int d = rand() % 4;
    //升级的数值随机
    switch (s) {
    case 0:
        fucitiao_xianshi1[0] += fucitiao_bianhua[b1][d];
        break;
    case 1:
        fucitiao_xianshi1[1] += fucitiao_bianhua[b2][d];
        break;
    case 2:
        fucitiao_xianshi1[2] += fucitiao_bianhua[b3][d];
        break;
    case 3:
        fucitiao_xianshi1[3] += fucitiao_bianhua[b4][d];
        break;
    }
    }
    return fucitiao_xianshi1;
}


double* Fucitiao::fucitiao_shengji_xueya(int i) {
    for(int m=0;m<i;m++){
        int s = rand() % 2;
        int d = rand() % 4;
        switch (s) {
        case 0:
            fucitiao_xianshi1[c[0]] += fucitiao_bianhua[e[0]][d];
            //左为显示界面的副词条。
            //右为副词条数组中的副词条。
            break;
        case 1:
            fucitiao_xianshi1[c[1]] += fucitiao_bianhua[e[1]][d];
            break;
        }
    }
    return fucitiao_xianshi1;
}

void Fucitiao::zhuan(int *a){
    a[0]=b1;
    a[1]=b2;
    a[2]=b3;
    a[3]=b4;
    //传输副词条代号
}

void Cup::zhengchang(int d7,int f100){
    y = d7;
    f = f100;
    if (0 < f &&f<= 35)
        x = 1;
    else if (35 < f&&f <= 54)
        x = 2;
    else if (54 < f&&f <= 73)
        x = 3;
    else if (73 < f&&f <= 92)
        x = 4;
    else if (92 < f&&f <= 95)
        x = 5;
    else if (95 < f&&f <= 100)
        x = 6;
}



QString Cup::zhucitiao() {
 //将元素伤害的string赋给参与显示的元素伤害string。
    QString word;
 if (y == 1)
     yuansushanghai = a1;
 else if (y == 2)
     yuansushanghai = a2;
 else if (y == 3)
     yuansushanghai = a3;
 else if (y == 4)
     yuansushanghai = a4;
 else if (y == 5)
     yuansushanghai = a5;
 else if (y == 6)
     yuansushanghai = a6;
 else if (y == 7)
     yuansushanghai = a7;
    if (x == 1)
    {
        word= yuansushanghai;
    }
    else if (x == 2){
        word= "生命" ;
    }
    else if (x == 3){
        word= "攻击" ;
    }
    else if (x == 4){
         word= "防御" ;
    }
    else if (x == 5){
         word= "元素精通" ;
    }
    else if (x == 6){
         word= "物理伤害加成" ;}
    xx = x;
    //将对象中的x值赋给xx，用于副词条的生成。
    return word;
    //初始赋值与显示输出，下同。
}
int Cup::xx = 0;
double Cup::zhunum(){
    if (x == 1)
        cup_zhu=cup_zhu_yuansushanghai;

    else if (x == 2)
        cup_zhu=cup_zhu_shengming;

    else if (x == 3)
        cup_zhu=cup_zhu_gongji;

    else if (x == 4)
        cup_zhu=cup_zhu_fangyu;

    else if (x == 5)
        cup_zhu=cup_zhu_jingtong;

    else if (x == 6)
        cup_zhu=cup_zhu_wulisahnghai;
xx = x;
    return cup_zhu;
}

void Cup::setx(int cx){
    x=cx;
}

void Cup::sety(int cy){
    y=cy;
}

int Cup::showx(){
    return x;
}
void fu_Cup::setz(int zz){
    z=zz;
}

void fu_Cup::change(){
    int k = 0;
    //k为副词条顺序决定代号。
    z = Cup::xx;
    //将对象产生的主词条类型赋给z。
    switch (z) {
    case 2:
        k = 4;
        break;
    case 3:
        k = 5;
        break;
    case 4:
        k = 6;
        break;
    case 5:
        k = 9;
        break;
    default:
        break;
    }
    //词条顺序存在两种，其一为各个圣遗物中的主词条顺序，由x与f共同决定，仅对每个圣遗物有效。
    //二为副词条中的顺序，仅对副词条有用。这里的操作是将在主词条中有用的代号x转化为对副词条有用的代号k。
    vector<int>fu = { 1,2,3,4,5,6,7,8,9,10 };
    //生成含有1-10的动态数组，作为10个副词条。
    switch (k) {
    case 4:
        fu.erase(fu.begin() + 3);
        break;
    case 5:
        fu.erase(fu.begin() + 4);
        break;
    case 6:
        fu.erase(fu.begin() + 5);
        break;
    case 9:
        fu.erase(fu.begin() + 8);
        break;
    default:
        break;
    }
    //k为与主词条重复的，对副词条有用的代号，这里的操作是将k对应的词条从副词条中删除以避免重复出现。
    random_shuffle(fu.begin(),fu.end());
    //将数组fu随机打乱。
    b1 = fu[0] - 1;
    b2 = fu[1] - 1;
    b3 = fu[2] - 1;
    b4 = fu[3] - 1;
    arrb[0]=b1;
    arrb[1]=b2;
    arrb[2]=b3;
    arrb[3]=b4;
    //由于数组从0开始，故将数组fu中的4个不相同随机数提取出来后进行减一后作为副词条数值数组参数。
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
    //生成四个0-3的随机数，在每个副词条中1-4等级中任选。
}


QString*fu_Cup::fuw_xueya(int m){
    int k = 0;
    //k为副词条顺序决定代号。
    int z = Cup::xx;
    //将对象产生的主词条类型赋给z。
    switch (z) {
    case 2:
        k = 4;
        break;
    case 3:
        k = 5;
        break;
    case 4:
        k = 6;
        break;
    case 5:
        k = 9;
        break;
    default:
        break;
    }
    vector<int>fu = { 7,8,1,2,3,4,5,6,9,10 };
    switch (k) {
    case 4:
        fu.erase(fu.begin() + 5);
        break;
    case 5:
        fu.erase(fu.begin() + 6);
        break;
    case 6:
        fu.erase(fu.begin() + 7);
        break;
    case 9:
        fu.erase(fu.begin() + 8);
        break;
    default:
        break;
    }
    random_shuffle(fu.begin() + 2, fu.end());
    vector<int>fu_ = { 1,2,3,4 };
    for (int i = 0; i < 4; i++) {
        fu_[i] = fu[i];
    }
    random_shuffle(fu_.begin(), fu_.end());
    b1 = fu_[0] - 1;
    b2 = fu_[1] - 1;
    b3 = fu_[2] - 1;
    b4 = fu_[3] - 1;
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
    for (int i = 0; i < 4; i++) {
        int k = fu_[i]-1 ;
        fu_ming_xianshi2[i] = fu_ming[k];
    }
    vector<int>bb = { b1,b2,b3,b4 };
    int cc = 0;
    switch(m){
    case 0:
        for (int i = 0; i < 4; i++) {
            if (bb[i] != 6 && bb[i] != 7) {
                c[cc] = i;
                cc++;
            }
        }
        break;
    case 1:
        for (int i = 0; i < 4; i++) {
            if (bb[i] == 6 || bb[i] == 7) {
                c[cc] = i;
                cc++;
            }
        }
        break;
    }
    for (int i = 0; i < 2; i++) {
        e[i] = bb[c[i]];
    }
    return fu_ming_xianshi2;
}

QString* fu_Cup::fuw() {
    for (int i = 0; i < 4; i++) {
        int k = arrb[i] ;
        //由于数组从0开始，故将数组fu中的4个不相同随机数提取出来后进行减一后作为副词条名称数组参数。
        fu_ming_xianshi2[i] = fu_ming[k];
        //对fu_ming_xianshi数组初始化。
    }
    return fu_ming_xianshi2;
}

double*fu_Cup::fucitiao_shengji_xueya(int i){
    for(int m=0;m<i;m++){
        int s = rand() % 2;
        int d = rand() % 4;
        switch (s) {
        case 0:
            fucitiao_xianshi2[c[0]] += fucitiao_bianhua[e[0]][d];
            break;
        case 1:
            fucitiao_xianshi2[c[1]] += fucitiao_bianhua[e[1]][d];
            break;
        }
    }
    return fucitiao_xianshi2;
}

void fu_Cup::zhuan(int *a){
    a[0]=b1;
    a[1]=b2;
    a[2]=b3;
    a[3]=b4;
}

double*fu_Cup::fucitiao(){
    fucitiao_xianshi2[0] = fucitiao_bianhua[b1][a1];
    fucitiao_xianshi2[1] = fucitiao_bianhua[b2][a2];
    fucitiao_xianshi2[2] = fucitiao_bianhua[b3][a3];
    fucitiao_xianshi2[3] = fucitiao_bianhua[b4][a4];
    //对fucitiao_xianshi数组初始化。
    return fucitiao_xianshi2;
}


double* fu_Cup::fucitiao_shengji(int i) {
    for(int m=0;m<i;m++){
    int s = rand() % 4;
    int d = rand() % 4;
    switch (s) {
    case 0:
        fucitiao_xianshi2[0] += fucitiao_bianhua[b1][d];
        break;
    case 1:
        fucitiao_xianshi2[1] += fucitiao_bianhua[b2][d];
        break;
    case 2:
        fucitiao_xianshi2[2] += fucitiao_bianhua[b3][d];
        break;
    case 3:
        fucitiao_xianshi2[3] += fucitiao_bianhua[b4][d];
        break;
    }
    }
    return fucitiao_xianshi2;
    }


double Cup::shengji(int k){
    double a[6][5] = { {14.9,22.8,30.7,38.7,46.6},{14.9,22.8,30.7,38.7,46.6},
                      {14.9,22.8,30.7,38.7,46.6},{18.6,28.5,38.4,48.4,58.3}, {60,92,123,155,187},{18.6,28.5,38.4,48.4,58.3} };
    cup_zhu = a[x-1][k-1];
    //主词条数值的二维数组，第一维为主词条类型，第二维为升级次数，下同。
    return cup_zhu;
}



QString Head::zhucitiao() {
    QString word;
    if (x == 1) {
        word= "攻击";
    }
    else if (x == 2) {
        word= "生命" ;
    }
    else if (x == 3) {
        word="防御" ;
    }
    else if (x == 4) {
        word= "治疗加成" ;
    }
    else if (x == 5) {
        word= "暴击率" ;
    }
    else if (x == 6) {
        word="暴击伤害" ;
    }
    else if (x == 7) {
        word= "元素精通" ;
    }

    return word;
}


void Head::zhengchang(int f100){
    f=f100;
    if (0 < f && f <= 22)
        x = 1;
    else if (22 < f && f <= 44)
        x = 2;
    else if (44 < f && f <= 66)
        x = 3;
    else if (66 < f && f <= 76)
        x = 4;
    else if (76 < f && f <= 86)
        x = 5;
    else if (86 < f && f <= 96)
        x = 6;
    else if (96<f&&f<=100)
        x = 7;
}

void Head::setx(int cx){
    x=cx;
}


int Head::showx(){
    return x;
}

int Head::xx = 0;
double Head::zhunum(){
    if (x == 1)
        head_zhu=head_zhu_gongji;
    else if (x == 2)
        head_zhu= head_zhu_shengming;

    else if (x == 3)
        head_zhu=head_zhu_fangyu;

    else if(x==4)
        head_zhu=head_zhu_zhiliao;

    else if (x == 5)
        head_zhu=head_zhu_baoji;

     else if (x == 6)
        head_zhu=head_zhu_baoshang;

     else if(x==7)
         head_zhu=head_zhu_jingtong;
     Head::xx = x;
    return head_zhu;
}


double Head::shengji(int k) {
    double a[7][5] = { {14.9,22.8,30.7,38.7,46.6},{14.9,22.8,30.7,38.7,46.6},{18.6,28.5,38.4,48.4,58.3},
                      {11.5,17.6,23.7,29.8,35.9},{10.0,15.3,20.5,25.8,31.1} ,{20.0,30.5,41.0,51.3,62.2},{60,92,123,155,187} };
    head_zhu = a[x-1][k-1];
    return head_zhu;
}

void fu_Head::setz(int zz){
    z=zz;
}

void fu_Head::change(){
    int k = 0;
    z = Head::xx;
    switch (z) {
    case 1:
        k = 5;
        break;
    case 2:
        k = 4;
        break;
    case 3:
        k = 6;
        break;
    case 5:
        k = 7;
        break;
    case 6:
        k = 8;
        break;
    case 7:
        k = 9;
        break;
    default:
        break;
    }
    vector<int>fu = { 1,2,3,4,5,6,7,8,9,10 };
    switch (k) {
    case 4:
        fu.erase(fu.begin() + 3);
        break;
    case 5:
        fu.erase(fu.begin() + 4);
        break;
    case 6:
        fu.erase(fu.begin() + 5);
        break;
    case 7:
        fu.erase(fu.begin() + 6);
        break;
    case 8:
        fu.erase(fu.begin() + 7);
        break;
    case 9:
        fu.erase(fu.begin() + 8);
        break;
    default:
        break;
    }
    random_shuffle(fu.begin(),fu.end());
    b1 = fu[0] - 1;
    b2 = fu[1] - 1;
    b3 = fu[2] - 1;
    b4 = fu[3] - 1;
    arrb[0]=b1;
    arrb[1]=b2;
    arrb[2]=b3;
    arrb[3]=b4;
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
}

QString* fu_Head::fuw() {

    for (int i = 0; i < 4; i++) {
        int k = arrb[i] ;
        fu_ming_xianshi3[i] = fu_ming[k];
    }
    return  fu_ming_xianshi3;
}
QString*fu_Head::fuw_xueya(int m){
    int k = 0;
    int z = Head::xx;
    switch (z) {
    case 1:
        k = 5;
        break;
    case 2:
        k = 4;
        break;
    case 3:
        k = 6;
        break;
    case 5:
        k = 7;
        break;
    case 6:
        k = 8;
        break;
    case 7:
        k = 9;
        break;
    default:
        break;
    }
    vector<int>fu = { 7,8,1,2,3,4,5,6,9,10 };
    switch (k) {
    case 4:
        fu.erase(fu.begin() + 5);
        break;
    case 5:
        fu.erase(fu.begin() + 6);
        break;
    case 6:
        fu.erase(fu.begin() + 7);
        break;
    case 7:
        fu.erase(fu.begin());
        break;
    case 8:
        fu.erase(fu.begin() + 1);
        break;
    case 9:
        fu.erase(fu.begin() + 8);
        break;
    default:
        break;
    }
    random_shuffle(fu.begin() + 2, fu.end());
    vector<int>fu_ = { 1,2,3,4 };
    for (int i = 0; i < 4; i++) {
        fu_[i] = fu[i];
    }
    random_shuffle(fu_.begin(), fu_.end());
    b1 = fu_[0] - 1;
    b2 = fu_[1] - 1;
    b3 = fu_[2] - 1;
    b4 = fu_[3] - 1;
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
    for (int i = 0; i < 4; i++) {
        int k = fu_[i]-1 ;
        fu_ming_xianshi3[i] = fu_ming[k];
    }
    vector<int>bb = { b1,b2,b3,b4 };
    int cc = 0;
    switch(m){
    case 0:
        for (int i = 0; i < 4; i++) {
            if (bb[i] != 6 && bb[i] != 7) {
                c[cc] = i;
                cc++;
            }
        }
        break;
    case 1:
        for (int i = 0; i < 4; i++) {
            if (bb[i] == 6 || bb[i] == 7) {
                c[cc] = i;
                cc++;
            }
        }
        break;
    }
    for (int i = 0; i < 2; i++) {
        e[i] = bb[c[i]];
    }
    return  fu_ming_xianshi3;
}


double* fu_Head::fucitiao(){
    fucitiao_xianshi3[0] = fucitiao_bianhua[b1][a1];
    fucitiao_xianshi3[1] = fucitiao_bianhua[b2][a2];
    fucitiao_xianshi3[2] = fucitiao_bianhua[b3][a3];
    fucitiao_xianshi3[3] = fucitiao_bianhua[b4][a4];

    return fucitiao_xianshi3;
}



double* fu_Head::fucitiao_shengji(int i) {
    for(int m=0;m<i;m++){
    int s = rand() % 4;
    int d = rand() % 4;
    switch (s) {
    case 0:
        fucitiao_xianshi3[0] += fucitiao_bianhua[b1][d];
        break;
    case 1:
        fucitiao_xianshi3[1] += fucitiao_bianhua[b2][d];
        break;
    case 2:
        fucitiao_xianshi3[2] += fucitiao_bianhua[b3][d];
        break;
    case 3:
        fucitiao_xianshi3[3] += fucitiao_bianhua[b4][d];
        break;
    }
    }
    return fucitiao_xianshi3;
}
double*fu_Head::fucitiao_shengji_xueya(int i){
    for(int m=0;m<i;m++){
        int s = rand() % 2;
        int d = rand() % 4;
        switch (s) {
        case 0:
            fucitiao_xianshi3[c[0]] += fucitiao_bianhua[e[0]][d];
            break;
        case 1:
            fucitiao_xianshi3[c[1]] += fucitiao_bianhua[e[1]][d];
            break;
        }
    }
    return fucitiao_xianshi3;
}

void fu_Head::zhuan(int *a){
    a[0]=b1;
    a[1]=b2;
    a[2]=b3;
    a[3]=b4;
}

void Hourglass::zhengchang(int f100){
    f = f100;
    if (0 < f && f <= 10)
        x = 1;
    else if (10 < f && f <= 37)
        x = 2;
    else if (37 < f && f <= 64)
        x = 3;
    else if (64 < f && f <= 90)
        x = 4;
    else if (90 < f && f <= 100)
        x = 5;
}


 QString Hourglass::zhucitiao(){
     QString word;
     if (x == 1)
         word="充能";
     else if (x == 2)
         word="生命";
     else if(x==3)
         word="攻击";
     else if (x == 4)
         word="防御";
     else if(x==5)
         word="精通";

     return word;

 }

 int Hourglass::showx(){
     return x;
 }


 void Hourglass::setx(int cx){
     x=cx;
 }


int Hourglass::xx = 0;
double Hourglass::zhunum() {

    if (x == 1)
    {
        hourglass_zhu = hourglass_zhu_chongneng;

    }
    else if (x == 2)
    {
        hourglass_zhu = hourglass_zhu_shengming;

    }
    else if (x == 3)
    {
        hourglass_zhu = hourglass_zhu_gongji;

    }
    else if (x == 4)
    {
        hourglass_zhu = hourglass_zhu_fangyu;

    }
    else if (x == 5)
    {
        hourglass_zhu = hourglass_zhu_jingtong;

    }
    xx = x;
    return hourglass_zhu;
}

QString*fu_Hourglass::fuw_xueya(int m){
    int k = 0;
    int z = Hourglass::xx;
    switch (z) {
    case 1:
        k = 10;
        break;
    case 2:
        k = 4;
        break;
    case 3:
        k = 5;
        break;
    case 4:
        k = 6;
        break;
    case 5:
        k = 9;
        break;
    default:
        break;
    }
    vector<int>fu = { 7,8,1,2,3,4,5,6,9,10 };
    switch (k) {
    case 4:
        fu.erase(fu.begin() + 5);
        break;
    case 5:
        fu.erase(fu.begin() + 6);
        break;
    case 6:
        fu.erase(fu.begin() + 7);
        break;
    case 9:
        fu.erase(fu.begin() + 8);
        break;
    case 10:
        fu.erase(fu.begin() + 9);
        break;
    default:
        break;
    }
    random_shuffle(fu.begin() + 2, fu.end());
    vector<int>fu_ = { 1,2,3,4 };
    for (int i = 0; i < 4; i++) {
        fu_[i] = fu[i];
    }
    random_shuffle(fu_.begin(), fu_.end());
    b1 = fu_[0] - 1;
    b2 = fu_[1] - 1;
    b3 = fu_[2] - 1;
    b4 = fu_[3] - 1;
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
    for (int i = 0; i < 4; i++) {
        int k = fu_[i] -1;
        fu_ming_xianshi4[i] = fu_ming[k];
    }
    vector<int>bb = { b1,b2,b3,b4 };
    int cc = 0;
    switch(m){
    case 0:
        for (int i = 0; i < 4; i++) {
            if (bb[i] != 6 && bb[i] != 7) {
                c[cc] = i;
                cc++;
            }
        }
        break;
    case 1:
        for (int i = 0; i < 4; i++) {
            if (bb[i] == 6 || bb[i] == 7) {
                c[cc] = i;
                cc++;
            }
        }
        break;
    }
    for (int i = 0; i < 2; i++) {
        e[i] = bb[c[i]];
    }
    return fu_ming_xianshi4;
}


double Hourglass::shengji(int k) {
    double a[5][5] = { {16.6,25.4,34.2,43.0,51.8},{14.9,22.8,30.7,38.7,46.6},
                      {14.9,22.8,30.7,38.7,46.6},{18.6,28.5,38.4,48.4,58.3},{60,92,123,155,187} };
    hourglass_zhu = a[x-1][k-1];
    return hourglass_zhu;
}

void fu_Hourglass::setz(int zz){
    z=zz;
}

void fu_Hourglass::change(){
    int k = 0;
    z = Hourglass::xx;
    switch (z) {
    case 1:
        k = 10;
        break;
    case 2:
        k = 4;
        break;
    case 3:
        k = 5;
        break;
    case 4:
        k = 6;
        break;
    case 5:
        k = 9;
        break;
    default:
        break;
    }
    vector<int>fu = { 1,2,3,4,5,6,7,8,9,10 };
    //生成含有1-10的动态数组，作为10个副词条。
    switch (k) {
    case 4:
        fu.erase(fu.begin() + 3);
        break;
    case 5:
        fu.erase(fu.begin() + 4);
        break;
    case 6:
        fu.erase(fu.begin() + 5);
        break;
    case 9:
        fu.erase(fu.begin() + 8);
        break;
    case 10:
        fu.erase(fu.begin() + 9);
        break;
    default:
        break;
    }
    random_shuffle(fu.begin(),fu.end());
    //将数组fu随机打乱。
    b1 = fu[0] - 1;
    b2 = fu[1] - 1;
    b3 = fu[2] - 1;
    b4 = fu[3] - 1;
    arrb[0]=b1;
    arrb[1]=b2;
    arrb[2]=b3;
    arrb[3]=b4;
    //由于数组从0开始，故将数组fu中的4个不相同随机数提取出来后进行减一后作为副词条数值数组参数。
    a1 = rand() % 4;
    a2 = rand() % 4;
    a3 = rand() % 4;
    a4 = rand() % 4;
    //生成四个0-3的随机数，在每个副词条中1-4等级中任选。
}


QString* fu_Hourglass::fuw() {
    for (int i = 0; i < 4; i++) {
        int k = arrb[i];
        //由于数组从0开始，故将数组fu中的4个不相同随机数提取出来后进行减一后作为副词条名称数组参数。
        fu_ming_xianshi4[i] = fu_ming[k];
        //对fu_ming_xianshi数组初始化。
    }
    return fu_ming_xianshi4;
}

double*fu_Hourglass::fucitiao(){
    fucitiao_xianshi4[0] = fucitiao_bianhua[b1][a1];
    fucitiao_xianshi4[1] = fucitiao_bianhua[b2][a2];
    fucitiao_xianshi4[2] = fucitiao_bianhua[b3][a3];
    fucitiao_xianshi4[3] = fucitiao_bianhua[b4][a4];
    //对fucitiao_xianshi数组初始化。
    return fucitiao_xianshi4;
}


double* fu_Hourglass::fucitiao_shengji(int i) {
    for(int m=0;m<i;m++){
    int s = rand() % 4;
    int d = rand() % 4;
    switch (s) {
    case 0:
        fucitiao_xianshi4[0] += fucitiao_bianhua[b1][d];
        break;
    case 1:
        fucitiao_xianshi4[1] += fucitiao_bianhua[b2][d];
        break;
    case 2:
        fucitiao_xianshi4[2] += fucitiao_bianhua[b3][d];
        break;
    case 3:
        fucitiao_xianshi4[3] += fucitiao_bianhua[b4][d];
        break;
    }
    }
    return fucitiao_xianshi4;
}


double*fu_Hourglass::fucitiao_shengji_xueya(int i){
    for(int m=0;m<i;m++){
        int s = rand() % 4;
        int d = rand() % 4;
        switch (s) {
        case 0:
            fucitiao_xianshi4[c[0]] += fucitiao_bianhua[e[0]][d];
            break;
        case 1:
            fucitiao_xianshi4[c[1]] += fucitiao_bianhua[e[1]][d];
            break;
        }
    }
    return fucitiao_xianshi4;
}

void fu_Hourglass::zhuan(int *a){
    a[0]=b1;
    a[1]=b2;
    a[2]=b3;
    a[3]=b4;
}
