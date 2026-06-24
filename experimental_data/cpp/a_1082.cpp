#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,ab=0;
    cin>>t;
     double sum=0,cum=0;
               long long int k1=-1,k2=-1,k3=-1;
    long long int n,x,y,d;
    while(t--)
     {
         cin>>n>>x>>y>>d;
         int c=0,min=1000000000;
         ab=abs(x-y)%d;
         if(ab==0)
          {
              k1=abs(x-y)/d;
              c++;
              min=k1;
          }
         if((y-1)%d==0)
           {
              cum=0;
                cum=ceil((x-1)/(d*1.0)) ;
                k2=cum+ (y-1)/d;
                c++;
                if(min>k2)
                min=k2;
                 
           }
          if((n-y)%d==0)
           {
            //  k=0;
              cum=0;
                cum=ceil((n-x)/(d*1.0));
                k3=cum+ (n-y)/d;
                c++;
                if(min>k3)
                min=k3;
           }
           if(c==0)
           {
               cout<<"-1"<<endl;
           }
           else
           cout<<min<<endl;
     }
}