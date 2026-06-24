#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
   int n,m,temp,i,x;
   
   cin>>n>>m;
   if(n<m)
   { temp=n;
     n=m;
     m=temp;
   }
   
   cout<<m+1<<"\n";
   x=m;
   
  /* for(i=0;i<m;i++,x--)
   { cout<<i<<" "<<x<<"\n";
   }
   cout<<m<<" 0";
   */
   
   for(i=0;i<m+1;i++)
   {cout<<i<<" "<<m-i<<endl;
   }

   
 // system("pause");
}