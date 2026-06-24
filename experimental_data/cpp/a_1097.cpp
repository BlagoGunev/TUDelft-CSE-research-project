#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{int c=1;
    char a[4];
    char s[5][2];
    for(int k=0;k<2;k++)
    {
       cin>>a[k]; 
    }
     
    for(int i=0;i<5;i++)
    {
       for(int j=0;j<2;j++)
       {
           cin>>s[i][j];
       }
    }
    for(int i=0;i<5;i++)
    {
       for(int j=0;j<2;j++)
       {
           if(s[i][j]==a[0]||s[i][j]==a[1])
           c++;
    
           
       }
    }
    if(c>1)
    cout<<"YES";
    else
    cout<<"NO";
}