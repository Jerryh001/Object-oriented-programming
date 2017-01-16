
Polynomial operator +(const Polynomial& a,const Polynomial& b)//加法
{
    Polynomial ans;
    //int pow1[100]={5,3,1,0,0},pow2[100]={4,3,1,0,0},ans.powers[100]={0};
    //double  a.elements[100]={1,2.1,-3,4,0},b.elements[100]={1,2,3,4,0},ans.elements[100]={0};
    int i=0,j=0,k=0;
    while(1)
    {
        if(a.powers[i]==0&&b.powers[j]==0&a.elements[i]==0&&b.elements[j]==0)//如果次方和系數=0 break
        {
            break;
        }
        if(a.powers[i]>b.powers[j])
        {
            ans.powers[k]=a.powers[i];
            ans.elements[k]=a.elements[i];
            j--;
        }
        else if(a.powers[i]==b.powers[j])
        {
            ans.powers[k]=a.powers[i];
            ans.elements[k]=a.elements[i]+b.elements[j];
        }
        else if(a.powers[i]<b.powers[j])
        {
            ans.powers[k]=b.powers[j];
            ans.elements[k]=b.elements[j];
            i--;
        }
        //cout<<ans.powers[k]<<" "<<ans.elements[k]<<endl;
        i++;
        j++;
        k++;
    }
    ans.refresh();
    return ans;
}




