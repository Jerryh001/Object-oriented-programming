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
if (formula[0]=='-')//�B�z�Ĥ@��
    {
        i=i+1;
        if (isdigit(formula[i]))//�t������O�Ʀr
        {
            while (isdigit(formula[i]))
            {
                name.elements[0]=10*name.elements[0]+formula[i]-'0';
                i++;

            }
            if(formula[i]=='.')//���Ū����Y���p���I
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

            if (formula[i]=='x')//�ƦrŪ������Ox
            {
                i=i+1;
                if (formula[i]=='^')//x�᭱�O^�A�N����Ƥ���1
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
        else if (formula[i]=='x')//�t������p�G������x
            {
                name.elements[0]=-1;
                i=i+1;
                if (formula[i]=='^')//x�᭱�p�G�O^��ܫ��Ƥ��O1
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
else if (isdigit(formula[0]))//�p�G�Ĥ@���@�}�l�O�Ʀr
{
        while (isdigit(formula[i]))
        {
            name.elements[0]=10*name.elements[0]+formula[i]-'0';
            i++;
        }
        if(formula[i]=='.')//���Ū������O�p���I
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
        if (formula[i]!='x')//�Ʀr��Ū���ᤣ�Ox��ܫ��Ƭ�0
        {
            name.powers[0]=0;
        }
        else
        {
            i=i+1;
            if (formula[i]=='^')//��ܫ��Ƥ@�w����0
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
else if (formula[0]=='x')//�Ĥ@���@�}�l�N�Ox
{
        name.elements[0]=1;
        i=i+1;
        if (formula[i]!='^')//�Yx�᭱���O^��ܫ��Ƭ�0
        {
            name.powers[0]=1;
        }
        else if (formula[i]=='^')//��ܫ��Ƥ@�w���O0
        {
            i=i+1;
            while (isdigit(formula[i]))
            {
                name.powers[0]=10*name.powers[0]+formula[i]-'0';
                i++;
            }
        }
}//�Ĥ@���B�z����
    for ( ; i < len_formula ; )//�B�z�Ĥ@���H�~��
    {

        if (formula[i]=='+')//�Y�O+��
        {
            i=i+1;
            if (isdigit(formula[i]))//+���᭱�����O�Ʀr
            {
                while (isdigit(formula[i]))
                {
                    name.elements[j]=10*name.elements[j]+formula[i]-'0';
                    i++;
                }
                if(formula[i]=='.')//���Ū������O�p���I
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

                if (formula[i]=='x')//�ƦrŪ������Ox
                {
                    i=i+1;
                    if (formula[i]!='^')//x�᭱���O��^��ܫ��Ƭ�1
                    {
                        name.powers[k]=1;
                    }
                    else if (formula[i]=='^')//��ܫ��Ƥ@�w���O1
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
            else if (formula[i]=='x')//+���᭱������x
            {

                name.elements[j]=1;
                j=j+1;
                i=i+1;
                if(formula[i]=='^')//x�᭱�O^
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
        else if (formula[i]=='-')//�@�}�lŪ�J�O�t��
        {
            i=i+1;
            if (isdigit(formula[i]))//�t�����Ʀr
            {
                while (isdigit(formula[i]))
                {
                    name.elements[j]=10*name.elements[j]+formula[i]-'0';
                    i++;
                }
                if(formula[i]=='.')//���Ū��Ū�p��
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

                if (formula[i]=='x')//�ƦrŪ�����ᱵx
                {
                    i=i+1;
                    if (formula[i]=='^')//x����O^
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
        else if (formula[i]=='x')//�t�����᪽����x
        {
                name.elements[j]=-1;
                j=j+1;
                i=i+1;
                if (formula[i]!='^')//x�᭱���O^
                {
                    name.powers[k]=1;
                }
                else if (formula[i]=='^')//x�᭱�O^
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
        else{i++;}// ��J�p�G���ŦX�W�w����
        if(k>=100||j>=100) break;
    }
    //name.refresh();
return cin;
}
