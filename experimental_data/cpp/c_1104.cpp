#include<bits/stdc++.h>

using namespace std;
#define sf scanf
#define pf prinf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("d",&a,&b)
#define sf3(a,b,c) scanf("d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("dd",&a,&b,&c,&d)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("lld",&a,&b)
#define sf3ll(a,b,c) scanf("lld%lld",&a,&b,&c)
#define sf4ll(a,b,c,d) scanf("lldlld",&a,&b,&c,&d)
#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define pb push_back
#define ppb pop_back
#define pbf push_front
#define ppf pop_front
#define fs first
#define sc second
#define mem(ar,vl) memset((ar),vl,sizeof(ar))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long int,long long int>
#define mkp make_pair
#define max3(m1,m2,m3) max(max(m1,m2),m3)
#define min3(m1,m2,m3) min(min(m1,m2),m3)
#define PI acos(-1.0)
#define INF 10000000000

#define popc(ct) (__builtin_popcount(a))
#define fast ios_base::sync_with_stdio(false)
#define file freopen("input.txt","r",stdin)


template<class T1> void myprint(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void myprint(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void myprint(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}

//------------------------------------------------------------------------------------------------------------------------
//moves
//int dx[]={0,0,1,-1}            //4 move
//int dy[]={1,-1,0,0}
//int dx[]={0,0,1,1,1,-1,-1,-1}  //8 move
//int dy[]={1,-1,0,1,-1,0,1,-1}
//int dx[]={1,1,2,2,-1,-1,-2,-2} //knight move
//int dy[]={2,-2,1,-1,2,-2,-1,1}

//bigMode
//ll bigmode(ll a,ll b,ll m){if(b==0)return 1%m; ll x=bigmod(a,b/2,m); x=(x*x)%m; if(b%2==1)x=(x*a)%m; return x;}
//ll BigMode(ll B,ll P,ll M){ll R=1%M; while(P>0){if(P%2==1){R=(R*B)%M;} P/=2; B=(B*B)%M;} return R;}  ////(B^P)%M
//std::string toBinary(int n){std::string r; while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;} return r;}


///  <------------------------------------------------------------STRAT------------------------------------------------------------------>
ll a[5][5];
int main()
{
    fast;

string s;
cin>>s;
ll x=1,y=1,p=3,q=1;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='0')
    {
        cout<<x<<" "<<y<<endl;
        y++;
        if(y==5) y=1;

    }
    else
    {
        cout<<p<<" "<<q<<endl;
        q+=2;
        if(q==5) q=1;
    }
}

    return 0;
}