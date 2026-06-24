#pragma gcc diagnostic "-std=c++1z"
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
using namespace std;
int n,m,T,k;
void test_case() {
     cin>>n;
     pii arr[n+1];
     for (int i=1; i<=n; i++) {
          cin>>arr[i].f;
     }
     
     for (int i=1; i<=n; i++) {
          cin>>arr[i].s;
     }

     sort(arr+1,arr+1+n);

     for (int i=1; i<=n; i++) cout<<arr[i].f<<" "; cout<<endl;
     for (int i=1; i<=n; i++) cout<<arr[i].s<<" "; cout<<endl;
}
main () {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	T=1; cin>>T;
	while (T--) test_case();
}