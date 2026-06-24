#include <iostream>

#include <sstream>

#include<bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define PI acos(-1)

#define YES cout<<"YES"<<endl

#define NO cout<<"NO"<<endl

#define NL cout<<endl

#define ll long long

#define ull unsigned long long

#define ld long double

#define lld long long double

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define vi vector<ll>

#define max3(a,b,c) max(max(a,b),c)

#define min3(a,b,c) min(min(a,b),c)

#define REP(i,n) FOR(i,0,n,1)

#define REPN(i,n) FORN(i,1,n,1)

#define FOR(a,b,c,d) for(int a=b;a<c;a=a+d)

#define FORN(a,b,c,d) for(int a=b;a<=c;a=a+d)

#define FORD(a,b,c,d) for(int a=b;a>=c;a=a-d)

#define FOREACH(a,b) for(auto &a:b)

#define RESET(a,b) memset(a,b,sizeof(a))

#define ALL(v) v.begin(),v.end()

#define ALLA(arr,sz) arr,arr+sz



void dummy()

{

	

}

void solve()

{ 

	ll n,x,m;cin>>n>>m;

	vi a;

	REP(i,n)	cin>>x,a.pb(x);

	accumulate(ALL(a),0)==m?YES:NO;

}

signed main()

{

	//ONLINE_JUDGE;

	#ifndef ONLINE_JUDGE

		freopen("input.txt","r",stdin);

		freopen("output.txt","w",stdout);

	#endif

		FIO;

		bool tc=1;

		if(tc)

		{

			dummy();

			long test_case;

			cin>>test_case;

			for(long i=1;i<=test_case;i++)

				solve();

		}

		else

			solve();

	return 0;

}