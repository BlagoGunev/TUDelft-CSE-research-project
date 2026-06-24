#include <bits/stdc++.h>
#define llt long long
using namespace std;

int m,n,a[100001],b[100001],ans=2100000000;

void f(int s,int e,int bit,int now)
{
    //printf("%d %d %d %d\n",s,e,bit,now);
    if(bit<0)
    {
        int mmax=0;
        for(int i=s;i<=e;i++) mmax=max(mmax,now^b[i]);
        ans=min(ans,mmax);
    }
    else
    {
        int one=-1;
        for(int i=s;i<=e;i++)
        {
            if((1<<bit)&b[i])
            {
                one=i;
                break;
            }
        }
        if(one==-1) f(s,e,bit-1,now);
        else if(one==s) f(s,e,bit-1,now|(1<<bit));
        else
        {
            f(s,one-1,bit-1,now|(1<<bit));
            f(one,e,bit-1,now);
        }
    }
}

int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    a[0]=-1;
    for(int i=1;i<=m;i++)
        if(a[i]>a[i-1]) b[++n]=a[i];
    f(1,n,30,0);
    printf("%d",ans);
}