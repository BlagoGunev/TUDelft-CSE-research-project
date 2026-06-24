#include<iostream>
using namespace std;
using ll=long long;
using ld=long double;
//#define int ll
using pii=pair<int,int>;
const int N=1e5+1;
int cnt[N];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1,x;i<=n;i++) cin>>x,cnt[x]++;
		for(int i=1;i<n;i++) if(cnt[i]>2)
			cnt[i+1]+=cnt[i]-2,cnt[i]=2;
		bool fl=1;
		for(int i=1;i<=n;i++) fl&=!(cnt[i]&1);
		if(fl) cout<<"Yes\n";
		else cout<<"No\n";
		for(int i=1;i<=n;i++) cnt[i]=0;
	}
	return 0;
}