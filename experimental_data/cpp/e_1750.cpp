#include<bits/stdc++.h>

using namespace std;

void solve()

{

	int n;cin>>n;

	string s; cin>>s;

	vector<int> a(1);

	int sum=0;

	for(int i=0;i<n;i++){

		if(s[i]=='(')sum++;

		else sum--;

		a.push_back(sum);

	}

	sort(a.begin(),a.end());

	long long ans=0,nc=0;

	for(int i=0;i<=n;i++){

		ans+=1ll*i*a[i]-nc;

		ans+=1ll*i*(n-i+1);

		nc+=a[i];

	}

	ans/=2;

	stack<int>stk;

	for(int i=0;i<n;i++){

		if(s[i]=='(') stk.push(i);

		else if(!stk.empty()) {

			ans-=1ll*(stk.top()+1)*(n-i);

			stk.pop();

		}

	}

	cout<<ans<<'\n';

}

int main()

{

	ios::sync_with_stdio(false);

	cin.tie(nullptr);;

	int t; cin>>t;

	while(t--)solve();

}