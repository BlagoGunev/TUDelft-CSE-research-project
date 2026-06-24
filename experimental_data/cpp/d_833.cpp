#include<bits/stdc++.h>
using namespace std;

#define MAX 100002

int n;

struct st{
	int go;
	long long int cost;
	bool flag;
};

vector<st> v[MAX];

int dp[MAX];
bool ng[MAX];

inline void find_cent(int b,int pr=-1){
	dp[b] = 1;
	for (int i = 0; i < v[b].size(); i++){
		int go = v[b][i].go;
		if (ng[go] == false){
			if (go != pr){
				find_cent(go, b);
				dp[b] += dp[go];
			}
		}
	}
}
inline pair<int, int> find_cent2(int b, int pr = -1,int all=0){
	pair<int, int> ans = { INT_MAX, INT_MAX };
	int sum2 = all-1;
	int U = 0;
	for (int i = 0; i < v[b].size(); i++){
		int go = v[b][i].go;
		if (ng[go] == false && go != pr){
			ans=min(ans,find_cent2(go, b,all));
			sum2 -= dp[go];
			U = max(U, dp[go]);
		}
	}
	U = max(U, sum2);
	ans = min(ans, make_pair(U, b));
	return ans;
}
int cent(int b){
	find_cent(b);
	return find_cent2(b,-1,dp[b]).second;
}
queue<int> q;

struct SS{
	int first;
	int second;
	long long int val;
};
vector<SS> tmp;
vector<SS> tmp2;
#define MOD 1000000007
long long int ans2 ;
inline void dfs(int b, int c1, int c2, int pr, long long int V){
	if (V >= MOD)V %= MOD;
	if (c1 * 2 >= c2&&c2 * 2 >= c1){
		ans2 *= V;
		if (ans2 >= MOD)ans2 %= MOD;
	}
	for (int i = 0; i < v[b].size(); i++){
		if (v[b][i].go == pr || ng[v[b][i].go])continue;
		dfs(v[b][i].go, c1 + (v[b][i].flag == false), c2 + (v[b][i].flag == true), b, V*v[b][i].cost);
	}
	tmp.push_back({ 2 * c1 - c2, 2 * c2 - c1, V });
	tmp2.push_back({2 * c1 - c2, 2 * c2 - c1, V});
}
struct query{
	int X;
	int Y;
	bool flag;
	long long int val;
};
bool cmp(query &a, query &b){
	if (a.X == b.X){
		if (a.Y == b.Y){
			return a.flag < b.flag;
		}
		return a.Y < b.Y;
	}
	return a.X < b.X;
}
long long int bit[300002];
int S;

void resize(int f){
	S = f;
	for (int i = 0; i < S; i++){
		bit[i] = 1;
	}
}
void add(int i, int x){
	i++;
	while (i < S){
		bit[i] *=x;
		if (bit[i] >= MOD)bit[i] %= MOD;
		i += i&-i;
	}
}
int sum(int i){
	i++;
	long long int r = 1;
	while (i){
		r *= bit[i];
		if (r >= MOD)r %= MOD;
		i -= i&-i;
	}
	return r;
}
struct solver{
	vector<int> ys;
	vector<query> Q;
	int solve(vector<SS> &vv){
		for (int i = 0; i < vv.size(); i++){
			ys.push_back(-vv[i].second);
			Q.push_back({ -vv[i].first, -vv[i].second, false ,vv[i].val});
			Q.push_back({ vv[i].first, vv[i].second, true ,vv[i].val});
		}
		long long int R = 1;
		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		sort(Q.begin(), Q.end(), cmp);
		resize(ys.size() + 3);
		for (int i = 0; i < Q.size(); i++){
			if (Q[i].flag == false){
				int Y = lower_bound(ys.begin(), ys.end(), Q[i].Y) - ys.begin();
				add(Y, Q[i].val);
			}
			else{
				int Y = upper_bound(ys.begin(), ys.end(), Q[i].Y) - ys.begin();
				Y--;
				if (Y>=0){
					R *= sum(Y);
					if (R >= MOD)R %= MOD;
				}
			}
		}
		return R;
	}
};
long long int ppow(long long int i, long long int j){
	long long int res = 1LL;
	while (j){
		if ((j & 1LL)){
			res *= i;
			if (res >= MOD){
				res %= MOD;
			}
		}
		j >>= 1;
		i *= i;
		if (i >= MOD){
			i %= MOD;
		}
	}
	return res;
}
long long int modpow(int a, int b, long long int m) {
	long long int ret = 1;
	while (b > 0) {
		if (b & 1) ret = 1LL * ret * a % m;
		a = 1LL * a * a % m;
		b /= 2;
	}
	return ret;
}

bool issquare(int a, long long int p) {
	return modpow(a, (p - 1) / 2, p) == 1;
}

int modsqrt(int a, long long int p) {
	if (a == 0) return 0;
	if (p == 2) return a;
	if (!issquare(a, p)) return -1;
	int b = 2;
	while (issquare((1LL * b * b - a + p) % p, p)) b++;
	int w = (1LL * b * b - a + p) % p;

	auto mul = [&](pair<int, int> u, pair<int, int> v) {
		int a = (1LL * u.first * v.first + 1LL * u.second * v.second % p * w) % p;
		int b = (1LL * u.first * v.second + 1LL * u.second * v.first) % p;
		return make_pair(a, b);
	};

	// (b + sqrt(b^2-a))^(p+1)/2
	int e = (p + 1) / 2;
	auto ret = make_pair(1, 0);
	auto v = make_pair(b, 1);
	while (e > 0) {
		if (e & 1) ret = mul(ret, v);
		v = mul(v, v);
		e /= 2;
	}
	return ret.first;
}
int read_int(){
	int num = 0;
	while (1){
		char c = getchar();
		if (!isdigit(c)){
			continue;
		}
		num += c - '0';
		break;
	}
	while (1){
		char c = getchar();
		if (!isdigit(c)){
			return num;
		}
		num *= 10;
		num += c - '0';
	}
}

int main(){
	ans2 = 1;
	n = read_int();
	for (int i = 1; i < n; i++){
		int a, b;
		a = read_int();
		b = read_int();
		a--;
		b--;
		int c, d;
		c = read_int();
		d = read_int();
		v[a].push_back({ b, c, d });
		v[b].push_back({ a, c, d });
	}
	int root = cent(0);
	q.push(root);
	long long int ans = 1;
	long long int D = 1;
	while (!q.empty()){
		root = q.front();
		q.pop();
		ng[root] = true;
		for (int i = 0; i < v[root].size(); i++){
			if (ng[v[root][i].go] == false){
				q.push(cent(v[root][i].go));
			}
		}
		tmp2.clear();
		for (int i = 0; i < v[root].size(); i++){
			int go = v[root][i].go;
			if (ng[go] == false){
				tmp.clear();
				dfs(go,v[root][i].flag==false,v[root][i].flag==true,root,v[root][i].cost);
				solver sol;
				D*=sol.solve(tmp);
				if (D >= MOD)D %= MOD;
			}
		}
		solver sol;
		ans *= sol.solve(tmp2);
		if (ans >= MOD)ans %= MOD;
	}
	ans *= ans2;
	ans %= MOD;
	ans *= ppow(D, MOD - 2);
	ans %= MOD;
	printf("%lld\n", ans);
	return 0;
}