#include <bits/stdc++.h>
#define endl "\n"
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define pb push_back
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define ull unsigned long long
using namespace std;
typedef pair<int, int> PII;
const int mod = 1e9+7;
const int N = 2e5+10;
const int M = 2010;
//int lowbit(int x) {
//	return x & -x ;
//}
//int ksm(int a,int b){int res=1;while(b){if(b&1) res=(res*a)%mod;b>>=1;a=(a*a)%mod;}return res;}
//int fact[N],infact[N];
//void init(){fact[0] = infact[0] = 1;for (int i = 1; i < N; i ++ ){fact[i] = fact[i - 1] * i % mod;infact[i] = infact[i - 1] * ksm(i, mod - 2) % mod;}}
//int C(int a,int b){if(a<0||b<0||b>a) return 0; return fact[a]*infact[a-b]%mod*infact[b]%mod;}
//int primes[N], cnt;map<int,int> mp;
//bool st[N];
//void get_primes(int nn){for (int i = 2; i <= nn; i ++ ){if (!st[i]) primes[cnt ++ ] = i,mp[i]=1;for (int j = 0; primes[j] <= nn / i; j ++ ){st[primes[j] * i] = true;if (i % primes[j] == 0) break;}}}
//int gcd(int a,int b){return b==0?a:gcd(b,a%b);}


void solve() {
	int n,m;
	cin>>n>>m;
	int ans=1e15;
	for(int i=1;i<=1e6;i++)
	{
		ans=min(ans,(i-1)+n/i+((n%i)!=0)+m/i+((m%i)!=0));
	}
	cout<<ans<<endl;
}
/*
*/
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//init();
	//get_primes(1000);
	int T=1;
	cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}