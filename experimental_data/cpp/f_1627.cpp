#include <algorithm>

#include <cstring>

#include <cstdio>

#include <ctime>

#include <queue>

typedef long long ll;

typedef __int128_t lll;

typedef unsigned int uint;

typedef unsigned long long ull;

typedef __uint128_t ulll;

namespace fastIO{

	class endline{}Endl;

	class fastIn{

		public:

			inline fastIn operator>>(char& x){scanf(" %c", &x);return *this;}

			inline fastIn operator>>(char* x){scanf("%s", x);return *this;}

			inline fastIn operator>>(float& x){scanf("%f", &x);return *this;}

			inline fastIn operator>>(double& x){scanf("%lf", &x);return *this;}

			inline fastIn operator>>(long double& x){scanf("%Lf", &x);return *this;}

			inline fastIn operator>>(int& x){char ch = getchar();int t = 1;x = 0;while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();x *= t;return *this;}

			inline fastIn operator>>(uint& x){char ch = getchar();x = 0;while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();return *this;}

			inline fastIn operator>>(ll& x){char ch = getchar();int t = 1;x = 0;while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();x *= t;return *this;}

			inline fastIn operator>>(ull& x){char ch = getchar();x = 0;while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();return *this;}

			inline fastIn operator>>(lll& x){char ch = getchar();int t = 1;x = 0;while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();x *= t;return *this;}

			inline fastIn operator>>(ulll& x){char ch = getchar();x = 0;while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();return *this;}

	}fin;

	class fastOut{

		int l = 10;char buf[101];

		public:

			inline fastOut operator<<(char x){putchar(x);return *this;}

			inline fastOut operator<<(char* x){printf("%s", x);return *this;}

			inline fastOut operator<<(const char* x){printf("%s", x);return *this;}

			inline fastOut operator<<(float x){sprintf(buf, "%%.%df", l), printf(buf, x);return *this;}

			inline fastOut operator<<(double x){sprintf(buf, "%%.%dlf", l), printf(buf, x);return *this;}

			inline fastOut operator<<(long double x){sprintf(buf, "%%.%dLf", l), printf(buf, x);return *this;}

			inline fastOut operator<<(int x){if (x < 0) putchar('-'), x = -x;int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}

			inline fastOut operator<<(uint x){int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}

			inline fastOut operator<<(ll x){if (x < 0) putchar('-'), x = -x;int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}

			inline fastOut operator<<(ull x){int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}

			inline fastOut operator<<(lll x){if (x < 0) putchar('-'), x = -x;int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}

			inline fastOut operator<<(ulll x){int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}

			inline fastOut operator<<(endline x){putchar('\n');return *this;}

			inline void cgelft(int x){l = x;}

	}fout;

}

struct custom_hash{

    static ull splitmix64(ull x){

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }

    uint operator()(ull x)const{

        static const ull FIXED_RANDOM = (ull)time(0) << 32 | time(0);

        return splitmix64(x + FIXED_RANDOM);

    }

};



using namespace fastIO;

using namespace std;

int head[300001], _cnt;

struct edge{

	int v, w, nxt;

}e[2000001];

inline void addedge(int u, int v, int w){

	e[++ _cnt] = {v, w, head[u]};

	head[u] = _cnt;

}

inline void add2edges(int u, int v, int w){addedge(u, v, w), addedge(v, u, w);}

int t, n, m, d[300001], X1, Y1, X2, Y2, id[501][501], cnt[501][501][2];

priority_queue<pair<int, int> > q;

int main(){

	fin >> t;

	while (t --){

		fin >> m >> n, _cnt = 0;

		for (int i = 0;i <= n;i ++){

			for (int j = 0;j <= n;j ++){

				id[i][j] = i * (n + 1) + j;

				head[id[i][j]] = -1, d[id[i][j]] = 1e9;

				cnt[i][j][0] = cnt[i][j][1] = 0;

			}

		}

		for (int i = 1;i <= m;i ++){

			fin >> X1 >> Y1 >> X2 >> Y2;

			int x, y, d, dx, dy;

			if (X1 + 1 == X2) x = X1, y = Y1 - 1, d = 0;

			if (X2 + 1 == X1) x = X2, y = Y2 - 1, d = 0;

			if (Y1 + 1 == Y2) x = X1 - 1, y = Y1, d = 1;

			if (Y2 + 1 == Y1) x = X2 - 1, y = Y2, d = 1;

			dx = abs(x - n / 2), dy = abs(y - n / 2);

			cnt[x][y][d] ++;

			if (x > n / 2) x = n / 2 - dx;

			else x = n / 2 + dx;

			if (y > n / 2) y = n / 2 - dy;

			else y = n / 2 + dy;

			if (d) x --;else y --;

			cnt[x][y][d] ++;

		}

		for (int i = 0;i <= n;i ++){

			for (int j = 0;j <= n;j ++){

				if (i < n) add2edges(id[i][j], id[i + 1][j], cnt[i][j][1]);

				if (j < n) add2edges(id[i][j], id[i][j + 1], cnt[i][j][0]);

			}

		}

		d[id[n / 2][n / 2]] = 0, q.push(make_pair(0, id[n / 2][n / 2]));

		while (q.size()){

			int u = q.top().second;q.pop();

			for (int i = head[u];i != -1;i = e[i].nxt){

				auto [v, w, _] = e[i];

				if (d[v] > d[u] + w) d[v] = d[u] + w, q.push(make_pair(-d[v], v));

			}

		}

		fout << m - d[id[n][n]] << Endl;

	}

}