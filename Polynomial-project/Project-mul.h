
Polynomial operator *(const Polynomial& a,const Polynomial& b)//���k
{
    Polynomial ans;
    int k=0;
    //int a.powers[100]={5,3,1,0,0},b.powers[100]={4,3,1,0,0},ans.powers[100]={0},k=0;
    //double  a.elements[100]={1,2.1,-3,4,0},b.elements[100]={1,2,3,4,0},ans.elements[100]={0};
    for(int i=0;;i++)//a���h�����q�Ĥ@�Ӷ}�l���Wb���h����
    {
        if(a.powers[i]==0&&a.elements[i]==0)break;//�p�G����M�t��=0 break
        for(int j=0;;j++)
        {
            if(b.powers[j]==0&&b.elements[j]==0)break;
            ans.powers[k]=a.powers[i]+b.powers[j];
            ans.elements[k]=a.elements[i]*b.elements[j];
            //cout<<ans.powers[k]<<" "<<ans.elements[k]<<endl;
            k++;
        }
    }
    ans.refresh();
    return ans;
}
