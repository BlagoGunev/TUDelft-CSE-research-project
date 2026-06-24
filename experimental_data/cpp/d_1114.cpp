#include <bits/stdc++.h>
using namespace std;
#define de(x) cout<<#x<<"="<<x<<","
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define dee(x) cout<<#x<<"="<<x<<"\n"
#define mes(p) memset(p,0,sizeof(p))
#define fi first
#define se second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define sz(x) (int)x.size()
#define pb push_back
#define ls (rt<<1)
#define rs (ls|1)
#define all(x) x.begin(),x.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
//typedef priority_queue <pair<int, int>, greater<pair<int, int> >, pairing_heap_tag> heap;
const int maxn=5005;
typedef long long ll;
typedef vector <int > vi;
typedef pair <int ,int > pi;
const int  N = 7;
int dp[maxn][maxn], a[maxn], b[maxn];
int ans[maxn],n;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
 	cin>>n;
	int len=0;
 	rep(i,1,n+1) {
	 	cin>>a[i];
	 	if(a[i]!=a[i-1]){
	 		b[len++]=a[i];	
		}
	}
    for(int i = len-1; i >= 0; --i){
        dp[i][i] = 1;
        for(int j = i+1; j < len; ++j)
            if(b[i] == b[j])
                dp[i][j] = dp[i+1][j-1]+2;
            else
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
    }
	cout << len -1- dp[0][len-1]/2;
	return 0;
}