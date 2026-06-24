/***************************************

	  Authur : zzblack                **

	  Created: 2016-07-24             **

	  source: codeforces  78C         **

	  Orz                             **

****************************************/

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <ctime>

#include <cmath>

#include <string>

#include <cctype>

#include <cstdio>

#include <vector>

#include <bitset>

#include <cstdlib>

#include <cstring>

#include <iomanip>

#include <sstream>

#include <iostream>

#include <assert.h>

#include <algorithm>

using namespace std;

#define ls id<<1,l,mid

#define rs id<<1|1,mid+1,r

#define OFF(x) memset(x,-1,sizeof x)

#define CLR(x) memset(x,0,sizeof x)

#define MEM(x) memset(x,0x3f,sizeof x)

typedef long long ll ;

typedef pair<int,int> pii ;

const int maxn = 1e5 + 50 ;

const int maxm = 1e6 + 50;

const double eps = 1e-10;

const int max_index = 62;

const int inf = 0x3f3f3f3f ;

const int MOD = 1e9+7 ;



inline int read(){

	char c = getchar();

	while (!isdigit(c)) c = getchar();

	int x = 0;

	while (isdigit(c)) {

	    x = x * 10 + c - '0';

	    c = getchar();

	}

	return x;

}



int n, m, k;



int main () {

#ifdef LOCAL

	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);

	freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);

#endif

	n = read(), m = read(), k = read();

	if (m == 1) {

		puts("Marsel");

		exit(0);

	}

	int tot = 1, tmp = m;

	int flag = 0;

	for (ll i = 2; i * i <= m; i++) {

		while (m % i == 0) {

			m /= i;

			tot = i;

			if (tmp / i >= k) flag = 1;

		}

	}

	if (m > 1 && tot > 1) tot = m;

	if ((tot >= k || flag) && (n&1)) puts("Timur");

	else puts("Marsel");

	// int tmp = dfs(m);

	// if (tmp == 3 || tmp == 2 && (n&1)) puts("Timur");

	// else puts("Marsel");

	return 0;

}