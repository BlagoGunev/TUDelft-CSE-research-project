/*	Coded By piyush_40	*/

#include <bits/stdc++.h>

using namespace std;

#define ll           long long 

#define pb           push_back 

#define ff           first 

#define ss           second 

#define ip(num)      ll num;cin>>num;

#define ips(num)     string num;cin>>num;

#define vip(vi,n)    for(ll i=0;i<n;i++) cin>>vi[i];

#define nl           '\n'

#define pnl          cout<<'\n'; 

#define P(v)         for(auto x:v) cout<<x<<' ';cout<<'\n';

#define Pr(v)        for(auto x:v) cout<<x.first<<' '<<x.second<<'\n';

#define p(x)         cout<<x<<'\n';

#define all(x)       (x).begin(),(x).end()

#define rall(x)      all(x),greater<ll>()

#define I05          ios_base::sync_with_stdio(false);cin.tie(NULL);







void solve_tc()

{

   ip(n);

   vector<ll> a(n);

   vip(a,n);

   priority_queue<ll> pq;

   ll ans=0;

   for(ll i=1;i<=n;i++){

	pq.push(a[i-1]);

	if(pq.top()==i){

		ans++;

	}

   }

   p(ans);

}

int main(){

	

	I05

	ll TestCase=1;

	cin>>TestCase;

	for(int tc=1;tc<=TestCase;tc++){

		solve_tc();

	}



return 0;

}