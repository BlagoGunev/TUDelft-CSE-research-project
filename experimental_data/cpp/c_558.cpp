#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <cstdio>
#include <string>
#include<string.h>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define exp 1e-8
#define INF 0x3f3f3f3f
#define ll long long
#define mm(a,b) memset(a,b,sizeof(a));
#define for1(a,b) for(int a=1;a<=b;a++)//1---(b)
#define rep(a,b,c) for(int a=b;a<=c;a++)//b---c
void bug(string st="bug")
{cout<<st<<endl;}
template<typename __ll>
inline void READ(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
template<typename __ll>
inline void read(__ll &m){READ(m);}
template<typename __ll>
inline void read(__ll &m,__ll &a){READ(m);READ(a);}
template<typename __ll>
inline void read(__ll &m,__ll &a,__ll &b){READ(m);READ(a);READ(b);}
int num[100010];
int two[100010][22];
int idx[100010];
int cnt[100010];
int main()
{
    int n;
    read(n);
    for1(i,n)read(num[i]);
    int minn=0;
    for1(i,n)
    {
        int tmp=num[i];
        cnt[i]=0;
        while(tmp)
        {
            two[i][++cnt[i]]=tmp%2;
            tmp/=2;
        }
    }
    int ccc=0;
    for(int j=0;j<=20;j++)
    {
        int flag=1;
            if(cnt[1]-j<1)flag=0;
            if(flag==0)break;
        int tmp=two[1][cnt[1]-j];
        for(int i=2;i<=n;i++)
        {
            if(cnt[i]-j<1||cnt[i]-j<1){flag=0;break;}
            if(two[i][cnt[i]-j]!=tmp)
                flag=0;
        }
        if(flag==0)break;
        minn+=tmp;
        if(j==20)
        {
            cout<<0<<endl;
            return 0;
        }

    }
    int ans=0;
    for1(i,n)
    {
        int tmp=minn;
        int first=-1;
        for(int j=20;j>=1;j--)
        {
            if(two[i][j]==1&&first==-1)first=j;
            tmp-=two[i][j];
            if(tmp==-1)
            {
                ans+=j;
                idx[i]=first-j;
                break;
            }
        }
        if(tmp==0)
            idx[i]=first;
    }
    sort(idx+1,idx+1+n);
    int mid=idx[n/2+1];
    for1(i,n) ans+=abs(idx[i]-mid);
    cout<<ans<<endl;
}