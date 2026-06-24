#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

template<size_t N>
struct Matrix {
	long long x[N][N];
	Matrix operator*(const Matrix& rhs) const {
		Matrix re;
		memset(&re.x[0][0], 0, sizeof(re.x[0][0]) * N * N);
		for (int i = 0; i < N; i++)
			for (int k = 0; k < N; k++)
				for (int j = 0; j < N; j++)
					re.x[i][j] = (re.x[i][j] + x[i][k] * rhs.x[k][j]) % MOD;
		return re;
	}
	Matrix operator^(int p) const {
		Matrix b = *this;
		Matrix re;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				re.x[i][j] = i == j;
		while (p) {
			if (p & 1)
				re = re * b;
			b = b * b;
			p /= 2;
		}
		return re;
	}
	void MultiplyVector(long long tar[N], long long tmp[N]) const {
		for (int i = 0; i < N; i++) {
			tmp[i] = 0;
			for (int j = 0; j < N; j++)
				tmp[i] = (tmp[i] + x[i][j] * tar[j]) % MOD;
		}
		for (int i = 0; i < N; i++)
			tar[i] = tmp[i];
	}
	void Show() const {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				printf("%lld%c", x[i][j], " \n"[j == N - 1]);
	}
};

void add(long long& a, long long b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int n, a[1005], m, at, ok[3];
vector<pair<int, int>> v[1005];
long long dp[64], ndp[64], sg[4], cur[4], ncur[4];
Matrix<64> mat[3], ms[30], mt;

void go(int p) {
	// printf("go(%d)\n", p);
	for (int i = 0; i < 30; i++)
		if (p & (1 << i))
			ms[i].MultiplyVector(dp, ndp);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int ta, tb, tc;
		scanf("%d%d%d", &ta, &tb, &tc);
		v[ta].emplace_back(tb, tc - 1);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", ok + j);
		for (int j = 0; j < 64; j++) {
			int base = j >> 2;
			set<int> s;
			if (ok[0]) s.insert((j >> 4) & 3);
			if (ok[1]) s.insert((j >> 2) & 3);
			if (ok[2]) s.insert((j >> 0) & 3);
			if (!s.count(0)) base ^= 0 << 4;
			else if (!s.count(1)) base ^= 1 << 4;
			else if (!s.count(2)) base ^= 2 << 4;
			else base ^= 3 << 4;
			mat[i].x[base][j]++;
			ms[0].x[base][j]++;
			// printf("%d %d > %d (%d%d%d>%d%d%d)\n", i, j, base, (j >> 4) & 3, (j >> 2) & 3, (j >> 0) & 3, (base >> 4) & 3, (base >> 2) & 3, (base >> 0) & 3);
		}
	}
	for (int i = 1; i < 30; i++)
		ms[i] = ms[i - 1] * ms[i - 1];
	cur[0] = 1;
	for (int i = 1; i <= n; i++) {
		at = 1;
		sort(v[i].begin(), v[i].end());
		memset(dp, 0, sizeof(dp[0]) * 64);
		for (int j = 0; j < 64; j++) dp[j] = 0;
		dp[15] = !v[i].empty() && v[i].front().first == 1 ? 1 : 3;
		for (int j = 0; j < v[i].size(); j++) {
			if (j && v[i][j].first == v[i][j - 1].first) {
				if (v[i][j].second != v[i][j].second) {
					puts("0");
					return 0;
				}
				continue;
			}
			if (v[i][j].first == 1) continue;
			go(v[i][j].first - 1 - at);
			mat[v[i][j].second].MultiplyVector(dp, ndp);
			at = v[i][j].first;
		}
		// printf("dp="); for (int j = 0; j < 64; j++) printf("%lld ", dp[j]); puts("");
		go(a[i] - at);
		// printf("dp="); for (int j = 0; j < 64; j++) printf("%lld ", dp[j]); puts("");
		sg[0] = sg[1] = sg[2] = sg[3] = 0;
		// for (int j = 0; j < 64; j++) if (dp[j]) printf("+%lld %d %d\n", dp[j], j, j >> 4);
		for (int j = 0; j < 64; j++) add(sg[j >> 4], dp[j]);
		// for (int j = 0; j < 4; j++) printf("%lld ", sg[j]); puts("");
		for (int j = 0; j < 4; j++) ncur[j] = 0;
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				ncur[j ^ k] = (ncur[j ^ k] + cur[j] * sg[k]) % MOD;
		for (int j = 0; j < 4; j++) cur[j] = ncur[j];
	}
	printf("%lld\n", cur[0]);
}