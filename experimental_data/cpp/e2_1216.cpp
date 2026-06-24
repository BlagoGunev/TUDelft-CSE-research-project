#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
#define enable_ll
#ifdef enable_ll
    #define int long long
#endif
#ifdef DEBUG
    #define out(u) cout<<u<<" "
    #define outln(u) cout<<u<<endl
    #define see(u) cout<<#u<<"="<<u<<" "
    #define seeln(u) cout<<#u<<"="<<u<<endl
    #define line cout<<"---------------------\n"
#else
    #define out(u)
    #define outln(u)
    #define see(u)
    #define seeln(u)
    #define line
#endif
#define m_p make_pair
#define pii pair<int,int>
#define piii pair<int,pii>
#define sz(x) x.size()
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
template <class T> void read(T &u)
{
    u=0; char c=getchar(); int flag=0;
    while (c<'0'||c>'9') flag|=(c=='-'),c=getchar();
    while (c>='0'&&c<='9') u=(u<<3)+(u<<1)+(c^48),c=getchar();
    if (flag) u=-u;
}
template <class T> bool checkmin(T &a,T b){return (b<a ? a=b,1 : 0);}
template <class T> bool checkmax(T &a,T b){return (b>a ? a=b,1 : 0);}
template <class T> T _min(T &a,T &b){return (a<b ? a : b);}
template <class T> T _max(T &a,T &b){return (a>b ? a : b);}
int C[]={45,9045,1395495,189414495,23939649495,2893942449495,339393974949495,38939394344949495,9000000000000000000};
int D[]={9,189,2889,38889,488889,5888889,68888889,788888889,8888888889};
void init()
{
}
 
int calc(int lim,int res)
{
    //cout<<lim<<" "<<res<<" "<<D[7]<<endl;
    int pos=8;
    for (int i=0;i<=8;++i)
    {
        if (D[i]==res)
        {
            return 9;
        }
        if (D[i]>res)
        {
            pos=i;
            if (i>0)
            {
                res-=D[i-1];
                //cout<<res<<endl;
            }
            break;   
        }
    }
    //cout<<res<<" "<<pos<<endl;
    int num=1;
    for (int i=1;i<=pos;++i)
    {
        num=num*10;
    }
    //cout<<num<<endl;
    int tim=res/(pos+1)+num;
    res%=(pos+1);
    //cout<<tim<<" "<<res<<endl;
    if (res==0)
    {
        return (tim-1)%10;
    }
    vector <int> v;
    while (tim)
    {
        v.push_back(tim%10);
        tim/=10;
    }
    reverse(v.begin(),v.end());
    return v[res-1];
}

string s="112123123412345123456123456712345678123456789";
void solve()
{
    int x;
    read(x);
    if (x<=45)
    {
        printf("%c\n",s[x-1]);
        return;
    }
    int pos=-1;
    for (int i=0;i<8;++i)
    {
        if (x==C[i])
        {
            printf("9\n");
            return;
        }
        if (x>C[i])
        {
            pos=i;
        }
    }
    pos++;
    int num=1;
    for (int i=1;i<=pos;++i)
    {
        num=num*10;
    }
    int beg=D[pos-1],step=pos+1;
    x-=C[pos-1];
    //cout<<pos<<" "<<beg<<" "<<num<<" "<<x<<" "<<step<<endl;
    int l=0,r=num*9,mid,best=-1;
    while (l<=r)
    {
        mid=(l+r)>>1;
        if (beg*mid+mid*(mid+1)/2*step<=x)
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    //cout<<"best="<<best<<endl;
    x-=(beg*best+best*(best+1)/2*step);
    if (x==0)
    {
        printf("%lld\n",(best+num-1)%10);
        return;
    }
    printf("%lld\n",calc(num+best,x));
} 
       
#undef int
int main()
{
    init();
    int Q;
    read(Q);
    while (Q--)
    {
        solve();
    }
    return 0;
}