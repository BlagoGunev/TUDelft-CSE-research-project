#include <bits/stdc++.h>
using namespace std;
using pint = tuple<int, int, int>;
using pp = pair<int, int>;
using iter = vector<int>::iterator;
using ull = unsigned long long;
void solve() {
  int n;cin>>n;string s;cin>>s;
  vector<int> a;
  for(int i=0;i<n;i++) if(s[i]=='0')  a.push_back(i);
  vector<int> b;
  for(int i=0;i<a.size();i++){
    if(s[i]=='1') b.push_back(i);
  }
  for(int i=a.size();i<n;i++){
    if(s[i]=='0') b.push_back(i);
  }
  if(b.size()==0) cout<<0<<"\n";
  else {
    cout<<1<<"\n";
    cout<<b.size()<<" ";
    for(int x:b) cout<<x+1<<" ";
    cout<<"\n";
  }
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t-->0) solve();
}