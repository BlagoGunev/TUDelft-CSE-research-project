#include<bits/stdc++.h>
#define ll long long 
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=m-1;i>=n;i--)
#define FIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
void solve()
{ 
      ll n, c, h;
		cin >> n >> c >> h; 
		if((c + h) >= n - 1){
			cout << n + (n - 1) << endl;
		}else{
			cout << (c + h) + (c + h + 1) << endl;
		}
}
int main()
{
FIO
int t;
cin>>t;
while(t--)
{
solve();
}
return 0;
}