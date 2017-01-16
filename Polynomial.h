#define MAX_LENGTH 100
#include<iostream>
#include <cmath>
#include <cstdlib>
#include<string>
#include <iomanip>
#include <algorithm>
#include<conio.h>
#include<windows.h>
using namespace std;
//最大項數
class Polynomial
{
    int powers[MAX_LENGTH];//多項式次方項
    float elements[MAX_LENGTH];//多項式係數
    public:
        Polynomial();
        Polynomial(const Polynomial&);
        void save_to_file();//存檔
        friend istream& operator >>(istream&,Polynomial&);
        friend ostream& operator <<(ostream&,const Polynomial&);
        void refresh();//整理成降冪
        friend Polynomial operator +(const Polynomial&,const Polynomial&);
        friend Polynomial operator -(const Polynomial&,const Polynomial&);
        friend Polynomial operator *(const Polynomial&,const Polynomial&);
        friend Polynomial operator /(const Polynomial&,const Polynomial&);
        friend Polynomial operator %(const Polynomial&,const Polynomial&);
        void derivative();//微分
        void integral(float C);//積分 C為常數
        //friend void search_root(Polynomial,int sensitive);//找根 sensitive表示到小數後第幾位
        friend void search_answer(Polynomial,int,float,double,double);//求解 y由使用者決定
        friend double y(Polynomial,double);
        friend double yp(Polynomial,double);

        void polyclear();
        void outtest();
        bool isempty();
};
bool Polynomial::isempty()//判斷是否為空多項式
{
    return !(powers[0]||elements[0]);
}
void Polynomial::polyclear()//歸零
{
    for(int i=0;i<MAX_LENGTH;i++)
    {
        powers[i]=0;
        elements[i]=0;
    }
}
Polynomial::Polynomial()
{
    polyclear();
}
Polynomial::Polynomial(const Polynomial& a)
{
    for(int i=0;i<MAX_LENGTH;i++)
    {
        powers[i]=a.powers[i];
        elements[i]=a.elements[i];
    }
    refresh();
}
void Polynomial::outtest()//debug用
{
    for(int i=0;(powers[i]!=0||elements[i]!=0)&&i<20;i++)
    {
        cout<<powers[i]<<" "<<elements[i]<<endl;
    }
}
void gotoxy(int xpos, int ypos)//移動游標(網路上找的)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void show_hint_word(string words,int y)//顯示特定文字而不破壞"框架"
{
    gotoxy(0,y);
    cout<<" ║                                                                          ║"<<endl;
    gotoxy(39-words.length()/2,y);
    cout<<words;
}
#include"derivative.h"
#include"integral.h"
///////////////////////////
#include"Project-add.h"
#include"Project-miu.h"
#include"Project-mul.h"
#include"Project-div.h"
#include"Project-mod.h"
/////////////////////////////
#include"project_pro.h"
//////////////////////////////

#include"ininder.h"
#include"out.h"
/////////////////////////
#include"refresh.h"
