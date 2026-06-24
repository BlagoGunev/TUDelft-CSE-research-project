#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define pii pair<int, int>
#define pll pair<long long, long long>
const i64 N = 100007;
const i64 INF = 0x3f3f3f3f;
const i64 mod = 1000000007;

void solve()
{
	i64 k, x, a;
	cin>>k>>x>>a;
	unsigned i64 sum = 1;
	while(x--)
		sum += sum / (k - 1) + 1;
	if(sum <= a)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
 }