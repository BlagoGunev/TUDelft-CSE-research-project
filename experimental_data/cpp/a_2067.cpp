#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int x,y;
void solve()
{
  cin>>x>>y;
  if(x<=y)
  {
    if(x+1==y) cout<<"Yes\n";
    else cout<<"No\n"; 
  }
  else
  {
    if((x-y)%9==8) cout<<"Yes\n";
    else cout<<"No\n"; 
  }
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}