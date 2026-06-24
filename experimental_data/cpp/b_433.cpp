#include <bits/stdc++.h>
#define make_it_fast ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const double eps=1e-11;
//const double pi=acos(-1.0);
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;

#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
typedef std::pair<int,int> pii ;
typedef std::vector<int> vi ;
#define lpu(i,s,e) for(i=s;i<e;i++)
#define lpd(i,s,e) for(i=s;i>e;i--)
#define lpui(i,s,e) for(i=s;i<=e;i++)
#define lpdi(i,s,e) for(i=s;i>=e;i--)
#define abs(a) (a<0?-(a):a)
#define nl() cout << '\n'
#define nlf() cout << endl

template <class T> inline void swap(T& a,T &b){ a^=b; b^=a; a^=b; }
template <class T> inline T min(T& a,T &b){ if(a<b) { return a; } else return b; }
template <class T> inline T max(T& a,T &b){ if(a>b) { return a; } else return b; }

# define getcx getchar

template <class T>
void inp(T& n)//fast input function
{
    n=0;
    int ch=getcx();
    int sign=1;
    while( ch < '0' || ch > '9' )
        {if(ch=='-')sign=-1; ch=getcx();}
    while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}

template <class T>
void oup(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    int len=0,data[25];
    while(x)
    {
        data[len++]=x%10;
        x/=10;
    }
    if(!len)
        data[len++]=0;
    while(len--)
        putchar(data[len]+48);
    putchar('\n');
}


int main()
{
    // make_it_fast
    #ifdef LOCAL
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    lli n,m,i,tp,typ,l,r;
    vector<lli> a;
    vector<lli> sum;
    vector<lli> ssum;

    inp(n);
    lpu(i,0,n) {
        inp(tp); a.pb(tp); 
    }
    // lpu(i,0,n) cout << a[i] << ' ';
    // cout << endl;
    lpu(i,0,n){
        if(i>0) sum.pb(a[i]+sum[i-1]);
        else sum.pb(a[i]);
    }
    // lpu(i,0,n) cout << sum[i] << ' ';
    // cout << endl;
    sort(a.begin(),a.end());
    // lpu(i,0,n) cout << a[i] << ' ';
    // cout << endl;
    lpu(i,0,n){
        if(i>0) ssum.pb(a[i]+ssum[i-1]);
        else ssum.pb(a[i]);
    }
    // lpu(i,0,n) cout << ssum[i] << ' ';
    // cout << endl;
    inp(m);
    lpu(i,0,m){
        inp(typ); inp(l); inp(r); l--; r--;
        if(typ==1){
            if(l>0) oup(sum[r]-sum[l-1]);
            else oup(sum[r]);
        }else if(typ==2){
            if(l>0) oup(ssum[r]-ssum[l-1]);
            else oup(ssum[r]);
        }
    }
    return 0;
}