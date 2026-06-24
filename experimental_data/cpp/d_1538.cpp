#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Test int T;cin>>T;while(T--)
#define PI acos(-1)
#define endl "\n"
#define fx(x) fixed<<setprecision(x)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define mem(a,n) memset((a),n,sizeof (a))
#define INF 1e9
#define ii pair<ll,ll>
ll gcd(ll x,ll y){return(!y?x:gcd(y,x%y));}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
void file(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    //freopen("conan.in", "r", stdin);
    //freopen("bridges.out", "w", stdout);
#endif
}
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
}
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
const double eps=1e-9;
const int mod=1e9+7;
const int N=1e6+5;
bool prime[N];
vector<int>primes;
void  sieve_v2(){
	for (int i = 0; i < N; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 4; i < N; i += 2){
		prime[i] = 0;
	}
	for (int i = 3; i * i < N; i += 2){
		if (prime[i]){
			for (int j = i * i; j < N; j += i + i){
				prime[j] = 0;
			}
		}
	}
	for(int i=2;i<N;i++)
        if(prime[i])primes.push_back(i);
}
int fact(int x){
    int ans=0;
    for(int i=0;primes[i]*primes[i]<=x;i++){
        while(x%primes[i]==0){
            x/=primes[i];
            ans++;
        }
    }
    if(x>1)ans++;
    return ans;
}
void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    int a1=fact(a);
    int b1=fact(b);
    int mx=a1;
    mx+=b1;
    int x=gcd(a,b);
    if(k==1){
        if((a==x&&b!=x)||(a!=x&&b==x))cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    if(a1>1||b1>1){
        int mn=(a!=x)+(b!=x);
        if(k>=mn&&k<=mx)cout<<"YES\n";
        else cout<<"NO\n";
    }
    else{
        if(k==a1+b1)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
int main(){
    fast();
    sieve_v2();
    Test{
        solve();
    }
}