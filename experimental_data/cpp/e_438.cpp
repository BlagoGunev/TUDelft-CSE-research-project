//  Created by Sengxian on 5/23/16.

//  Copyright (c) 2016年 Sengxian. All rights reserved.

//  Codeforces 438E 多项式开根（分治FFT）

#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

inline int ReadInt() {

	static int n, ch;

	n = 0, ch = getchar();

	while (!isdigit(ch)) ch = getchar();

	while (isdigit(ch)) n = (n << 3) + (n << 1) + ch - '0', ch = getchar();

	return n;

}



const int modu = 998244353, g = 3, inv2 = 499122177;

 

namespace other {

	template <typename T>

	inline void mod(T &x) {

		if (x < 0) ((x %= modu) += modu) %= modu;

		else if (x >= modu) x %= modu;

	}

	inline int mod_pow(ll a, int b, int modu = ::modu) {

		ll res = 1;

		while (b) {

			if (b & 1) mod(res *= a);

			mod(a *= a);

			b >>= 1;

		}

		return res;

	}

	#define inv(n) mod_pow((n), modu - 2)

}

using namespace other;





namespace FNT {

	typedef unsigned int uint;

	typedef vector<int> vi;

	void DFT(vi &a, bool rev = false) {

		int n = a.size();

		for (int i = 0, j = 0; i < n; ++i) {

			if (i > j) swap(a[i], a[j]);

			for (int l = n >> 1; (j ^= l) < l; l >>= 1);

		}

		for (int l = 1, dl = 2; l < n; l <<= 1, dl <<= 1) {

			ll omega = 1, omega_n = mod_pow(g, (modu - 1) / l / 2, modu);

			if (rev) omega_n = inv(omega_n);

			for (int k = 0; k < l; ++k, mod(omega *= omega_n))

				for (int st = k; st < n; st += dl) {

					ll tmp = (ll)omega * a[st + l] % modu;

					mod(a[st + l] = a[st] - tmp);

					mod(a[st] += tmp);

				}

		}

		if (rev) for (int i = 0, iv = inv(n); i < n; ++i) a[i] = (ll)a[i] * iv % modu;

	}



	vi& operator *= (vi &v1, const vi &v2) {

		int s = 1, ss = (int)v1.size() + (int)v2.size();        

		while (s < ss) s <<= 1;

		vi a(s, 0), b(s, 0);

		for (unsigned int i = 0; i < v1.size(); ++i) a[i] = v1[i];

		for (unsigned int i = 0; i < v2.size(); ++i) b[i] = v2[i];

		DFT(a), DFT(b);

		for (int i = 0; i < s; ++i) a[i] = (ll)a[i] * b[i] % modu;

		DFT(a, true);

		v1 = vi(s, 0);

		for (int i = 0; i < s; ++i) v1[i] = a[i];

		return v1;

	}

	

	vi& inverse(const vi &v) {

		static vi ret;

		int n = v.size(), n1 = (n + 1) / 2;

		if (n == 1) ret = vi(1, inv(v[0]));

		else {

			vi tmp(n1, 0);

			for (int i = 0; i < n1; ++i) tmp[i] = v[i];

			tmp = inverse(tmp);

			for (int i = 0; i < n1; ++i) mod(ret[i] *= 2);

			ret.resize(n);

			(tmp *= tmp) *= v;

			tmp.resize(n);

			for (int i = 0; i < n; ++i) mod(ret[i] -= tmp[i]);

		}

		return ret;

	}



	vi& getRoot(const vi &v) {

		static vi ret;

		int n = v.size(), n1 = (n + 1) / 2;

		if (n == 1) ret = vi(1, 1); //本题常数是 1

		else {

			vi tmp(n1, 0);

			for (int i = 0; i < n1; ++i) tmp[i] = v[i];

			getRoot(tmp);

			ret.resize(n); //注意我们逆元，是在模 n 意义下的，必须要扩展到 n！

			vi &iv = inverse(ret);

			iv *= v;

			for (int i = 0; i < n; ++i) ret[i] = ((ll)ret[i] + iv[i]) * inv2 % modu;

		}

		return ret;

	}

}

using namespace FNT;



int n, m;



int main() {

#ifndef ONLINE_JUDGE

	freopen("test.in", "r", stdin);

#endif

	n = ReadInt(), m = ReadInt();

	vi c(m + 1, 0);

	for (int i = 0; i < n; ++i) {

		int x = ReadInt();

		if (x <= m) c[x] = modu - 4; //根式内部合起来写了

	}

	c[0] = 1;

	vi root = getRoot(c);

	root[0]++;

	root = inverse(root);

	for (int i = 1; i <= m; ++i) printf("%d\n", root[i] * 2 % modu);

	return 0;

}