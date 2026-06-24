#include <bits/stdc++.h>



#define  Ahmed_esam     ios::sync_with_stdio(0); cin.tie(0);   cout.tie(0);

using namespace std;

#define int long long int

#define pb push_back

#define no "NO\n"

#define yes "YES\n"

int inf = 1000000007;

#define Endl endl

#define all(v) v.begin(),v.end()



template<class T, class M>

ostream &operator<<(ostream &os, const pair<T, M> &pa);



template<class T>

istream &operator>>(istream &is, vector<T> &v);



template<class T>

ostream &operator<<(ostream &os, vector<T> &v);



template<class T>

bool operator==(vector<T> a, vector<T> b);



void bfs(int l, int r, int x, int a, int b) {

    queue<pair<int, int>> q;

    map<int, bool> visited;

    visited[a] = true;

    int ans = -1;

    q.push({a, 0});

    while (q.size()) {

        int a_n = q.front().first;

        int steps = q.front().second;

        q.pop();

        if (a_n == b) {

            ans = steps;

            break;

        }



        if (!visited[-a_n + x] and -a_n + x >= l and -a_n + x <= r) {

            q.push({-a_n + x, steps + 1});

            visited[-a_n + x] = true;

        }

        if (!visited[a_n + x + 1] and a_n + x + 1 >= l and a_n + x + 1 <= r) {

            q.push({a_n + x + 1, steps + 1});

            visited[a_n + x + 1] = true;

        }

        if (!visited[a_n + x] and a_n + x >= l and a_n + x <= r) {

            q.push({a_n + x, steps + 1});

            visited[a_n + x] = true;

        }

        if (!visited[-a_n + x - 1] and -a_n + x - 1 >= l and -a_n + x - 1 <= r) {

            q.push({-a_n + x - 1, steps + 1});

            visited[-a_n + x - 1] = true;

        }





    }

    cout << ans << endl;



}



int check(vector<int> &v) {

    int n = v.size();

    int num_zeros = 0;

    for (int i = 0; i < n; ++i) {

        num_zeros += (0 == v[i]);

    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {

        if (v[i] == 0)

            num_zeros--;

        else {

            ans += num_zeros;

        }

    }

    return ans;



}



void solve() {

    int n;

    cin >> n;

    vector<int> v(n);

    cin >> v;

    vector<int> tmp_1 = v, tmp_2 = v;

    for (int i = 0; i < n; ++i) {

        if (tmp_1[i] == 0) {

            tmp_1[i] = 1;

            break;

        }

    }

    for (int i = n - 1; i >= 0; --i) {

        if (tmp_2[i] == 1) {

            tmp_2[i] = 0;

            break;

        }

    }

    cout << max({check(v), check(tmp_1), check(tmp_2)}) << endl;



}





int32_t main() {



    Ahmed_esam

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif





    int q = 1;

    cin >> q;

    while (q--) {

        solve();

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;





}





int power_mod(int b, int p) {

    if (p == 0)

        return 1;

    if (p == 1)

        return b % inf;

    int ret = power_mod(b % inf, p / 2) % inf;

    ret = (ret * ret) % inf;

    if (p % 2 == 1) {

        ret = (ret * (b % inf)) % inf;

    }

    return ret;

}



template<class T, class M>

ostream &operator<<(ostream &os, const pair<T, M> &pa) {

    os << pa.first << " " << pa.second << endl;

    return os;



}



template<class T>

istream &operator>>(istream &is, vector<T> &v) {

    for (int i = 0; i < v.size(); i++) {

        is >> v[i];

    }

    return is;



}



template<class T>

ostream &operator<<(ostream &os, vector<T> &v) {

    for (int i = 0; i < v.size(); i++) {

        os << v[i] << " ";

    }

    os << endl;

    return os;



}





template<class T>

bool operator==(vector<T> a, vector<T> b) {

    for (int i = 0; i < a.size(); i++) {

        if (a[i] == b[i]) {

            continue;

        } else return false;

    }

    return true;

}