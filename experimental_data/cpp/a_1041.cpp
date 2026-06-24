#include<bits/stdc++.h>
using namespace std;

#define FREAKit ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pf push_front
#define mp make_pair
#define lb(v,x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define ub(v,x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define ll long long int

//#define int long long int
//int32_t main(){
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	FREAKit

	int n;
	cin>>n;
	int arr[n];
	
	int i;
	ll ans = 0;
	
	for(i=0; i<n; i++)
	cin>>arr[i];
	
	sort(arr, arr+n);
	for(i=1; i<n; i++){
		ans += arr[i]-arr[i-1]-1;
	}
	
	cout<<ans;
	return 0;
}