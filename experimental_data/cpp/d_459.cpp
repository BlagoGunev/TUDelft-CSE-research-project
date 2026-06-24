#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second


struct BIT{
    int sz;
    int H;
    ll* bit;
    void init()
    {
        REP(i,sz+1) bit[i]=0;
    }
    BIT(int size)
    {
        sz=size>0?size:0;
        bit=new ll[sz+1];
        this->init(); // initialize
        H = 1;
        while(H <= sz) H<<=1;
    }
    ~BIT()
    {
        delete[] bit;
    }
    void add(int i, ll x)
    {
        while(i<=sz)
        {
            bit[i]+=x;
            i+=i&-i;
        }
    }
    ll query(int i)
    {
        ll sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=i&-i;
        }
        return sum;
    }
    int kth(int k)
    {
        int r = 0, h = H;
        while(h>>=1)
        {
            r += h;
            if(r > sz || bit[r] >= k)
                r -= h;
            else
                k -= bit[r];
        }
        int i = r+1;
        while(i<=sz)
        {
            bit[i]--;
            i += i&-i;
        }
        return r;
    }
};

int a[1000000];
PII p[1000000];
int v1[1000000];
int v2[1000000];
int f1[1000000];
int f2[1000000];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n){cin>>a[i]; p[i]=MP(a[i],i);}
    sort(p,p+n);
    int k=0;
    REP(i,n)
    {
        if(!i || p[i].X!=p[i-1].X)
        {
            a[p[i].Y]=k++;
        }else{
            a[p[i].Y]=k-1;
        }
    }
    REP(i,n)
        f1[i] = ++v1[a[i]];
    DEP(i,n-1,0)
        f2[i] = ++v2[a[i]];
    ll ans=0;
    BIT bit(1000010);
    DEP(i,n-1,0)
    {
        ans += bit.query(f1[i]-1);
        bit.add(f2[i],1);
    }
    cout<<ans<<endl;
    return 0;
}