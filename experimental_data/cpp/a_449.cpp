#include <bits/stdc++.h>
#include <map>

#include <set>

#include <cmath>

#include <queue>

#include <vector>

#include <bitset>

#include <string>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <iostream>

#include <algorithm>

using namespace std;

#define M 1000010

#define LL long long

#define MOD 1000000007

#define inf 2147483647

#define llinf 4000000000000000000ll

#define For(i, x, y) for(int i = (x); i < (y); i ++)

#define rep(i, x, y) for(int i = (x); i <= (y); i ++)

#define drep(i, x, y) for(int i = (x); i >= (y); i --)



inline int read(){

	char ch=getchar();int x=0,f=1;

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}

	return x*f;

}



inline LL llread(){

	char ch=getchar();LL x=0,f=1;

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}

	return x*f;

}



int main(){

	//freopen("0input.in", "r", stdin);

	int n = read(), m = read(), k = read();

	if(n + m - 2 < k){

		return puts("-1"), 0;

	}  

	//max{floor(n/x)*ceil(m/(k+2-x))}

	LL ans = 0;

	for(int i = min(n, k + 1); i != 0; i = n / (n / i + 1)){

	//	printf("%d\n", i);

		ans = max(ans, (LL)(n / i) * (LL)(m / (k + 2 - i)));

	}

	/*for(int i = min(n, k + 1); i != 0; i = n / (n / i + 1)){

		printf("%d\n", i);

		ans = max(ans, (LL)(n / i) * (LL)(m / (k + 2 - i)));

	}*/

	printf("%lld\n", ans);

	return 0;

}