//#include<iostream>
//#include"Polynomial.h"
using namespace std;
void Polynomial::refresh()//整理成降冪
{
    for(int i=0;i<MAX_LENGTH;i++)//清除多餘項
    {
        if(elements[i]==0)
        {
            powers[i]=0;
        }
    }
    for(int i=0;i<MAX_LENGTH;i++)//排序
    {
        for(int j=0;j<MAX_LENGTH-i-1;j++)
        {
            if(powers[j]<powers[j+1])
            {
                swap(powers[j],powers[j+1]);
                swap(elements[j],elements[j+1]);
            }else if(powers[j]==powers[j+1])
            {
                elements[j]+=elements[j+1];
                elements[j+1]=0;
                powers[j+1]=0;
            }
        }
    }
}
