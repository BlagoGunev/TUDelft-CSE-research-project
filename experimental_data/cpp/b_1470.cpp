#include <algorithm>

#include <cstring>

#include <cstdio>

#include <vector>

#include <ctime>

#define ll long long

#define ull unsigned long long

#define uint unsigned int

namespace fastIO{

	inline void read(int& x){

		char ch = getchar();

		int t = 1;x = 0;

		while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();

		while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();

		x *= t;

	}

	inline void read(ll& x){

		char ch = getchar();

		int t = 1;x = 0;

		while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();

		while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();

		x *= t;

	}

	inline void read(char* x){scanf("%s", x);}

	void write(int x){

		if (x < 0){putchar('-'), write(-x);return;}

		if (x > 9) write(x / 10);

		putchar(x % 10 ^ 48);

	}

	void write(ll x){

		if (x < 0){putchar('-'), write(-x);return;}

		if (x > 9) write(x / 10);

		putchar(x % 10 ^ 48);

	}

	void write(char* x){printf("%s", x);}

	void write(const char* x){printf("%s", x);}

}

struct custom_hash{

    static ull splitmix64(ull x){

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }

    uint operator()(ull x)const{

        static const ull FIXED_RANDOM = time(0) << 32 | time(0);

        return splitmix64(x + FIXED_RANDOM);

    }

};



using namespace fastIO;

using namespace std;



int t, n, m = 1000000, q, cntp, p[100001], lst[1000001], a[300001], c[1000001], ans1, ans2;

bool isnp[1000001];

ll x;

vector<int> pos;

int main(){

	isnp[1] = 1;

	for (int i = 2;i <= m;i ++){

		if (!isnp[i]) p[++ cntp] = i, lst[i] = i;

		for (int j = 1;j <= cntp && i * p[j] <= m;j ++){

			isnp[i * p[j]] = 1, lst[i * p[j]] = p[j];

			if (i % p[j] == 0) break;

		}

	}

	read(t);

	while (t --){

		read(n), ans1 = ans2 = 0, pos.clear();

		for (int i = 1;i <= n;i ++){

			read(a[i]);

			int x = a[i], res = 1;

			while (x > 1){

				if (res % lst[x] == 0) res /= lst[x];

				else res *= lst[x];

				x /= lst[x];

			}

			res *= x, c[res] ++, pos.push_back(res);

		}

		sort(pos.begin(), pos.end()), pos.erase(unique(pos.begin(), pos.end()), pos.end());

		for (int i : pos) ans1 = max(ans1, c[i]);

		for (int i : pos){

			if (c[i] % 2 == 0 && i != 1) c[1] += c[i], c[i] = 0;

		}

		ans2 = c[1];

		for (int i : pos) ans2 = max(ans2, c[i]);

		read(q);

		while (q --) read(x), write(x == 0 ? ans1 : ans2), putchar('\n');

		c[1] = 0;

		for (int i : pos) c[i] = 0;

	}

}