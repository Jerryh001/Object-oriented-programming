ostream& operator <<(ostream& cout,const Polynomial& out)
{

    for (int i = 0 ; i < 100 ; i++)
    {
        if (out.elements[i]==0 && out.powers[i]==0)//�S����ָ�����ǵĕr��
            break;
        else if (out.powers[i]>1)//ָ�����1
        {
            if (out.elements[i]>1)//�S�����1
            {
                if (i==0)//����ǵ�һ�
                cout<<out.elements[i]<<"x^"<<out.powers[i];
                else//���ǵ�һ�
                cout<<"+"<<out.elements[i]<<"x^"<<out.powers[i];
            }
            else if (out.elements[i]<0)//�S��С�1
            {
                if (out.elements[i]==-1)//���������-1
                {
                    cout<<"-x^"<<out.powers[i];
                }
                else//����ؓ1�Ġ�r
                cout<<out.elements[i]<<"x^"<<out.powers[i];
            }
            else if (out.elements[i]==1)//���õ��1 �ĕr��
            {
                if (i==0)//������ڵ�һ헵��1
                cout<<"x^"<<out.powers[i];
                else//�����ڵ�һ헵�Ԓ
                cout<<"+x^"<<out.powers[i];
            }
            else if (out.elements[i]==0)//�S�������ĕr��
            {
                if (out.powers[i]!=1)//���ָ�������1
                cout<<"x^"<<out.powers[i];
                else if (out.powers[i]==1)//ָ�����1
                cout<<"x";
            }
        }
        else if (out.powers[i]==0)//ָ����0
        {
            if (i==0 && out.elements[i]>0)//�ڵ�һ��҂S�����0
            {
                cout<<out.elements[i];
            }
            else if (i!=0 && out.elements[i]>0)//�����ڵ�һ헶��҂S�����0
            {
                cout<<"+"<<out.elements[i];
            }
            else if (out.elements[i]<0)//�S��С�0
            {
                cout<<out.elements[i];
            }
        }
        else if (out.powers[i]==1)//ָ����1
        {
            if (i==0)//������ڵ�һ�
            {
                if (out.elements[i]==1)//�S����1
                cout<<"x";
                else//�S������1
                cout<<out.elements[i]<<"x";
            }
            else if (i != 0 )//���ǵ�һ�
            {
                if (out.elements[i]>0)//�S��>0
                {
                    if (out.elements[i]==1)//�S�����1�ĕr��
                    cout<<"+x";
                    else//�S������1�ĕr��
                    cout<<"+"<<out.elements[i]<<"x";
                }
                else if (out.elements[i]<0)//�S��С�0
                {
                    cout<<out.elements[i]<<"x";
                }

            }

        }
    }
    return cout;

}
