//#include<iostream>
//#include"Polynomial.h"
using namespace std;
void Polynomial::refresh()//��z������
{
    for(int i=0;i<MAX_LENGTH;i++)//�M���h�l��
    {
        if(elements[i]==0)
        {
            powers[i]=0;
        }
    }
    for(int i=0;i<MAX_LENGTH;i++)//�Ƨ�
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
