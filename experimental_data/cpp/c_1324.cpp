#include<bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef unsigned long long          ull;
typedef vector<int>                 vi;
typedef vector<ll>                  vll;
typedef vector<vi>                  vvi;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef complex<double>             point;

#define X                           real()
#define Y                           imag()
#define angle(p)                    atan2(p.Y,p.X)
#define vec(a,b)                    (b-a)
#define rotateO(p,theta)            (p*exp(point(0,theta)))
#define rotateA(p,theta,about)      rotateO(vec(about,p), theta) + about
#define reflectO(p,m)               conj(p/m)*m
#define reflectA(p,p0,pm)           conj(vec(p0,p)/vec(p0,pm))*vec(p0,pm) + p0
#define scf                         scanf
#define prf                         printf
#define F_IO                        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(c)                      c.begin(),c.end()
#define sz(c)                       ((int)((c).size()))
#define pb                          push_back
#define eb                          emplace_back
#define popb                        pop_back
#define mkp                         make_pair
#define xf                          first
#define ys                          second
#define getbit(i, mask)             ((mask & (((__typeof(mask))1)<<i)) != 0)
#define setbit(i, mask)             (mask |= ((__typeof(mask))1)<<i)
#define clrbit(i, mask)             (mask &= ~(((__typeof(mask))1)<<i))
#define togglebit(i, mask)          (mask ^= ((__typeof(mask))1)<<i)
#define lp(i,s,e)                   for(auto i=s ; i<e ;  ++i)
#define rlp(i,e,s)                  for(auto i=e ; i>s ;  --i)
#define lp_(var , c)                for(const auto &var : c)
#define mems(c,val)                 memset(c,val,sizeof(c))
#define mod                         998244353
#define OOi                         (~(1<<31))
#define OOl                         (~(1LL<<63))
#define PI                          (3.14159265358979)
#define EPS                         (1e-9)
#define F_open_r                    freopen("input.txt", "r", stdin)
#define F_open_w                    freopen("output.txt", "w", stdout)
#define watch(x)                    cerr << ">> " << (#x) << " = " << (x) << endl
int dcmp(double a, double b)                            {return((fabs(a-b)<EPS)?0:(a<b)?-1:+1);}
double crossP(const point &v1, const point &v2)         {return (conj(v1)*v2).Y;}
double dotP(const point &v1, const point &v2)           {return (conj(v1)*v2).X;}
double lengthSqr(const point &p)                        {return dotP(p, p);}
double length(const point &p)                           {return hypot(p.X,p.Y);}
double fixAngle(double a)                               {return ((a>1)?1:(a<-1)?-1:a);}
bool same(const point &p1, const point &p2)             {return((dcmp(p1.X, p2.X)==0 && dcmp(p1.Y, p2.Y)==0)?1:0);}
double getAngle_A_abc(double a, double b, double c)     {return acos(fixAngle((b*b+c*c-a*a)/(2*b*c)));}
//_______________________________________________________________________________________________________________________.
const int N = 2e5 + 9;
char c[N];

int main(){
	int tc;
	scf("%d", &tc);

	while(tc--){
		scf("%s", c);

		int n = strlen(c);
		c[n] = '#';

		char pre = c[0];
		int len = 1;
		int mx = 0;

		lp(i,1,n+1){
			if(c[i] == pre) len++;
			else{
				if(pre == 'L') mx = max(mx, len);
				pre = c[i];
				len = 1;
			}
		}
		prf("%d\n", mx+1);
	}
	return 0;
}