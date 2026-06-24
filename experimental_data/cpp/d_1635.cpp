#include <bits/stdc++.h>
#define MAX_INT 0x7FFFFFFF
#define MIN_INT -0x80000000
#define MAX_LLI 0x7FFFFFFFFFFFFFFF
#define MIN_LLI -0x8000000000000000
#define fi first
#define se second
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef queue<pii> qii;
typedef queue<pll> qll;
typedef set<int> si;
typedef multiset<int> msi;

const ll MOD = 1000000007;
int n,p,a[202020];
ll dp[202020] = {1,2,4},ans;

ll f(int x)
{
    if(x < 0) return 0;
    if(dp[x]) return dp[x];
    dp[x] = 1+f(x-1)+f(x-2);
    dp[x] %= MOD;
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<p;i++) f(i);
    for(int i=n-1;i>0;i--){
        int tmp = a[i];
        bool flg = true;
        while((tmp%2 or tmp%4 == 0) and tmp){
            if(tmp%2) tmp /= 2;
            else tmp /= 4;
            if(binary_search(a,a+n,tmp)){
                flg = false;
                break;
            }
        }
        if(flg){
            int k = 0;
            while((1<<k) <= a[i]) k++;
            ans += f(p-k);
            ans %= MOD;
        }
    }
    int k = 0;
    while((1<<k) <= a[0]) k++;
    ans += f(p-k);
    ans %= MOD;
    cout << ans;
}