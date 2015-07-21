ostream& operator <<(ostream& cout,const Polynomial& out)
{

    for (int i = 0 ; i < 100 ; i++)
    {
        if (out.elements[i]==0 && out.powers[i]==0)//係數根指數都是的時候
            break;
        else if (out.powers[i]>1)//指數大於1
        {
            if (out.elements[i]>1)//係數大於1
            {
                if (i==0)//如果是第一項
                cout<<out.elements[i]<<"x^"<<out.powers[i];
                else//不是第一項
                cout<<"+"<<out.elements[i]<<"x^"<<out.powers[i];
            }
            else if (out.elements[i]<0)//係數小於1
            {
                if (out.elements[i]==-1)//如果剛好是-1
                {
                    cout<<"-x^"<<out.powers[i];
                }
                else//不是負1的狀況
                cout<<out.elements[i]<<"x^"<<out.powers[i];
            }
            else if (out.elements[i]==1)//剛好等於1 的時候
            {
                if (i==0)//如果是在第一項等於1
                cout<<"x^"<<out.powers[i];
                else//不是在第一項的話
                cout<<"+x^"<<out.powers[i];
            }
            else if (out.elements[i]==0)//係數等於零的時候
            {
                if (out.powers[i]!=1)//如果指數不等於1
                cout<<"x^"<<out.powers[i];
                else if (out.powers[i]==1)//指數等於1
                cout<<"x";
            }
        }
        else if (out.powers[i]==0)//指數是0
        {
            if (i==0 && out.elements[i]>0)//在第一項且係數大於0
            {
                cout<<out.elements[i];
            }
            else if (i!=0 && out.elements[i]>0)//不是在第一項而且係數大於0
            {
                cout<<"+"<<out.elements[i];
            }
            else if (out.elements[i]<0)//係數小於0
            {
                cout<<out.elements[i];
            }
        }
        else if (out.powers[i]==1)//指數是1
        {
            if (i==0)//如果是在第一項
            {
                if (out.elements[i]==1)//係數是1
                cout<<"x";
                else//係數不是1
                cout<<out.elements[i]<<"x";
            }
            else if (i != 0 )//不是第一項
            {
                if (out.elements[i]>0)//係數>0
                {
                    if (out.elements[i]==1)//係數等於1的時候
                    cout<<"+x";
                    else//係數不是1的時候
                    cout<<"+"<<out.elements[i]<<"x";
                }
                else if (out.elements[i]<0)//係數小於0
                {
                    cout<<out.elements[i]<<"x";
                }

            }

        }
    }
    return cout;

}
