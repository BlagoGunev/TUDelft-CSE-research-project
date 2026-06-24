#include <bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll=long long;

const ll mod=1000000007;

void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(long long x) {cerr << x;}

void __print(unsigned x) {cerr << x;}

void __print(unsigned long x) {cerr << x;}

void __print(unsigned long long x) {cerr << x;}

void __print(float x) {cerr << x;}

void __print(double x) {cerr << x;}

void __print(long double x) {cerr << x;}

void __print(char x) {cerr << '\'' << x << '\'';}

void __print(const char *x) {cerr << '\"' << x << '\"';}

void __print(const string &x) {cerr << '\"' << x << '\"';}

void __print(bool x) {cerr << (x ? "true" : "false");}



template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

#else

#define debug(x...)

#endif

int main(){fast

	int t; cin>>t;

	while(t--){

		map<ll,int>s;

		ll ans=0;

		int n; cin>>n; 

		ll ne=1,del=0;

		for(int i=0;i<n;i++){

			int a; cin>>a; ne^=1; del=-del+a;

			ne? s[del-a]++:s[a-del]++;

			while(s.size()){

				if(ne){

					pair<ll,ll> it= *--s.end();

					if(it.first>del){

						s.erase(--s.end());

					}

					else{

						break;

					}

				}

				else{

					pair<ll,ll> it=*s.begin();

					if(it.first<-del){

						s.erase(s.begin());

					}

					else{

						break;

					}

				}

			}

			ans+= ne? s[del]:s[-del];

		}

		cout<<ans<<"\n";

		

	}

}