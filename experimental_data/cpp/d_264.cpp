#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n,m;
const int MAXN=1000005;
char a[MAXN],b[MAXN];
int mi[MAXN],ma[MAXN];
long long ans=0;
int trs(char a,char b)
{
    int s=0;
    if(a=='R') s+=6;
    else if(a=='B') s+=3;
    if(b=='R') s+=2;
    else if(b=='B') s+=1;
    return s;
}

int s[MAXN][10];
int main()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    n=strlen(a+1),m=strlen(b+1);
    for(int i=2;i<=m;i++)
    {
        for(int j=0;j<=9;j++) s[i][j]=s[i-1][j];
        if(b[i]!=b[i-1])
        s[i][trs(b[i],b[i-1])]++;
    //  cout<<trs(b[i],b[i-1])<<' '<<b[i]<<' '<<b[i-1]<<endl;
    //  for(int j=0;j<=9;j++) cout<<s[i][j]<<' ';cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1) mi[i]=ma[i]=1;
        else mi[i]=mi[i-1],ma[i]=ma[i-1];
        if(i!=1&&a[i-1]==b[mi[i]]) mi[i]++;
        if(i!=1&&ma[i]!=m) ma[i]++;
        while(ma[i]!=m&&b[ma[i]]!=a[i]) ma[i]++;
        ans+=ma[i]-mi[i]+1;
        if(i!=1)
        {
            ans-=s[ma[i]][trs(a[i-1],a[i])]-s[mi[i]-1][trs(a[i-1],a[i])];
        //  cout<<s[ma[i]][trs(a[i-1],a[i])]-s[mi[i]-1][trs(a[i-1],a[i])]<<' '<<mi[i]<<' '<<ma[i]<<endl;
        }
    }
    printf("%I64d\n",ans);
    
    return 0;
}
/*
BRGBRGBRGBRRRRGGG
RBGRBGBRBGBRGBRBGRRRRGGG
*/