//#include <iostream>
//#include <cmath>
//#include <cstdlib>
//#include <iomanip>
//#include"Polynomial.h"
using namespace std;
double y(Polynomial p,double x)//��X�a�J�h����return(f(x))
{
    //�h����x^4-3x^3+6x^2-68
    double z=0;
    for(int i=0;p.powers[i]!=0||p.elements[i]!=0;i++)
    {
        z+=p.elements[i]*pow(x,p.powers[i]);
    }
    return(z);
}

double yp(Polynomial p,double x)//��X�a�J�h�������L��return(f'(x))
{
    //�h���O�@�L��4x^3-9x^2+12x
    p.derivative();
    double z=0;
    for(int i=0;p.powers[i]!=0||p.elements[i]!=0;i++)
    {
        z+=p.elements[i]*pow(x,p.powers[i]);
    }
    return(z);
}

void search_answer(Polynomial p,int sensitive,float t,double a,double b)
{
    show_hint_word("�B�⤤...�i��|����[�ɶ�",5);
    for(int i=0;;i++)
    {
        if(p.powers[i]==0)
        {
            p.elements[i]-=t;
            break;
        }
    }
    //cout<<fixed<<setprecision(sensitive);
    //��X��l��
    double xa,xb,i,j;
    double ans[20];
    int TotalAns = 0, k, n;
    //a = -100;
    //b = 100;
    for (i=a,j=a;i<=b;j=i,i+=0.1)//a��b���ϥΪ̿�J�ɡA�ҭn�D���D�ڽd��
    if (y(p,i)*y(p,j) < 0)
    ans[TotalAns++] = j;

    n=1;
    //���y�k�D��
    int u=1;
    for (k=0;k<TotalAns;k++)
    {
        xa = ans[k];
        while(1)
        {
            xb = xa-y(p,xa)/yp(p,xa);
            if (fabs(xa-xb) < pow(10,-1*sensitive)) break;
            xa = xb;
        }
        show_hint_word("",5);
        gotoxy(30,u+5);
        cout<<setprecision(sensitive)<<"x="<<xa<<endl;
        u++;
    }
    if(TotalAns==0)
    {
        show_hint_word("�䤣�쵲�G",5);
    }
    gotoxy(30,20);
    system("PAUSE");
        //���h����4�ӸѬ� 3.2001,-2.0425,0.92122+3.0911i,0.92122-3.0911i
}
