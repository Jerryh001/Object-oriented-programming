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
//�̤j����
class Polynomial
{
    int powers[MAX_LENGTH];//�h�������趵
    float elements[MAX_LENGTH];//�h�����Y��
    public:
        Polynomial();
        Polynomial(const Polynomial&);
        void save_to_file();//�s��
        friend istream& operator >>(istream&,Polynomial&);
        friend ostream& operator <<(ostream&,const Polynomial&);
        void refresh();//��z������
        friend Polynomial operator +(const Polynomial&,const Polynomial&);
        friend Polynomial operator -(const Polynomial&,const Polynomial&);
        friend Polynomial operator *(const Polynomial&,const Polynomial&);
        friend Polynomial operator /(const Polynomial&,const Polynomial&);
        friend Polynomial operator %(const Polynomial&,const Polynomial&);
        void derivative();//�L��
        void integral(float C);//�n�� C���`��
        //friend void search_root(Polynomial,int sensitive);//��� sensitive��ܨ�p�ƫ�ĴX��
        friend void search_answer(Polynomial,int,float,double,double);//�D�� y�ѨϥΪ̨M�w
        friend double y(Polynomial,double);
        friend double yp(Polynomial,double);

        void polyclear();
        void outtest();
        bool isempty();
};
bool Polynomial::isempty()//�P�_�O�_���Ŧh����
{
    return !(powers[0]||elements[0]);
}
void Polynomial::polyclear()//�k�s
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
void Polynomial::outtest()//debug��
{
    for(int i=0;(powers[i]!=0||elements[i]!=0)&&i<20;i++)
    {
        cout<<powers[i]<<" "<<elements[i]<<endl;
    }
}
void gotoxy(int xpos, int ypos)//���ʴ��(�����W�䪺)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void show_hint_word(string words,int y)//��ܯS�w��r�Ӥ��}�a"�ج["
{
    gotoxy(0,y);
    cout<<" ��                                                                          ��"<<endl;
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
