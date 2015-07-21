/*對多項式進行積分，係數除以次方加一，次方再加一。*/


void Polynomial::integral(float C)
{
 /*int powers[100]={5,4,3,2,1,0,0};
 float elements[100]={8,-5,2,7.4,-2.2,0,0};
 float C = 5.5;*/

         for(int i=0;i<100;i++)
         {
           if(elements[i]==0&&powers[i]==0&&powers[i+1]==0)
           {
            powers[i] = powers[i]+1;
            elements[i+1] = C;
            break;
           }
           if(elements[i]==0&&powers[i]==0)
           {
            elements[i] = C;
            break;
           }
          elements[i] = elements[i]/(powers[i]+1);
          powers[i] = powers[i]+1;
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
          if(powers[k]==0)
          {
           cout<<C;
           break;
          }
       cout<<elements[k]<<" ";*/


}

