#include<bits/stdc++.h>

using namespace std;

int main()

{

   int n,m,x,y,c=0;

   cin>>n>>m;

   int a[m]={0};

   for(int i=1;i<=n;i++)

   {

       cin>>x;

       for(int j=1;j<=x;j++)

       {

           cin>>y;

           a[y-1]++;

       }

   }

   for(int i=0;i<m;i++)

   {

       if(a[i]>0)

       c++;

   }

   if(c==m)

   cout<<"YES";

   else

   cout<<"NO";

}