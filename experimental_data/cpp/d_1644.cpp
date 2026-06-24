/*************************************
*    author: marvinthang             *
*    created: 22.02.2022 21:33:47    *
*************************************/

#include <bits/stdc++.h>

using namespace std;

#define   scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)
#define  print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)
#define     superspeed  ios_base::sync_with_stdio(false); cin.tie(nullptr); // cout.tie(nullptr);
#define     file(name)  if (fopen (name".inp", "r")) { freopen (name".inp", "r", stdin); freopen (name".out", "w", stdout); }

template <class U, class V>  scan_op(pair <U, V>)   { return in >> u.first >> u.second; }
template <class U, class V>  print_op(pair <U, V>)  { return out << '(' << u.first << ", " << u.second << ')'; }
template <class T>           print_op(vector <T>)   { out << '{'; for (size_t i = 0; i + 1 < u.size(); i++) out << u[i] << ", "; if (!u.empty()) out << u.back(); return out << '}'; }

const 	  double PI = 3.1415926535897932384626433832795; // acos(-1.0); atan(-1.0);
const 	  int dir[] = {0, 1, 0, -1, 0}; // {0, 1, 1, -1, -1, 1, 0, -1, 0};
const  long long oo = 1e18;
const 		int MAX = 2e5 + 5;

namespace Mod {

    const int MOD = 998244353;
    int sum(const int &x, const int &y){
        int res = x + y;
        if (res >= MOD) res -= MOD;
        return res;
    }

    int diff(const int &x, const int &y){
        int res = x - y;
        if (res < 0) res += MOD;
        return res;
    }

    void add(int &x, const int &y){
        x += y;
        if (x >= MOD) x -= MOD;
    }

    void sub(int &x, const int &y){
        x -= y;
        if (x < 0) x += MOD;
    }

    void mul(int &x, const int &y){
        x = 1LL * x * y % MOD; 
    }

    int MUL(int x, int y){
        return 1LL * x * y % MOD;
    }

    int Pow(int a, int n){
        if (n == 0) return 1;
        if (n == 1) return a;
        int Res = Pow(a, n >> 1);
        mul(Res, Res);
        if (n & 1) return MUL(Res, a);
        return Res;
    }

    void Div(int &a, const int &b){
        mul(a, Pow(b, MOD - 2));
    }

    int DIV(int a, int b){
        return MUL(a, Pow(b, MOD - 2));
    }

    inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned &out_m) {
        unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
        #ifdef __GNUC__
        asm(
            "divl %4 \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (y)
        );
        #else
        __asm {
            mov edx, dword ptr[xh];
            mov eax, dword ptr[xl];
            div dword ptr[y];
            mov dword ptr[d], eax;
            mov dword ptr[m], edx;
        };
        #endif
        out_d = d; out_m = m;
    }

    template <int MOD>
    struct ModInt {
        
        unsigned int val;

        ModInt(): val(0) { }
        ModInt(const long long &x) { *this = x; }

        ModInt & normalize(const unsigned int &v) {
            val = v >= MOD ? v - MOD : v;
            return *this;
        }

        bool operator ! () { return !val; }

        ModInt & operator = (const ModInt &x) { val = x.val; return *this; }
        ModInt & operator = (const long long &x) { return normalize(x % MOD + MOD); }

        ModInt operator - () { return normalize(MOD - val); }

        ModInt & operator += (const ModInt &other) { return normalize(val + other.val); }
        ModInt & operator -= (const ModInt &other) { return normalize(val + MOD - other.val); }
        ModInt & operator /= (const ModInt &other) { return *this *= other.inv(); }
        ModInt & operator ^= (const ModInt &n) { return *this = *this ^ n; }
        ModInt & operator ^= (const long long &n) { return *this = *this ^ n; }

        ModInt & operator *= (const ModInt &other) {
            unsigned dummy;
            fasterLLDivMod((unsigned long long) val * other.val, MOD, dummy, val);
            return *this;
        }

        ModInt operator + (const ModInt &other) const { return ModInt(*this) += other; }
        ModInt operator - (const ModInt &other) const { return ModInt(*this) -= other; }
        ModInt operator * (const ModInt &other) const { return ModInt(*this) *= other; }
        ModInt operator / (const ModInt &other) const { return ModInt(*this) /= other; }

        ModInt pow(const ModInt &Exp) const {
            ModInt res = 1, a = *this;
            int n = Exp.val;
            while (n) {
                if (n & 1) res = res * a;
                a = a * a;
                n >>= 1;
            }
            return res;
        }

        ModInt pow(long long Exp) const {
            assert(Exp >= 0);
            ModInt res = 1, a = *this;
            while (Exp) {
                if (Exp & 1) res = res * a;
                a = a * a;
                Exp >>= 1;
            }
            return res;
        }

        ModInt inv() const { return pow(MOD - 2); }

        ModInt & operator ++ () { return *this += 1; }
        ModInt & operator -- () { return *this -= 1; }
        ModInt operator ++ (int) { ModInt old = *this; operator ++(); return old; }
        ModInt operator -- (int) { ModInt old = *this; operator --(); return old; }

        friend ModInt operator + (const long long &x, const ModInt &y) { return ModInt(x) + y; }
        friend ModInt operator - (const long long &x, const ModInt &y) { return ModInt(x) - y; }
        friend ModInt operator * (const long long &x, const ModInt &y) { return ModInt(x) * y; }
        friend ModInt operator / (const long long &x, const ModInt &y) { return ModInt(x) / y; }
        friend ostream & operator << (ostream &out, const ModInt &x) { return out << x.val; }
        friend istream & operator >> (istream &in, ModInt &x) { long long a; in >> a; x = a; return in; }

        bool operator < (const ModInt &other) const { return val < other.val; }
        bool operator > (const ModInt &other) const { return val > other.val; }
        bool operator <= (const ModInt &other) const { return val <= other.val; }
        bool operator >= (const ModInt &other) const { return val >= other.val; }
        bool operator == (const ModInt &other) const { return val == other.val; }
        bool operator != (const ModInt &other) const { return val != other.val; }
        explicit operator bool() const{ return val; }

        ModInt operator >>= (const int &x) const { return normalize((int) val >> x); }
        ModInt operator >> (const int &x) const { return ModInt(*this) >>= x; }
        ModInt operator <<= (const int &x) const { return ModInt((long long) val << x); }
        ModInt operator << (const int &x) const { return ModInt(*this) <<= x; }
        ModInt operator &= (const int &x) const { return normalize((int) val & x); }
        ModInt operator & (const int &x) const { return ModInt(*this) &= x; }
        ModInt operator |= (const int &x) const { return ModInt((int) val | x); }
        ModInt operator | (const int &x) const { return ModInt(*this) |= x; }
        ModInt operator ^= (const int &x) const { return ModInt((int) val ^ x); }
        ModInt operator ^ (const int &x) const { return ModInt(*this) ^= x; }
        ModInt operator ~ () const { return ModInt(~val); }

        // operator int() { return val; }

    };  

    using Modular = ModInt <MOD>;

}

using namespace Mod;


int N, M, K, Q, x[MAX], y[MAX];
bool col[MAX], row[MAX];

void solve(void) {
	cin >> N >> M >> K >> Q;
	for (int i = 1; i <= Q; ++i) cin >> x[i] >> y[i];
	int cnt = 0;
	int r = N, c = M;
	for (int i = Q; i > 0; --i) {
		if (!r || !c) continue;
		if (row[x[i]] && col[y[i]]) continue;
		++cnt;
		if (!row[x[i]]) --r;
		if (!col[y[i]]) --c;
		row[x[i]] = col[y[i]] = true;
	}
	cout << Modular(K).pow(cnt) << '\n';
	for (int i = 1; i <= Q; ++i) row[x[i]] = col[y[i]] = false;
}

int main(void) {
	superspeed;
	file("codeforces");
	int t; cin >> t; while (t--)
		solve();
	return 0;
}