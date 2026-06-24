#include <bits/stdc++.h>
using namespace std;

namespace fft
{

    struct cd {
        double r, i;

        cd(double x = 0) {
            r = x; i = 0;
        }

        cd(double p, double q) {
            r = p; i = q;
        }

        double real() {
            return r;
        }

        double imag() {
            return i;
        }
    };

    cd operator+(cd a, cd b) {
        a.r += b.r;
        a.i += b.i;
        return a;
    }

    cd operator-(cd a, cd b) {
        a.r -= b.r;
        a.i -= b.i;
        return a;
    }

    cd operator*(cd a, cd b) {
        return {a.r * b.r - a.i * b.i, a.r * b.i + b.r * a.i};
    }

    cd operator/(cd a, cd b) {
        double den = b.r * b.r + b.i * b.i;
        return {(a.r * b.r + a.i * b.i) / den, (-a.r * b.i + b.r * a.i) / den};
    }

    const int MAXT = 21, MAXN = (1 << MAXT);
    int rev[MAXN];
    cd roots[MAXN];
    const double PI = 3.141592653589793238;
    cd rt;

    void build(int t = MAXT) {
        rt = {cos(PI * 2 / (1 << t)), sin(PI * 2 / (1 << t))};
        roots[0] = {1, 0};
        for (int i = 1; i < (1 << t); ++i) {
            roots[i] = roots[i - 1] * rt;
        }
        for (int i = 0; i < (1 << t) / 2; ++i) {
            rev[2 * i] = rev[i] / 2;
            rev[2 * i + 1] = rev[i] / 2 + (1 << t) / 2;
        }
    }

    void fft(vector<cd> &val, int t = MAXT) {
        for (int i = 0; i < (1 << t); ++i) {
            if (i < rev[i]) {
                swap(val[i], val[rev[i]]);
            }
        }
        for (int n = 2; n <= (1 << t); n *= 2) {
            for (int s = 0; s < (1 << t); s += n) {
                for (int i = 0; i < n / 2; ++i) {
                    cd v0 = val[s + i];
                    cd v1 = val[s + i + n / 2];
                    cd x = v1 * roots[i * ((1 << t) / n)];
                    val[s + i] = v0 + x;
                    val[s + i + n / 2] = v0 - x;
                }
            }
        }
    }

    void inv_fft(vector<cd> &val, int t = MAXT) {
        fft(val, t);
        reverse(val.begin() + 1, val.end());
        for (int i = 0; i < (1 << t); ++i) {
            val[i] = val[i] / cd((1 << t), 0);
        }
    }

}

/// #define int int64_t

using fft::cd;
using fft::PI;

vector<cd> operator*(const vector<cd> &a, const vector<cd> &b) {
    int t = 0;
    while ((1 << t) < (int)a.size() + (int)b.size()) {
        t++;
    }
    vector<cd> af((1 << t), 0), bf((1 << t), 0);
    fft::build(t);
    for (int i = 0; i < (int)a.size(); ++i) {
        af[i] = a[i];
    }
    for (int i = 0; i < (int)b.size(); ++i) {
        bf[i] = b[i];
    }
    fft::fft(af, t);
    fft::fft(bf, t);
    vector<cd> cf((1 << t), {0, 0});
    for (int i = 0; i < (1 << t); ++i) {
        cf[i] = af[i] * bf[i];
    }
    fft::inv_fft(cf, t);
    vector<cd> c((int)a.size() + (int)b.size() - 1);
    for (int i = 0; i < (int)c.size(); ++i) {
        c[i] = cf[i];
    }
    return c;
}

const int MAXA = 27;
int len[MAXA], ind[MAXA], id[MAXA];

const int MAXN = 2e5 + 100;
int check[MAXN];

int pref[MAXN * 2];

cd get(double a) {
    return {cos(a), sin(a)};
}

const double EPS = 0.025;

int main() {
    /// freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> p(MAXA);
    for (int i = 0; i < MAXA - 1; ++i) {
        int x;
        cin >> x;
        p[x - 1] = i;
    }
    p[MAXA - 1] = MAXA - 1;
    fill(id, id + MAXA, -1);
    int cur = 0;
    for (int i = 0; i < MAXA; ++i) {
        if (id[i] == -1) {
            id[i] = cur;
            int cnt = 1;
            ind[i] = 0;
            for (int j = p[i]; j != i; j = p[j], cnt++) {
                id[j] = cur;
                ind[j] = cnt;
            }
            len[i] = cnt;
            for (int j = p[i]; j != i; j = p[j]) {
                len[j] = cnt;
            }
            cur++;
        }
    }

    string s, t;
    cin >> s >> t;
    string sp = s + "{" + t;
    pref[1] = 0;
    pref[0] = -1;
    for (int i = 2; i <= (int)sp.size(); ++i) {
        pref[i] = 0;
        for (int j = pref[i - 1]; j >= 0; j = pref[j]) {
            if (id[sp[j] - 'a'] == id[sp[i - 1] - 'a']) {
                pref[i] = j + 1;
                break;
            }
        }
    }
    fill(check, check + t.size() - s.size() + 1, 1);
    for (int i = s.size(); i <= (int)t.size(); ++i) {
        if (pref[i + s.size() + 1] != (int)s.size()) {
            check[i - s.size()] = 0;
        }
    }
    vector<cd> a(s.size()), b(t.size());
    for (int i = 0; i < (int)t.size(); ++i) {
        b[i] = get(PI * 2 / len[t[i] - 'a'] * ind[t[i] - 'a']);
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        a[s.size() - i - 1] = get(PI / len[s[i] - 'a'] - PI * 2 / len[s[i] - 'a'] * ind[s[i] - 'a']);
    }
    double sum = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        sum += cos(PI / len[s[i] - 'a']);
    }
    auto res = a * b;
    for (int i = 0; i <= (int)t.size() - (int)s.size(); ++i) {
        double cur = res[i + s.size() - 1].real();
        if (cur < sum - EPS) {
            check[i] = 0;
        }
    }
    for (int i = 0; i <= (int)t.size() - (int)s.size(); ++i) {
        cout << check[i];
    }
    return 0;
}