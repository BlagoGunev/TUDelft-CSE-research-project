#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define ld  long double
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long ,long long>
#define vi  vector<int>
#define vit vector <int> :: iterator
#define all(a)         (a).begin(),(a).end()
#define F            first
#define S             second
#define sz(x)          (ll)x.size()
#define hell         1000000007
#define endl           '\n'
#define out(a)            for(int i=0;i<a.size();++i)cout<<a[i]<<" ";
#define loopl(a,b)   for(long long i=a;i<b;i++)
#define loop(a,b)    for(ll i=a;i<b;i++)
#define loopj(a,b)   for(ll j=a;j<b;++j)
#define PI             3.141592653589793l
#define vl             vector<long>
#define inf            10000000001
#define rush() ll T;cin>>T;while(T--)
#define MAXN 1000001
#define MINN .00000001
ll MOD = 1e9+7;
 
 
void solve(){
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll x,y,z;
    ll gcdwd = __gcd(w,d);
    ll wd = w/gcdwd;
    ll dd = d/gcdwd;
    if(p%gcdwd!=0){
        cout<<-1<<"\n";
        return;
    }
    ll pd = p/gcdwd;
    ll pdd = pd%dd;
    vector <bool> modd(dd,0);
    ll highx = pd/wd;
    bool ispossible  =1;
    // cout<<pdd;
    while(highx>=0 && (wd*highx)%dd != pdd){
        if(modd[((wd*highx)%dd)] == 1){
            ispossible = 0;
            break;
        }
        modd[((wd*highx)%dd)] = 1;
        highx--;
    }
    // cout<<"ji";
    if(!ispossible){
        cout<<-1<<"\n";
        return;
    }
    // cout<<"ji2";
    x = highx;
    if((pd-x*wd)%dd!=0){
        cout<<-1<<"\n";
        return;
    }
    y = (pd - x*wd)/dd;
    z = n - (x+y);
    if(x>=0 && y>=0 && z>=0){
        cout<<x<<" "<<y<<" "<<z<<"\n";
    }else{
        cout<<-1<<"\n";
        return;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    cout << fixed;
    // rush(){
        solve();
    // }
}