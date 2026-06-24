/*input
10
1 1 0 1 1 0 1 0 1 0

*/

#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define int long long int
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define lines printsf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define fors(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define mp make_pair
using namespace std;
const int MOD = 1e9+7;

signed main(){
	int n;
	cin>>n;
	vi arr(n);
	int ans=0;
	ff(n) cin>>arr[i];
	for(int i=1;i<n-1;i++){
		if(arr[i-1]==1 and arr[i+1]==1 and arr[i]==0){
			arr[i+1]=0;
			++ans;
		}
	}
	cout<<ans;
}