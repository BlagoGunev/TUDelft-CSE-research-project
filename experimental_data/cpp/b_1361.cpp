// LUOGU_RID: 102082825
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 5;

using i64 = long long;
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template<int P>
struct Mint {
    int x;
    Mint(int x = 0) : x(norm(x)) {}
    Mint(i64 x) : x(norm(x % P)) {}
    
    int norm(int x) {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    int val() const {
        return x;
    }
    Mint operator-() const {
        return Mint(norm(P - x));
    }
    Mint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Mint &operator*=(const Mint &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        return *this *= rhs.inv();
    }
    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
};

constexpr int P = 1e9 + 7;
using Z = Mint<P>;

void solve() {
	int n, p;
	std::cin >> n >> p;
		
	std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.rbegin(), a.rend());

    if (p == 1) {
        std::cout << n % 2 << "\n";
        return;
    }

    Z s = power(Z(p), a[0]);
    // std::cerr << s << "\n";
    std::vector<std::pair<int, int>> stk;
    stk.emplace_back(a[0], 1);
    for (int i = 1; i < n; i++) {
        // std::cerr << "--------\n";
        // for (auto [x, v] : stk) std::cout << x << " " << v << "\n";
        if (stk.empty()) {
            s += power(Z(p), a[i]);
            stk.emplace_back(a[i], 1);
        } else {
            // std::cerr << i << ": " <<  s << " " << power(Z(p), a[i]) << "-\n";
            s -= power(Z(p), a[i]);
            // std::cerr << s << " " << power(Z(p), a[i]) << "\n";
            // if (s.val() == 0) {
            //     while (!stk.empty()) stk.pop_back();
            //     continue;
            // }
            // if (stk.back().first == a[i] && stk.size() == 1) {
            //     assert(s.val() == 0);
            //     stk.pop_back();
            //     continue;
            // }
            if (stk.back().first == a[i]) {
                stk.back().second++;
                while (stk.size() >= 2 && stk.back().second >= p) {
                    int x = stk.back().first;
                    stk.pop_back();
                    if (stk.empty()) {
                        break;
                    }
                    if (!stk.empty() && stk.back().first == x + 1) {
                        stk.back().second++;
                    } else {
                        stk.emplace_back(x + 1, 1);
                    }
                } 
                if (stk.size() == 1 && stk.back().second % 2 == 0) {
                    stk.pop_back();
                }
            } else {
                stk.emplace_back(a[i], 1);
            }
        }
    }
    std::cout << s << "\n";
}

int main() {	
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);

	int T; std::cin >> T;
	
	while (T--) {
		solve();
	}
	
	return 0;
}