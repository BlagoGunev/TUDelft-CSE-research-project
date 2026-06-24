#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

char a[100010],b[100010];

int main()
{
    int t,x,y,k,lx,ly,i,xx,yy;
    cin>>t;
    while(t--)
    {
       int f=0;
       k=0,i=0;
       scanf("%s",a);
       scanf("%s",b);
       lx=strlen(a);
       ly=strlen(b);
       for(xx=lx,yy=ly;xx>=0,yy>=0;)
       {
          if(f==0)
          {
             if(b[yy]=='1')
             {
                f=1;
             }
             else
             {
                xx--;yy--;
             }
          }
          if(f)
          {
             if(a[xx]=='1')
             {
                break;
             }
             else
             {
                k++;xx--;
             }
          }
       }
       cout<<k<<endl;
    }
    return 0;
}