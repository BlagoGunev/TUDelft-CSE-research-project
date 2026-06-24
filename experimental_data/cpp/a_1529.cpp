#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define FOR(n) for(int i=0;i<n;i++)
#define rep(i,j,n) for(int i=j;i<n;i++)
#define pb push_back
#define ppb pop_back()
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define every(a,n) a,a+n
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define tez ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all_st for(auto it=st.begin();it!=st.end();it++)
#define mp_x unordered_map<int,int>x
#define endl "\n"
#define sz(x) (int)x.size()

void solve()
{
	int n;cin>>n;
	int a[n];
	unordered_map<int,int>cnt;
	FOR(n){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a,a+n);
	cout<<n-cnt[a[0]]<<endl;
}

signed main()
{   
    tez
    int test_case=1;
    cin>>test_case;
    for(int i=1;i<=test_case;i++)
    {
    solve();
    }
}