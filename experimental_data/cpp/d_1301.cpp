#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define pb push_back
#define make_unique(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define sz(a) int64_t(a.size())

const LL mod = 1e9 + 7;


template<class T>
istream& operator >> (istream& in, vector<T>& v){ for (auto &x : v) { in >> x; } return in; }

template<class T, class U>
istream& operator >> (istream& in, pair<T, U> & v){ in >> v.X >> v.Y;return in; }

template<class T, class U>
ostream& operator << (ostream& out, pair<T, U> & v){ out << v.X << " " << v.Y;return out; }

template<class T>
void chkmax(T &a, T b) {
    a = max(a, b);
    return;
}

template<class T>
void chkmin(T &a, T b) {
    a = min(a, b);
    return;
}

LL ppow (LL x, LL s) {
    if (!s) return 1;
    if (!(s - 1)) return x % mod;
    if (s % 2) return (x * ppow (x, s - 1)) % mod;
    LL b = ppow (x, s / 2);
    return (b * b) % mod;
}

vector<int> zf (string s) {

	int n = sz(s);

	vector<int> z (n);

	for (int i = 1, l = 0, r = 0; i < n; i++) {

		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);

		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;

		if (i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;

	}

	return z;
}

vector<int> pf(string p) {
    int n = sz(p);
    vector<int> pref_fun(n, 0);

    for (int i = 1;i < n;i++) {
        int j = pref_fun[i - 1];
        while (j > 0 && p[i] != p[j])
            j = pref_fun[j - 1];
        if (p[i] == p[j])
            j++;
        pref_fun[i] = j;
    }
    return pref_fun;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 4*n*m - 2*n - 2*m) {
        cout << "NO\n";
        return 0;
    }
    vector<pair<int, string> > ans;
    for (int i = 0;i < n;i++) {
        if (i == 0) {
            if (m > 1) {
                if (k >= m - 1) {
                    ans.pb({m - 1, "R"});
                    k -= m - 1;
                }else {
                    if (k == 0) {
                        break;
                    }
                    ans.pb({k, "R"});
                    k = 0;
                    break;
                }
                if (k >= m - 1) {
                    ans.pb({m - 1, "L"});
                    k -= m - 1;
                }else {
                    if (k == 0) {
                        break;
                    }

                    ans.pb({k, "L"});
                    k = 0;
                    break;
                }
            }
        }else {
            if (k >= 1) {
                ans.pb({1, "D"});
                k--;
            }else {
                break;
            }
            if (m > 1) {
                if (k >= (m - 1)*3) {
                    ans.pb({m - 1, "RUD"});
                    k -= (m - 1)*3;
                }else {
                    if (k == 0) {
                        break;
                    }

                    int cnt_f = k/3;
                    int cnt_n_f = k%3;
                    if (cnt_f) {
                        ans.pb({cnt_f, "RUD"});
                    }
                    if (cnt_n_f) {
                        string t = "RUD";
                        ans.pb({1, t.substr(0, cnt_n_f)});
                    }
                    k = 0;
                    break;
                }
                if (k >= m - 1) {
                    ans.pb({m - 1, "L"});
                    k -= m - 1;
                }else {
                    if (k == 0) {
                        break;
                    }

                    ans.pb({k, "L"});
                    k = 0;
                    break;
                }
            }
        }
    }
    if (k) ans.pb({k, "U"});
    cout << "YES\n" << sz(ans) << '\n';
    for (auto x : ans) {
        cout << x << '\n';
    }
    return 0;
}