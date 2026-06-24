//editor: Jan Tang

//problem:

#include <iostream>

#include <cstdio>

#include <string>

#include <cstring>

#include <algorithm>

#include <cmath>

#include <map>

#include <stack>

#include <queue>

#include <set>

#include <cstdlib>

using namespace std;

#define set0(a) memset(a,0,sizeof(a));

#define CIN(a,n) for(int i=1;i<=n;i++) cin>>a[i];

typedef long long ll;

typedef unsigned long long ull;

const int Mod = 1e9+7;

const int maxn = 2005;

const int inf = 0x3f3f3f3f;

int k,n,dp[maxn], a[maxn];

bool check(ll x){

//dp[i]代表不改变第i个数的情况下前i-1个数最少需要改变的数的个数

//	cout << x << endl;

	for(int i = 1; i <= n; i++) dp[i] = i-1;



	for(int i = 1; i <= n; i++){

		for(int j = i+1; j <= n; j++){

			if(x * (j-i) >= abs(a[j] - a[i])) dp[j] = min(dp[j], dp[i] + j-i-1);

		}

//		printf("dp[%d] = %d\n", i, dp[i]);

	}

	int ans = inf;

	for(int i = 1; i <= n; i++) ans = min(ans, dp[i]+n-i);



	if(ans<=k) return true;

	else return false;

}

/*==============================head==========================*/

int main(){

	while(scanf("%d%d",&n,&k)!=EOF){

		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

		ll r = 2*inf, l = 0;

		while(l<r){

			ll mid = (r-l)/2 + l;

			if(check(mid)) r = mid;

			else l = mid+1;

		}

		cout << r << endl;

	}

	return 0;

}