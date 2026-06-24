#include <bits/stdc++.h>
#define pii pair<int, int>
#define piii tuple<int, int, int>
#define pll pair<long long, long long>
#define L(n) (n << 1)
#define R(n) (n << 1 | 1)
#define print_vector(n, delimiter) for(auto a0 : n) cout << a0 << delimiter; cout << endl;
#define vector_sort(n) sort(n.begin(), n.end())
#define print_array(n, l, r, delimiter) for(int a0 = l; a0 <= r; a0++) cout << n[a0] << delimiter; cout << '\n';
#define REP(i, l, r) for (int i = l; i <= r; i++) 
#define VREP(i, l, r) for (int i = l; i >= r; i--) 
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define ABS(a) ((a) > 0 ? (a) : -(a))
#define LOG2(n) (31 - __builtin_clz(n))
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
istream & operator >> (istream &in, pair<T, T> &p) {
	in >> p.first >> p.second;
	return in;
}

template<class T>
ostream & operator <<(ostream &out, pair<T, T> &p) {
	out << p.first << ' ' << p.second;
	return out;
}

template<class Tuple, std::size_t N>
struct TuplePrinter {
	static void print(ostream &out, const Tuple& t) {
		TuplePrinter<Tuple, N-1>::print(out, t);
		out << ' ' << get<N-1>(t);
	}
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
	static void print(ostream &out, const Tuple& t) {
		out << get<0>(t);
	}
};

template<class... Args>
ostream & operator <<(ostream &out, const tuple<Args...> &p) {
	TuplePrinter<decltype(p), sizeof...(Args)>::print(out, p);
	return out;
}

const int MAX_N = 2e5;

int N, M, Q;
int A[MAX_N + 5];
int lList[MAX_N + 5];
pair<int, int> T[MAX_N + 5];

int B[MAX_N + 5];
int pos[MAX_N + 5];
int p_B;

int BIT[MAX_N + 5];

void upd(int idx, int val) {
	if (idx == 0) return;
	for (int i = idx; i <= N; i += i & -i) {
		BIT[i] += val;
	}
}

int query(int idx) {
	int ans = 0;
	for (int i = idx; i > 0; i -= i & -i) {
		ans += BIT[i]; 
	}
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> Q;	

	int sum = 0;
	set<int> seto;
	for (int i = 1; i <= N; i++) {
		char ch;
		cin >> ch;
		A[i] = ch == '1';
			sum += A[i];
		seto.emplace(i);
	}
	seto.emplace(N+1);
	
	p_B = 0;
	for (int i = 1; i <= M; i++) {
		int l, r;
		cin >> l >> r;

		if (!seto.count(l)) {
			l = *seto.upper_bound(l);
		}

		while (l <= r) {
			seto.erase(l);
			B[++p_B] = l;
			pos[l] = p_B;
			l = *seto.upper_bound(l);
		}
	}
	// print_array(B, 1, p_B, ' ');

	for (int i = 1; i <= p_B; i++) {
		if (A[B[i]]) upd(i, 1);
	}

	for (int i = 1; i <= Q; i++) {
		int idx;
		cin >> idx;
		if (A[idx] == 0) {
			upd(pos[idx], 1);
			// cout << pos[idx] << " " << 1 << "\n";
			sum++;
		} else {
			upd(pos[idx], -1);
			// cout << pos[idx] << " " << -1 << "\n";
			sum--;
		}
		A[idx] ^= 1;
		// cout << "sum " << sum << "\n";
		// for (int i = 1; i <= p_B; i++) {
		// 	cout << A[B[i]] << " ";
		// }
		int ssum = min(sum, p_B);
		// cout << "\n";
		cout << ssum - query(ssum) << "\n";
	}
}