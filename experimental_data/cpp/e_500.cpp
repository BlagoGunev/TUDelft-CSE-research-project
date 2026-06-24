#include<iostream>

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<string>

#include<vector>

#include<set>

#include<algorithm>

#include<stack>

#include<queue>

#include<map>

#include<limits>

#include<list>

#include<math.h>

using namespace std;

#define ll long long

#define f(i,x,n) for (int i = x;i < n;++i)



int f[200001], n, in[200002], an[200000];



struct sg {

	int l, r, i;

	bool o;

	sg(int a, int b, int c, bool d) { l = a, r = b, i = c; o = d; }

	bool operator <(sg a) { return (l > a.l) || (l == a.l && o < a.o); }

};



stack<sg> st;

vector<sg> dt;



inline void add(int i, int x) {

	for (; i <= n; i += i &-i)f[i] += x;

}



inline int gt(int i) {

	int a = 0;

	for (; i; i -= i&-i)a += f[i];

	return a;

}



int main() {

	scanf("%d", &n);

	f(i, 0, n) {

		int a, b;

		scanf("%d%d", &a, &b);

		dt.push_back(sg(i + 1, a, b, 0));

		in[i + 1] = a;

	}

	int q;

	scanf("%d", &q);

	f(i, 0, q) {

		int a, b;

		scanf("%d%d", &a, &b);

		dt.push_back(sg(a, b, i, 1));

	}

	sort(dt.begin(), dt.end());

	f(i, 0, dt.size()) {

		sg &a = dt[i];

		if (a.o)an[a.i] =  gt(a.r) - gt(a.l);

		else {

			int d = a.r + a.i;

			if (d < in[a.l + 1]) {

				add(a.l + 1, in[a.l + 1] - d);

				st.push(sg(in[a.l + 1], in[a.l + 1] - d, a.l + 1, 0));

			}

			else {

				while (!st.empty() && st.top().l <= d) {

					add(st.top().i, -st.top().r);

					st.pop();

				}

				if (!st.empty() && st.top().l - st.top().r < d) {

					add(st.top().i, -(d - st.top().l + st.top().r));

					st.top().r = st.top().l - d;

				}

			}

		}

	}

	f(i, 0, q)printf("%d\n", an[i]);

}