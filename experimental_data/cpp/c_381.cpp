#pragma comment(linker,"/STACK:102400000,102400000")
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#define sf scanf
#define pf printf
#define fst first
#define scd second
#define pb push_back
#define mkp make_pair
#define cls(a,x) memset(a,x,sizeof a)
#define dt(x) cout<<#x<<"="<<x<<" ";
#define dte(x) cout<<#x<<"="<<x<<endl;

#if(_WIN32||__WIN32_)
typedef __int64 LL;
#define lld I64d
#else
typedef long long LL;
#endif

using namespace std;
//template<class T>inline T gcd(T a,T b){while(b){T t=a%b;a=b;b=t;} return a;}
template<class T>inline void read(T &v)
{
    char ch;
    while(ch=getchar())
        if(ch<='9' && ch>='0') break;
    v=ch-'0';
    while(ch=getchar())
        if(ch<='9' && ch>='0') v=(v<<1)+(v<<3)+ch-'0';
        else break;
}
typedef pair < int , int > pii;
const double eps=1e-4;
const int MX=111111;

LL inx[MX],iny[MX],inc[MX];
LL inn[MX];
vector<LL>vec;
int main()
{
    int i,j,k;
    LL n,m;
    vec.clear();
    read(m);
    for(i=0;i<m;++i)
    {
        read(inx[i]);
        read(iny[i]);
        if(2==inx[i])
            read(inc[i]);
    }
    read(n);
    for(i=0;i<n;++i)
    {
        read(inn[i]);
    }
    LL now=0,nown=0,size=0;
    for(i=0;i<m,nown<n;++i)
    {
        if(inx[i]==1)
        {
            now++;
            vec.pb(iny[i]);
            ++size;
            if(now>=inn[nown])
            {
                pf("%I64d ",iny[i]);
                nown++;
                if(nown>=n)
                    return 0;
            }
        }else
        {
            for(k=0;k<inc[i]&&size<100000;++k)
            {
                for(j=0;j<iny[i]&&size<100000;++j)
                {
                    LL tmp=vec[j];
                    vec.pb(tmp);
                    ++size;
                }
            }
            if(iny[i]*inc[i]+now>=inn[nown])
            {
                while(nown<n && iny[i]*inc[i]+now>=inn[nown])
                {
                    LL res=(inn[nown]-now)%iny[i]-1;
                    if(res<0)
                        res=iny[i]-1;
                    pf("%I64d ",vec[res]);
                    ++nown;
                }
            }
            now=iny[i]*inc[i]+now;
        }
    }
    return 0;
}