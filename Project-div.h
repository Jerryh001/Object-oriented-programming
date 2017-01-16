
Polynomial operator /(const Polynomial& c,const Polynomial& d)//求商式
{
    Polynomial a,b;
    a=c;b=d;
    Polynomial ans1;//商
    Polynomial ans2;//餘
    //int a.powers[100]={3,1,0,0,0,0,0,0,0,0,0,0,0,0},b.powers[100]={1,0,0,0,0,0,0,0},ans1.powers[100]={0},anspr[100]={0};
    //double  a.elements[100]={1,2,1,0,0,0,0,0,0,0,0,0,0,0},b.elements[100]={1,1,0,0,0,0,0,0},ans1.elements[100]={0},anscr[100]={0};
    int l=0;
    ans1.powers[l]=a.powers[0]-b.powers[0];
    ans1.elements[l]=a.elements[0]/b.elements[0];
    //cout<<ans1.powers[l]<<" "<<ans1.elements[l]<<endl;
    while(1)
    {
        int temp=0;
        for(int x=0;;x++)
        {
            if(b.powers[x]==0&&b.elements[x]==0)break;
            b.powers[x]+=ans1.powers[l];
            b.elements[x]*=ans1.elements[l];
        }
        int ansp[100]={0},i=0,j=0,k=0;
        double ansc[100]={0};
        while(2)//使a多項式與乘過商的b多項式相減
        {
            if((a.powers[i]==0)&&(b.powers[j]==0)&&(a.elements[i]==0)&&(b.elements[j]==0))//如果次方和系數=0 break
            {
                break;
            }
            if(a.powers[i]>b.powers[j])
            {
                ansp[k]=a.powers[i];
                ansc[k]=a.elements[i];
                j--;
            }
            else if(a.powers[i]==b.powers[j])
            {
                if((a.elements[i]-b.elements[j])==0)
                {
                    i++;
                    j++;
                    continue;
                }
                else
                {
                    ansp[k]=a.powers[i];
                    ansc[k]=a.elements[i]-b.elements[j];
                }
            }
            else if(a.powers[i]<b.powers[j])
            {
                ansp[k]=b.powers[j];
                ansc[k]=-b.elements[j];
                i--;
            }
            temp++;
            i++;
            j++;
            k++;
        }
        for(int x=0;;x++)
        {
            a.powers[x]=ansp[x];
            a.elements[x]=ansc[x];
            if(ansp[x]==0&&ansc[x]==0)break;
        }
        for(int x=0;;x++)
        {
            if((b.powers[x]==0)&&(b.elements[x]==0))break;
            b.powers[x]-=ans1.powers[l];
            b.elements[x]/=ans1.elements[l];
        }
        if(a.powers[0]==0&&temp==0)
        {
            //cout<<"========"<<endl<<temp<<endl;
            break;
        }
        if(a.powers[0]<b.powers[0])
        {
            //cout<<"========"<<endl;
            for(int x=0;;x++)
            {
                if(a.powers[x]==0&&a.elements[x]==0)break;
                ans2.powers[x]=a.powers[x];
                ans2.elements[x]=a.elements[x];
                //cout<<a.powers[x]<<" "<<a.elements[x]<<endl;
            }
            break;
        }
        l++;
        ans1.powers[l]=a.powers[0]-b.powers[0];
        ans1.elements[l]=a.elements[0]/b.elements[0];
        //cout<<ans1.powers[l]<<" "<<ans1.elements[l]<<endl;
    }
    ans1.refresh();
    return ans1;
}







