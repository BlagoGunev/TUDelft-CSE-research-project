#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl '\n'

#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=2e5+10,mod=1e9+7;

signed main()

{

	_

	int n,q;

	cin>>n>>q;

	vector<int> a(n+1),s(n+1);

	int res=0;

	for (int i=1;i<=n;i++) cin>>a[i],res+=a[i];

	sort(a.begin()+1,a.end(),greater());

	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

	while(q--)

	{

		int l,r;

		cin>>l>>r;

		cout<<s[l]-s[l-r]<<endl;

	}

	return 0; 

}