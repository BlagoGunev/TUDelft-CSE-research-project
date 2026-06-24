#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t)
	{
		ll a,b,k;
		cin>>a>>b>>k;
	//	cerr<<k/2<<' '<<k-k/2<<':';
		cout<<(k-k/2)*a-(k/2)*b<<endl;;
		t--;
	}
	return 0;
}