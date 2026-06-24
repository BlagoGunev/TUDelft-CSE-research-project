#include <bits/stdc++.h>
using namespace std;
int q[200009];
void solve()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>q[i];
	int x=__gcd(abs(q[1]-1),abs(q[2]-2));
	for (int i=3;i<=n;i++)
		x=__gcd(abs(q[i]-i),x);
	cout<<x<<"\n";
}
int main()
{
	int T=1;
	cin>>T;
	while (T--)
		solve();
}