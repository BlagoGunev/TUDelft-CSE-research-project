#include <bits/stdc++.h>



using namespace std;



using ll = long long;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

using vi = vector<int>;

using vb = vector<bool>;

using vll = vector<ll>;

using vs = vector<string>;

#define ALL(v) v.begin(), v.end()

#define SORT(v) sort(ALL(v))

#define SZ(v) int(v.size())



#ifdef DLOCAL

#include <local.h>

#else

#define deb(...);

#endif



void solve() {

    int n; cin >> n;

    map<char, int> a, b;

    map<char, queue<int>> ai, bi;

    

    string l, r; cin >> l >> r;

    for (int i = 0; i < n; ++i) {

        if (l[i] == '?') l[i] = '{';

        if (r[i] == '?') r[i] = '{';

        a[l[i]]++;

        b[r[i]]++;

        ai[l[i]].push(i + 1);

        bi[r[i]].push(i + 1);

    }



    vector<pii> answer;

    for (auto it = a.begin(); it != a.end(); ++it) {

        if (it->first == '{') {

            for (auto it2 = b.begin(); it2 != b.end(); ++it2) {

                if (it2->second == 0) continue;

                int total = min(it2->second, it->second);

                it->second -= total;

                it2->second -= total;



                for (int i = 0; i < total; ++i) {

                    answer.emplace_back(make_pair(ai[it->first].front(), bi[it2->first].front()));

                    ai[it->first].pop();

                    bi[it2->first].pop();

                }

            }

        }

        else {

            auto  it2 = b.find(it->first);

            if (it2->second != 0) {

                int total = min(it2->second, it->second);

                it->second -= total;

                it2->second -= total;

                for (int i = 0; i < total; ++i) {

                    answer.emplace_back(make_pair(ai[it->first].front(), bi[it2->first].front()));

                    ai[it->first].pop();

                    bi[it2->first].pop();

                }

            }

            if (it->second == 0) continue;

            it2 = b.find('{');

            if (it2 != b.end() && it2->second != 0)

            {

                int total = min(it2->second, it->second);

                it->second -= total;

                it2->second -= total;

                for (int i = 0; i < total; ++i) {

                    answer.emplace_back(make_pair(ai[it->first].front(), bi[it2->first].front()));

                    ai[it->first].pop();

                    bi[it2->first].pop();

                }

            }

        }

    }

    cout << SZ(answer) << "\n";

    for (int i = 0; i < SZ(answer); ++i) {

        cout << answer[i].first << " " << answer[i].second << "\n";

    }

}



int main() {

    ios::sync_with_stdio(0); cin.tie(0);



    //ifstream cin ("puzzle_name.in");

    //ofstream cout ("puzzle_name.out");



    solve();



    return 0;

}