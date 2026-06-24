/***************************************

      Authur : zzblack                **

      Created: 2016-07-18             **

      Orz                             **

****************************************/

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <cmath>

#include <string>

#include <cctype>

#include <cstdio>

#include <vector>

#include <cstdlib>

#include <cstring>

#include <iomanip>

#include <sstream>

#include <iostream>

#include <algorithm>

using namespace std;

#define ls id<<1,l,mid

#define rs id<<1|1,mid+1,r

#define OFF(x) memset(x,-1,sizeof x)

#define CLR(x) memset(x,0,sizeof x)

#define MEM(x) memset(x,0x3f,sizeof x)

typedef long long ll ;

typedef pair<int,int> pii ;

const int maxn = 1e6 + 50 ;

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



int val[maxn], a[maxn];



void build(int id, int dep){

	if (dep == 1) return ;

	build(id << 1, dep-1);

	build(id << 1 | 1, dep - 1);

	if (dep & 1) val[id] = val[id << 1] ^ val[id<<1|1];

	else val[id] = val[id<<1] | val[id<<1|1];

}



void update(int id, int goal, int dep) {

	if (goal >> dep & 1) update(id >> 1 | 1, goal, dep - 1);

	else update(id >> 1, goal, dep - 1);



}



int main () {

#ifdef LOCAL

  	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);

    freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);

#endif

    int n = read(), m = read();

    for (int i = 1; i <= 1 << n; i++) a[i] = read();

    for (int i = 1; i <= 1 << n; i++) val[i + (1 << n) - 1] = a[i];

    build(1, n + 1);

	// 	for (int i = 1; i < 1 << n + 1; i++) printf("%d ", val[i]);

	// cout << val[1] << "\n";

	while (m--) {

		int l = read(), r = read();

		val[l + (1 << n) - 1] = r;

		int cur = (l + (1 << n) - 1) >> 1;

		int dep = 1;

		while (cur) {

			if (dep & 1) val[cur] = val[cur << 1] | val[cur<<1|1];

			else val[cur] = val[cur << 1] ^ val[cur<<1|1];

			dep ^= 1;

			cur >>= 1;

		}

		// for (int i = 1; i < 1 << n + 1; i++) printf("%d ", val[i]);

		printf("%d\n", val[1]);

		// update(1, l + (1 << n) - 1, n);

	}

	return 0;

}