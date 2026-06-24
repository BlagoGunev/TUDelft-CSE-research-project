#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#define ft first
#define sd second
#define pb push_back
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);


using namespace std;


typedef long long LL;
typedef pair<int, int>PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef map<int,int> MPII;
typedef map<LL,LL> MPLL;



const int N = 110;
LL n,t,cnt,ans;
LL vis[N],sum[N];
LL f[N] = {1,2};
LL d[N] = {0,1};
LL a[N] = {0,1,2};
void dfs(LL x,LL num,LL last) 
{
    if(sum[last - 1] < x) return;
    if(last == 1 && x) return;
    if(num >= ans && x) return;
    if(x == 0) ans = min(ans,num);
    for(int i = last - 1;i >= 1; i--) 
        if(x >= a[i])
            dfs(x - a[i],num + 1,i);
}

int main() 
{
    for(int i = 2; i <= 20; i++) d[i] = d[i-1] * i;
	cnt = 2;
    for(int i = 2; i <= 50; i++) f[i] = f[i - 1] * 2;
    for(int i = 3;i <= 20;i++) a[++cnt] = d[i];
    for(int i = 2;i <= 50;i++) a[++cnt] = f[i];
    sort(a + 1,a + cnt + 1);
    for(int i = 1;i <= cnt; i++) sum[i] = sum[i - 1] + a[i];
    cin>>t;
    while(t--) 
	{
        cin >> n;
    	ans = 1e18;
    	dfs(n,0,cnt+1);
    	cout << ans << endl;
    }
    return 0;
}