#include<stdio.h>

#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define f(i,x,n) for (int i = x;i < n;++i)



set<int> st;



void go(ll x) {

	if (x >= 1e9)return;

	st.insert(x);

	go(x * 10 + 4);

	go(x * 10 + 7);

}



int main() {

	int l1, l2, r1, r2, k;

	scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k);

	int s1 = r1 - l1 + 1, s2 = r2 - l2 + 1;

	go(4), go(7);

	st.insert(0);

	int c = 0;

	long double an = 0.0;

	set<int>::iterator it = st.begin(), it0 = st.begin();

	while (it != st.end() && c != k)++it, ++c;

	if (c != k) { printf("0"); return 0; }

	st.insert(1e9 + 1);

	while (*it != 1e9 + 1) {

		set<int>::iterator t = it++;

		int lr = *t, rr = *it - 1;

		int lr1 = max(lr, l1), rr1 = min(rr, r1), lr2 = max(lr, l2), rr2 = min(rr, r2);

		t = it0++;

		int LL = *t + 1, rl = *it0;

		int ll1 = max(LL, l1), rl1 = min(rl, r1), ll2 = max(LL, l2), rl2 = min(rl, r2);

		if (rr1 >= lr1 && rl2 >= ll2)an += (long double)(rr1 - lr1 + 1) / s1 * (rl2 - ll2 + 1) / s2;

		if (rl1 >= ll1 && rr2 >= lr2)an += (long double)(rl1 - ll1 + 1) / s1 * (rr2 - lr2 + 1) / s2;

		if (k == 1 && lr1 == rl2 && lr2 == rl1)an -= (long double)1 / s1 / s2;

	}

	printf("%.10lf", (double)an);

}