#include <bits/stdc++.h>
#define int long long
#define pi pair<int,int>
//#define endl "\n"
using namespace std;

mt19937_64 rnd(42);
const int K = 2;
typedef array<int,K> Hash;
typedef pair<Hash,Hash> pH;
map <int,Hash> r;
Hash mod;
Hash p;
vector <Hash> power;
const int inf = 1e5;
const int INF = 1e8;

Hash operator+(Hash h1, Hash h2) {
    for (int i = 0; i<K; ++i) h1[i] = (h1[i] + h2[i]) % mod[i];
    return h1;
}
Hash operator-(Hash h1, Hash h2) {
    for (int i = 0; i<K; ++i) h1[i] = (h1[i] - h2[i] + 2*mod[i]) % mod[i];
    return h1;
}
Hash operator*(Hash h1, Hash h2) {
    for (int i = 0; i<K; ++i) h1[i] = (h1[i] * h2[i]) % mod[i];
    return h1;
}
Hash mkHash(int n) {
    Hash h;
    for (int i = 0; i<K; ++i) h[i] = (n % mod[i] + mod[i]) % mod[i];
    return h;
}
int binpow(int a, int n, int m) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % m;
            n--;
        }
        else {
            a = (a * a) % m;
            n >>= 1;
        }
    }
    return res;
}
Hash inv(Hash x) {
    Hash h;
    for (int i = 0; i<K; ++i) h[i] = binpow(x[i], mod[i]-2, mod[i]);
    return h;
}


bool prime(int x) {
    for (int i = 2; i*i<=x; ++i) if (x % i == 0) return 0;
    return 1;
}
void init_modules() {
    for (int i = 0; i<K; ++i) p[i] = (rnd() % inf + inf) % inf;
    for (int i = 0; i<K; ++i)   {
        mod[i] = (rnd() % INF + INF) % INF;
        while (!prime(mod[i])) mod[i]++;
    }
}

void init(int n) {
    init_modules();
    mod[0] = 1e9 + 7;
    p[0] = 998244353;
    for (int i = 1; i<=n; ++i) {
        int tmp = rnd();
        r[i] = mkHash(tmp);
    }
    power.clear();
    power.resize(n+1, mkHash(1));
    for (int i = 1; i<=n; ++i) power[i] = power[i-1] * p;
}


struct hashed{
    int n;
    vector <Hash> h;
    hashed(vector<Hash>& vec) {
        n = vec.size();
        h.resize(n+1);
        for (int i = 1; i<=n; ++i) {
            h[i] = h[i-1] + vec[i-1] * power[i-1];
        }
    };
    hashed() {};
    Hash get_subhash(int l, int r) {
        Hash res = (h[r] - h[l]) * inv(power[l]);
        return res;
    }
    Hash concat(vector <pi> segms) {
        Hash res = mkHash(0);
        int d = 0;
        for (auto segm: segms) {
            res = (res + get_subhash(segm.first, segm.second) * power[d]);
            d += segm.second - segm.first;
        }
        return res;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    init(n);
    vector <vector <Hash>> a(k, vector<Hash>(n, mkHash(0)));
    for (int i = 0; i<k; ++i) {
        for (int j = 0; j<n; ++j) {
            int tmp;
            cin >> tmp;
            a[i][j] = r[tmp];
        }
    }
    vector <hashed> h(k);
    for (int i = 0; i<k; ++i) h[i] = hashed(a[i]);
    vector <set <Hash>> all_hashes(k);
    
    for (int i = 0; i<k; ++i) {
        for (int j = 0; j<n; ++j) {
            vector <pi> segms;
            segms.push_back({1, j+1});
            segms.push_back({0,1});
            segms.push_back({j+1, n});
            Hash cur = h[i].concat(segms);
            all_hashes[i].insert(cur);
        }
    }

    
    set <Hash> intersect = all_hashes[0];
    for (int i = 1; i<k; ++i) {
        set <Hash> intersect2;
        for (auto el: intersect) if (all_hashes[i].count(el)) intersect2.insert(el);
        swap(intersect, intersect2);
    }
    cout << (intersect.size() > 0 ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}