//um passing time with the chili sauce
#include<bits/stdc++.h>
using namespace std;
#define  io_fast()      ios :: sync_with_stdio(false); cin.tie(0);
#define  go             return 0
#define  ll             long long int
#define  ull            unsigned long long int
#define  ld             long double
#define  vi             vector<int>
#define vl              vector<long long>
#define vc              vector<char>
#define vs              vector<string>
#define vp              vector< pair<ll,ll> >
#define sl              set<long long>
#define sc              set<char>
#define sts             stack<string>
#define max_3(a,b,c)    max(a, max(b,c))
#define max_4(a,b,c,d)  max(a,max(b,max(c,d)))
#define min_3(a,b,c)    min(a, min(b,c))
#define min_4(a,b,c,d)  min(a,min(b,min(c,d)))
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*b)/gcd(a,b)
#define pi              2*acos(0.0)
#define N               100001
//ll a[N],b[N];
int main()
{
    io_fast();
    ll t,x,y,a,b,c,r,d1,d2,ans,rslt;
    cin>>t;
    while(t--){
    cin>>x>>y>>c>>r;
    a=min(x,y);
    b=max(x,y);
    d1=c-r;
    d2=c+r;
    ans=b-a;
    if(d1>a&&d2<b&&d1<=b) rslt=ans-2*r;
    else if(d1>a&&d2>=b&&d1<=b) rslt=d1-a;
    else if(d2<=a||d1>=b) rslt=ans;
    else if(d2>a&&d2<b) rslt=b-d2;
    else if(d1<=a&&d2>=b) rslt=0;
    cout<<rslt<<endl;
    }
    go;
}