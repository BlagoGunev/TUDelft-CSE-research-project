#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--){
		int n;
		cin>>n;
		string A; cin>>A;
		int curr = 1;
		int ans = 0;
		vi prev;
		prev.pb(A[0]);
		for(int i=1;i<n;i++){
			if(A[i]!=prev.back()){
				if(sz(prev)<2 || (prev[sz(prev)-2]!=A[i]) || curr!=1)
				ans++;
				prev.pb(A[i]);
				curr = 1;
			}
			else curr++;
			if(curr==2) ans++;
		}
		cout<<ans<<endl;
    }
    return 0;
}