//satyaki3794

#include <bits/stdc++.h>

#define ff first

#define ss second

#define pb push_back

#define MOD (1000000007LL)

#define LEFT(n) (2*(n))

#define RIGHT(n) (2*(n)+1)

 

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> ii;

typedef pair<int, ii> iii;

 

ll pwr(ll base, ll p, ll mod = MOD){

ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;

}

 

ll gcd(ll a, ll b){

    if(b == 0)  return a;

    return gcd(b, a%b);

}



double INF = 1e100;

double EPS = 1e-12;



struct PT { 

  double x, y; 

  PT() {}

  PT(double x, double y) : x(x), y(y) {}

  PT(const PT &p) : x(p.x), y(p.y)    {}

  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }

  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }

  PT operator * (double c)     const { return PT(x*c,   y*c  ); }

  PT operator / (double c)     const { return PT(x/c,   y/c  ); }

};



double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }

double dist2(PT p, PT q)   { return dot(p-q,p-q); }





int n, k;

PT arr[102];





int main(){



    ios_base::sync_with_stdio(0);



    cin>>n>>k;

    double ans = 0.0;

    for(int i=0;i<n;i++){

        int x, y;

        cin>>x>>y;

        arr[i] = PT(x, y);

        if(i > 0)

            ans += sqrt(dist2(arr[i-1], arr[i]));

    }



    ans *= k/50.0;

    cout<<fixed<<setprecision(7)<<ans;

    return 0;

}