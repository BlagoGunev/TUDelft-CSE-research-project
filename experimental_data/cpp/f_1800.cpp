#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define prq priority_queue
using namespace std;
int T;
int jd[200010];
int pw[200010];
map<int,int>cnt;
void solve()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n ;i ++)
	{
		string s;
		cin>>s;
		int len = s.size();
		for(int j = 0 ; j < len ; j ++)
		{
			jd[i]^=(1<<(s[j]-'a'));
			pw[i]|=(1<<(s[j]-'a'));
		}
	}
	ll ans = 0;
	for(int i = 0 ; i <= 25; i ++)
	{
		cnt.clear();
		for(int j = 1;j <= n ; j ++)
		{
			if((pw[j]>>i)&1)continue;
			int temp = (1<<26)-1-(1<<i);
			temp ^= jd[j];
			ans += cnt[temp];
			cnt[jd[j]]++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}