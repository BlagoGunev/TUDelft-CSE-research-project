//{{{
#include <bits/stdc++.h>
using namespace std;
//types
typedef long long ll;
typedef pair<int,int> pii;
//input
bool SR(int &_x){return scanf("%d",&_x)==1;}bool SR(ll &_x){return scanf("%" PRId64,&_x)==1;}
bool SR(double &_x){return scanf("%lf",&_x)==1;}bool SR(char *_s){return scanf("%s",_s)==1;}
bool RI(){return true;}
template<typename I,typename... T>bool RI(I &_x,T&... _tail){return SR(_x) && RI(_tail...);}
//output
void SP(const int _x){printf("%d",_x);}void SP(const ll _x){printf("%" PRId64,_x);}
void SP(const double _x){printf("%.16lf",_x);}void SP(const char *s){printf("%s",s);}
void PL(){puts("");}
template<typename I,typename... T>void PL(const I _x,const T... _tail)
{SP(_x);if(sizeof...(_tail)) putchar(' ');PL(_tail...);}
//macro
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
#define pb push_back
#define mkp make_pair
#define F first
#define S second
//debug
#ifdef darry140
template<typename I>
void _DOING(const char *_s,I&& _x){cerr<<_s<<"="<<_x<<endl;}//without ','
template<typename I,typename... T>
void _DOING(const char *_s,I&& _x,T&&... _tail)//with ','
{
    int _c=0;
    static const char _bra[]="({[";
    static const char _ket[]=")}]";
    while(*_s!=',' || _c!=0)//eg. mkp(a,b)
    {
        if(strchr(_bra,*_s)) _c++;
        if(strchr(_ket,*_s)) _c--;
        cerr<<*_s++;
    }
    cerr<<"="<<_x<<", ";
    _DOING(_s+1,_tail...);
}
#define debug(...) do{\
    fprintf(stderr,"%s:%d - ",__PRETTY_FUNCTION__,__LINE__);\
    _DOING(#__VA_ARGS__,__VA_ARGS__);\
}while(0)
template<typename It>
ostream& _OUTC(ostream &_s,It _b,It _e)//container
{
    _s<<"{";
    for(auto _it=_b;_it!=_e;_it++) _s<<(_it==_b?"":" ")<<*_it;
    _s<<"}";
    return _s;
}
template<typename A,typename B>
ostream& operator <<(ostream&_s, const pair<A,B> &_p){return _s<<"("<<_p.F<<","<<_p.S<<")";}
template<typename A,typename B>
ostream& operator <<(ostream&_s, const map<A,B> &_c){return _OUTC(_s,ALL(_c));}
template<typename T>
ostream& operator <<(ostream&_s, const set<T> &_c){return _OUTC(_s,ALL(_c));}
template<typename T>
ostream& operator <<(ostream&_s, const vector<T> &_c){return _OUTC(_s,ALL(_c));}
#else
#define debug(...)
#endif
//}}}
const int maxn=3e5+5;
const int INF=1e9+7;
struct Seg
{
    int dat[maxn<<2];
#define Mid int mid=(low+high)/2
#define lc x<<1,low,mid
#define rc x<<1|1,mid+1,high
#define me x
    void init(int x,int low,int high)
    {
        dat[x]=INF;
        if(low==high) return;
        Mid;init(lc);init(rc);
    }
    void add(int x,int low,int high,int pos,int val)
    {
        if(low==high){dat[x]=min(dat[x],val);return;}
        Mid;
        if(pos<=mid) add(lc,pos,val);
        else add(rc,pos,val);
        dat[x]=min(dat[x<<1],dat[x<<1|1]);
    }
    int ask(int x,int low,int high,int a,int b)
    {
        if(low==a&&b==high) return dat[x];
        Mid;
        if(b<=mid) return ask(lc,a,b);
        else if(mid+1<=a) return ask(rc,a,b);
        else return min(ask(lc,a,mid),ask(rc,mid+1,b));
    }
} seg;
int n,a[maxn];
void read()
{
    RI(n);
    assert(2<=n && n<=100000);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) assert(0<=a[i] && a[i]<INF);
}
vector<int> usel[maxn];
void doo()
{
    vector<int> odr(a+1,a+n+1);
    sort(ALL(odr));odr.erase(unique(ALL(odr)),odr.end());
    seg.init(1,0,SZ(odr)-1);

    for(int i=n;i>=1;i--)
    {
        int p=lower_bound(ALL(odr),a[i])-odr.begin();
        int j=seg.ask(1,0,SZ(odr)-1,p,SZ(odr)-1);
        if(j==INF){seg.add(1,0,SZ(odr)-1,p,i);continue;}
        usel[i].pb(j);
        while(1)
        {
            int q=lower_bound(ALL(odr),(a[i]+a[j]+1)/2)-odr.begin()-1;
            if(p>q) break;
            int k=seg.ask(1,0,SZ(odr)-1,p,q);
            if(k==INF) break;
            else usel[i].pb(j=k);
        }
        seg.add(1,0,SZ(odr)-1,p,i);
    }
}
void build()
{
    doo();
    REP1(i,1,n) a[i]=INF-1-a[i];
    doo();
    REP1(i,1,n) a[i]=INF-1-a[i];
}
struct Bit
{
    int dat[maxn];
    void init(){REP1(i,1,n) dat[i]=INF;}
    void add(int i,int x)
    {
        for(;i<=n;i+=i&-i) dat[i]=min(dat[i],x);
    }
    int ask(int i)
    {
        int ret=INF;
        for(;i>=1;i-=i&-i) ret=min(ret,dat[i]);
        return ret;
    }
} bit;
int l[maxn],r[maxn];
int ans[maxn];
void sol()
{
    int q;RI(q);
    REP1(i,1,q) RI(l[i],r[i]);
    REP1(i,1,q) assert(1<=l[i] && l[i]<r[i] && r[i]<=n);
    
    vector<int> req(q);
    REP(i,q) req[i]=i+1;
    sort(ALL(req),[&](int i,int j){return l[i]>l[j];});
    
    bit.init();
    int lpt=n;
    for(int i:req)
    {
        for(;lpt>=l[i];lpt--) for(auto rpt:usel[lpt])
            bit.add(rpt,abs(a[lpt]-a[rpt]));
        ans[i]=bit.ask(r[i]);
    }

    REP1(i,1,q) PL(ans[i]);
    int siz=0;
    REP1(i,1,n) siz+=SZ(usel[i]);
    debug(siz);
}
int main()
{
    read();
    build();
    sol();
    return 0;
}




































/*End Of File*/