#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

template<class T, class U>
ostream& operator<<(ostream &o, pair<T, U> x) {
  return o << "(" << x.first << ", " << x.second << ")";
}
template<class> struct is_container : false_type {};
template<class... Ts> struct is_container<vector<Ts...>> : true_type {};
template<class... Ts> struct is_container<map<Ts...>> : true_type {};
template<class... Ts> struct is_container<unordered_map<Ts...>> : true_type {};
template<class... Ts> struct is_container<set<Ts...>> : true_type {};
template<class... Ts> struct is_container<unordered_set<Ts...>> : true_type {};
template<class... Ts> struct is_container<multiset<Ts...>> : true_type {};
template<class... Ts> struct is_container<unordered_multiset<Ts...>> : true_type {};
template<class T, class = typename enable_if<is_container<T>::value>::type>
ostream& operator<<(ostream &o, T x) {
  int f = 1;
  o << "{";
  for (auto y : x) {
    o << (f ? "" : ", ") << y;
    f = 0;
  }
  return o << "}";
}

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vi> a(n, vi(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        auto sol = a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vi b;
                if (i > 0) b.push_back(a[i - 1][j]);
                if (i < n - 1) b.push_back(a[i + 1][j]);
                if (j > 0) b.push_back(a[i][j - 1]);
                if (j < m - 1) b.push_back(a[i][j + 1]);
                sort(all(b));
                sol[i][j] = min(a[i][j], b.back());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << sol[i][j] << " \n"[j == m - 1];
            }
        }
    }

    return 0;
}