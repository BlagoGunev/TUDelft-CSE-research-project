#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

typedef unsigned long long ull;
ull ha[1000010];
int fact[1000010];
int n, m, a[1000010];
int main(){
	scanf("%d%d", &n, &m);
	ull seed = 1;
	for(int i =1 ;i <= n;i ++){
		int k;
		scanf("%d", &k);
		for(int j = 1;j <= k;j ++) scanf("%d", &a[j]);
		sort(a + 1,a+k+1);
		int tmp = 1;
		
		for(int j=1;j<=k;j ++){
			int l = j;
			while(l+1<=k&&a[l+1]==a[j]) l++;
			ha[a[j]] += seed * (l - j + 1);	
			j=l;
		}
		seed *= 1000000007ULL;
	}
	fact[0] = 1;
	for(int i = 1;i <= m;i ++) fact[i] = 1LL * fact[i - 1] * i % mo;
	sort(ha + 1, ha + m + 1);
	int ans = 1;
	for(int i = 1;i <= m;i ++){
		int j = i;
		while(j + 1 <= m && ha[j + 1] == ha[i]) j ++;
		ans = 1LL * ans * fact[j - i + 1] % mo;
		i = j;
	}
	cout << ans << endl;
	return 0;
}