istream& operator >>(istream& cin,Polynomial& name)
{
    name.polyclear();
    string formula;

    int len_formula;
    cin>>formula;
    len_formula=formula.length();
    int i = 0;
    int j = 1 ;
    int k =1;
if (formula[0]=='-')//處理第一項
    {
        i=i+1;
        if (isdigit(formula[i]))//負號之後是數字
        {
            while (isdigit(formula[i]))
            {
                name.elements[0]=10*name.elements[0]+formula[i]-'0';
                i++;

            }
            if(formula[i]=='.')//整數讀完後若有小數點
            {
                int count=0;
                i=i+1;
                while (isdigit(formula[i]))
                {
                    name.elements[0]=10*name.elements[0]+formula[i]-'0';
                    i++;
                    count++;
                }

                name.elements[0]=name.elements[0]/pow(10 , count);
                name.elements[0]=-name.elements[0];

            }

            if (formula[i]=='x')//數字讀完之後是x
            {
                i=i+1;
                if (formula[i]=='^')//x後面是^，代表指數不為1
                {
                    i+=1;
                    while (isdigit(formula[i]))
                    {
                        name.powers[0]=10*name.powers[0]+formula[i]-'0';
                        i++;
                    }
                }
            }



        }
        else if (formula[i]=='x')//負號之後如果直接接x
            {
                name.elements[0]=-1;
                i=i+1;
                if (formula[i]=='^')//x後面如果是^表示指數不是1
                {
                    i+=1;
                    while (isdigit(formula[i]))
                    {
                        name.powers[0]=10*name.powers[0]+formula[i]-'0';
                        i++;
                    }
                }
            }





    }
else if (isdigit(formula[0]))//如果第一項一開始是數字
{
        while (isdigit(formula[i]))
        {
            name.elements[0]=10*name.elements[0]+formula[i]-'0';
            i++;
        }
        if(formula[i]=='.')//整數讀完之後是小數點
        {
            int count=0;
            i=i+1;
            while (isdigit(formula[i]))
            {
                name.elements[0]=10*name.elements[0]+formula[i]-'0';
                i++;
                count++;
            }

            name.elements[0]=name.elements[0]/pow(10 , count);
        }
        if (formula[i]!='x')//數字都讀完後不是x表示指數為0
        {
            name.powers[0]=0;
        }
        else
        {
            i=i+1;
            if (formula[i]=='^')//表示指數一定不為0
            {
                i+=1;
                while (isdigit(formula[i]))
                {
                    name.powers[0]=10*name.powers[0]+formula[i]-'0';
                    i++;

                }

            }

        }
}
else if (formula[0]=='x')//第一項一開始就是x
{
        name.elements[0]=1;
        i=i+1;
        if (formula[i]!='^')//若x後面不是^表示指數為0
        {
            name.powers[0]=1;
        }
        else if (formula[i]=='^')//表示指數一定不是0
        {
            i=i+1;
            while (isdigit(formula[i]))
            {
                name.powers[0]=10*name.powers[0]+formula[i]-'0';
                i++;
            }
        }
}//第一項處理結束
    for ( ; i < len_formula ; )//處理第一項以外的
    {

        if (formula[i]=='+')//若是+號
        {
            i=i+1;
            if (isdigit(formula[i]))//+號後面接的是數字
            {
                while (isdigit(formula[i]))
                {
                    name.elements[j]=10*name.elements[j]+formula[i]-'0';
                    i++;
                }
                if(formula[i]=='.')//整數讀完之後是小數點
                {
                    int count=0;
                    i=i+1;
                    while (isdigit(formula[i]))
                    {
                        name.elements[j]=10*name.elements[j]+formula[i]-'0';
                        i++;
                        count++;
                    }

                    name.elements[j]=name.elements[j]/pow(10 , count);
                    //name.elements[j]=-name.elements[j];
                }

                if (formula[i]=='x')//數字讀完之後是x
                {
                    i=i+1;
                    if (formula[i]!='^')//x後面不是接^表示指數為1
                    {
                        name.powers[k]=1;
                    }
                    else if (formula[i]=='^')//表示指數一定不是1
                    {
                        i=i+1;
                        while (isdigit(formula[i]))
                        {
                            name.powers[k]=10*name.powers[k]+formula[i]-'0';
                            i++;
                        }

                    }

                }
                k=k+1;
                j=j+1;
            }
            else if (formula[i]=='x')//+號後面直接接x
            {

                name.elements[j]=1;
                j=j+1;
                i=i+1;
                if(formula[i]=='^')//x後面是^
                {
                    i=i+1;
                    while (isdigit(formula[i]))
                    {
                        name.powers[k]=10*name.powers[k]+formula[i]-'0';
                        i++;
                    }
                }
                else
                {
                    name.powers[k]=1;
                }
                k=k+1;
            }
        }
        else if (formula[i]=='-')//一開始讀入是負號
        {
            i=i+1;
            if (isdigit(formula[i]))//負號接數字
            {
                while (isdigit(formula[i]))
                {
                    name.elements[j]=10*name.elements[j]+formula[i]-'0';
                    i++;
                }
                if(formula[i]=='.')//整數讀完讀小數
                {
                    int count=0;
                    i=i+1;
                    while (isdigit(formula[i]))
                    {
                        name.elements[j]=10*name.elements[j]+formula[i]-'0';
                        i++;
                        count++;
                    }
                    name.elements[j]=name.elements[j]/pow(10 , count);


                }name.elements[j]=-name.elements[j];

                if (formula[i]=='x')//數字讀完之後接x
                {
                    i=i+1;
                    if (formula[i]=='^')//x之後是^
                    {
                        i+=1;
                        while (isdigit(formula[i]))
                        {
                            name.powers[k]=10*name.powers[k]+formula[i]-'0';
                            i++;
                        }

                    }
                    else if (formula[i]!='^')
                    {
                        i+=1;
                        name.powers[k]=1;
                    }

                    k+=1;
                    j+=1;
                }
                else if (formula[i]!='x')
                {
                    i=i+1;
                    name.powers[k]=0;

                }
                k=k+1;
                j=j+1;

        }
        else if (formula[i]=='x')//負號之後直接接x
        {
                name.elements[j]=-1;
                j=j+1;
                i=i+1;
                if (formula[i]!='^')//x後面不是^
                {
                    name.powers[k]=1;
                }
                else if (formula[i]=='^')//x後面是^
                {
                    i=i+1;
                    while (isdigit(formula[i]))
                    {
                        name.powers[k]=10*name.powers[k]+formula[i]-'0';
                        i++;
                    }


                }
                k=k+1;
        }
    }
        else{i++;}// 輸入如果不符合規定的話
        if(k>=100||j>=100) break;
    }
    //name.refresh();
return cin;
}
