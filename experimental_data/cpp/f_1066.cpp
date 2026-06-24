// go proooooooooooooooooooooooooooooooooooo
#include <bits/stdc++.h>

// #define DEBUG

#define maxN 200005
#define matrix_size 2
#define base 1000000007LL
#define eps 1e-8

#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL(x) (x << 1)
#define RR(x) ((x << 1) + 1)
#define sqr(x) ((x) * (x))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define onbit(x,k) (x | (1<<k))
#define offbit(x,k) (x & (~(1<<k)))
#define getbit(x,k) ((x>>k) & 1)
#define cross(A,B) (A.x*B.y-A.y*B.x)
#define dot(A,B) (A.x*B.x+A.y*B.y)
#define ccw(A,B,C) (-(A.x*(C.y-B.y) + B.x*(A.y-C.y) + C.x*(B.y-A.y)))
#define CROSS(a,b,c,d) (a*d - b*c)
#define ALL(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,a,b) for (int i=(a); i<(b); ++i)
#define REPD(i,a,b) for (int i=(a); i>(b); --i)

using namespace std;

// template ends here
ll d[maxN],F[maxN][2],Level[maxN]; iii a[maxN]; int n; ii b1[maxN],b2[maxN];

ll calc(int a,int b,int c,int d)
{
    return 1LL*abs(a-c)+1LL*abs(b-d);
}

bool cmp(iii a,iii b)
{
    return (a.fi<b.fi) || (a.fi==b.fi && a.se.fi<b.se.fi) || (a.fi==b.fi && a.se.fi==b.se.fi && a.se.se>b.se.se);
}

void yolosmile()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i].se.fi >> a[i].se.se;
        a[i].fi=max(a[i].se.fi,a[i].se.se);
    }
    sort(a+1,a+n+1,cmp);
    int cnt=0;
    for (int i=1; i<=n; i++)
    {
//        int Minx=a[i].se.fi,Miny=a[i].se.se,ax=i,Left=i,Right=i;
        int ax=i;
        for (int j=i+1; j<=n+1; j++)
        {
            if (a[i].fi!=a[j].fi)
            {
                ax=j-1;
                break;
            }
        }
        Level[++cnt]=a[i].fi;
//        b[cnt].fi=Minx; b[cnt].se=Miny;
//        d[cnt]=calc(a[Left].se.fi,a[Left].se.se,a[Right].se.fi,a[Right].se.se);
        b1[cnt].fi=a[i].se.fi; b1[cnt].se=a[i].se.se;
        b2[cnt].fi=a[ax].se.fi; b2[cnt].se=a[ax].se.se;
        d[cnt]=calc(a[i].se.fi,a[i].se.se,a[ax].se.fi,a[ax].se.se);
        i=ax;
    }
//    F[1][0]=Level[1]+b[1].fi;
//    F[1][1]=Level[1]+b[1].se;
    F[1][0]=calc(0,0,b1[1].fi,b1[1].se);
    F[1][1]=calc(0,0,b2[1].fi,b2[1].se);
    for (int i=2; i<=cnt; i++)
    {
        F[i][0]=min(F[i-1][1]+d[i-1]+calc(b1[i-1].fi,b1[i-1].se,b1[i].fi,b1[i].se),F[i-1][0]+d[i-1]+calc(b2[i-1].fi,b2[i-1].se,b1[i].fi,b1[i].se));
        F[i][1]=min(F[i-1][1]+d[i-1]+calc(b1[i-1].fi,b1[i-1].se,b2[i].fi,b2[i].se),F[i-1][0]+d[i-1]+calc(b2[i-1].fi,b2[i-1].se,b2[i].fi,b2[i].se));
    }
    cout<<min(F[cnt][0],F[cnt][1])+d[cnt];
}

int main()
{
	IOS;
	#ifdef DEBUG
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
	#endif // DEBUG

    yolosmile();

    return 0;
}