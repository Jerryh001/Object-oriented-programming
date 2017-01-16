/*對多項式進行微分，次方乘以係數，次方再減一。*/

 void Polynomial::derivative()
{
 /*int powers[100]={5,4,3,2,1,0,0};
 float si[100]={8,-5,2,7.4,-2.2,0,0};*/

         for(int i=0;i<100;i++)
         {
            if(elements[i]==0&&powers[i]==0)
             break;
          elements[i] = powers[i]*elements[i];
          powers[i] = powers[i]-1;
         }

      /*for(int j=0;j<100;j++)
      {
          if(powers[j]==0&&powers[j+1]==0)
          {
           cout<<"0";
           break;
          }
       cout<<powers[j]<<" ";
      }
      cout<<endl;

      for(int k=0;k<100;k++)
      {
          if(elements[k]==0)
          break;
       cout<<elements[k]<<" ";*/
       }

