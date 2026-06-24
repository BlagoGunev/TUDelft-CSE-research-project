#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set= tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define MAX 200005
#define inf 1e9
#define pi 3.141592653589793238
const ll mod=1000000007;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))


double make_radian(double x){return (x*pi)/180;}
double make_degree(double x){return (x*180)/pi;}
ld distance(ld a,ld b,ld x,ld y) {ld total=sqrtl(((a-x)*(a-x))+((b-y)*(b-y)));return total;}
bool point_on_segment(ld a,ld b,ld c,ld d,ld x,ld y){if(distance(a,b,c,d)==distance(a,b,x,y)+distance(x,y,c,d)) return true;else return false;}
ld point_checking(ld a,ld b,ld c,ld d,ld x,ld y){ld total=(a*(d-y))-(b*(c-x))+((c*y)-(d*x));return total;/*pos==anti-clock,neg==clockwise,zero==on_line*/}
string dtob(ll n){string s;for(ll i=63;i>=0;i--){if(n&(1LL<<i)) s.pb('1');else s.pb('0');}return s;}
ll btod(string x){ll dec(0);reverse(x.begin(),x.end());for(int i=0;i<x.size();i++)if(x[i]=='1')dec+=pow(2LL,i);return dec;}
void _(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
int X[]={1,-1,0,0};int Y[]={0,0,1,-1};


bool SORT(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.first.first == b.first.first && a.first.second == b.first.second)
        return a.second < b.second;
    else if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    else
        return a.first.first > b.first.first;
}

void solve(int tc)
{
    int n,m,h;cin>>n>>m>>h;
    
    vector<pair<pair<ll,ll>,ll>> table;
    
    for(int i=0;i<n;i++)
    {
        vector<ll> vc(m);
        for(int i=0;i<m;i++) cin>>vc[i];
        sort(vc.begin(),vc.end());
        ll total=0,penalty=0,point=0;
        for(int i=0;i<m;i++)
        {
            if(total+vc[i]>h) break;
            else 
            {
                total+=vc[i];
                point++,penalty+=total;
            }
        }
        table.push_back({{point,penalty},i}); 
    }

    sort(table.begin(),table.end(),SORT);


    for(int i=0;i<n;i++)
    {
        if(table[i].second==0) 
        {
            cout<<i+1<<endl;
            return;
        }
    }
}

int main()
{
    _(); 
    ll t,tc;
    t=tc=1;
    cin>>t,tc=t;
    while(t--) solve(tc-t);
}