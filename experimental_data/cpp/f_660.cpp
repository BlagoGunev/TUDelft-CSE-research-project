#include <bits/stdc++.h>
/*************************************************************************

	> File Name: 660F.cpp

	> Author: jiangyuzhu

	> Mail: 834138558@qq.com

	> Created Time: Mon 20 Jun 2016 10:25:40 AM CST

 ************************************************************************/



#include<iostream>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<queue>

#include<stack>

using namespace std;

typedef pair<int, int>p;

typedef long long ll;

#define sa(n) scanf("%d", &(n))

#define sal(n) scanf("%lld", &(n))

const int maxn = 2e5 + 5, mod = 1e9 + 7, oo = 0x3f3f3f3f;

ll a[maxn], val[maxn], sum[maxn];

int q[maxn];

inline ll up(int a, int b)

{

	ll x1 = val[a] - a * sum[a];

	ll x2 = val[b] - b * sum[b];

	return x2 - x1;

}

inline ll down(int a, int b){return (ll)b - a;}

bool judge(int a, int i)

{

	ll x1 = val[q[a]] - q[a] * sum[q[a]];

	ll x2 = val[q[a + 1]] - q[a + 1] * sum[q[a + 1 ]];

	return x2 - x1 > -sum[i] * down(q[a], q[a + 1]);

}

int main (void)

{

	int n;sa(n);

	ll ans = 0;

	for(int i = 1; i <= n; i++){

		sal(a[i]);

		sum[i] = sum[i - 1] + a[i];

		val[i] = val[i - 1] + i * a[i];

		ans = max(ans, a[i]);

	}

	int rear = 0;

	int l, r;

	q[rear++] = 0;

	for(int i = 1; i <= n; i++){

		l = 0, r = rear - 1;

		int res = 0;

		while(l <= r){//[]

			int mid = l + r >> 1;

			if(judge(mid, i)) r = mid - 1, res = mid;

			else l = mid + 1;

		}

        ans = max(ans, val[i] - val[q[res]] - q[res] * (sum[i] - sum[q[res]]));

		while(rear > 1 && up(q[rear - 1], i) * down(q[rear - 2], q[rear - 1]) < up(q[rear - 2], q[rear - 1]) * down(q[rear - 1], i)) rear--;

		q[rear++] = i;

	}

	printf("%lld\n", ans);

	return 0;

}