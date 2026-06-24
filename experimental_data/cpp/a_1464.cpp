// Problem: A. Peaceful Rooks

// Contest: Codeforces - Codeforces Round #692 (Div. 1, based on Technocup 2021 Elimination Round 3)

// URL: https://codeforces.com/contest/1464/problem/A

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

#define x first

#define y second

#define int long long 

#define endl '\n'

using namespace std;

typedef pair<int,int>PII;



int n,m;

int p[200005];



int find(int x){

	if(x!=p[x])p[x]=find(p[x]);

	return p[x];

}



void solve(){

	cin>>n>>m;

	for(int i=1;i<=n;i++)p[i]=i;

	int ans=0;

	for(int i=1;i<=m;i++){

		int x,y;

		cin>>x>>y;

		if(x==y)continue;

		ans++;

		x=find(x),y=find(y);

		if(x==y)ans++;

		else p[x]=y;

	}

	cout<<ans<<endl;

}



signed main()

{

	ios::sync_with_stdio(false);

    cin.tie(nullptr);

	int T=1;

	cin>>T;

	while(T--)

		solve();

	return 0;

}