#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000100
int t,n,val[N],sum[N];
int cal(int x)
{
	int maxx = 0,minn = 1e15;
	for(int i = 1;i <= n / x;++i) {
		maxx = max(maxx,sum[i * x] - sum[(i - 1) * x]);
		minn = min(minn,sum[i * x] - sum[(i - 1) * x]);
	}
	return maxx - minn;
}
int work()
{
	//sort(val + 1,val + n + 1);
	for(int i = 1;i <= n;++i) sum[i] = sum[i - 1] + val[i];

	int maxx = 0;
	for(int i = 1;i < n;++i)
		if(n % i == 0) maxx = max(maxx,cal(i));
	return maxx;
}
signed main()
{
	ios::sync_with_stdio(false);

	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;++i) cin>>val[i];
		cout<<work()<<endl;
	}

	return 0;
}