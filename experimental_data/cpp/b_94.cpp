// Vikram singh dhinwal

#include <bits/stdc++.h>

using namespace std;

#define    max(a,b)          ((a)>(b)?(a):(b))

#define    min(a,b)          ((a)<(b)?(a):(b))

#define    ll                long long

#define    ff                first

#define    ss                second

#define    pb                push_back

#define    mp                make_pair

#define    FOR(i,a,b)        for(i=a;i<b;i++)

#define    AFOR(i,a,b)       for(i=a;i<=b;i++)

#define    RFOR(i,a,b)       for(i=a;i>=b;i--)

#define    mset(x,v)         memset(x,v,sizeof(x))

#define    sz(x)             (int)x.size()

typedef long long i64;

const ll LINF = (ll)1e16 + 5;

const int INF =1e9;

const int MOD=1e9+7;

const int maxlen=1e6;

typedef vector <int> V;

typedef vector < pair <int,int> > VV;

typedef pair <int,int> P;

typedef map<string,int> M;

int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int xx[]={-1,1,0,0};

int yy[]={0,0,-1,1};

/*

double dis(double a1,double b1,double a2,double b2)

{

    return sqrt((a1-a2)*(a1-a2)+(b2-b1)*(b2-b1));

} */



int main()

{

    int m,x,y,i;

    int a[6];

    mset(a,0);

    cin >> m;

    FOR(i,0,m)

    {

      cin >> x >> y;

      a[x]++;

      a[y]++;

    }

    bool f=false;

    AFOR(i,1,5)

    {

      if(a[i]<=1 || a[i]>=3)

      {

        f=true;

        break;

      }

    }

    f ? cout << "WIN\n" : cout << "FAIL\n";

}