#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>

#define prev asdajsdb
#define rank alsdasda

typedef long long ll;
typedef double dbl;

using namespace std;

template<class T>
void print(vector<T> s){
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
}

template<class T>
void print(vector<pair<T, T> > s){
    for (int i = 0; i < s.size(); i++)
        cout << s[i].first << " " << s[i].second << endl;
    cout << endl;
}

const ll MOD = 1e9 + 7;
const int INF = 1e9;

int main()
{
    //*freopen("test.in", "r", stdin);/**/
    /*freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);/**/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> s >> m;
    s += '*';
    if (m > n){
        cout << 0 << endl;
        return 0;
    }
    if (m == 1){
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '?')
                cnt++;
        cout << cnt << endl;
        return 0;
    }
    vector<int> q1, q2;
    int cur1 = 0, cur2 = 0;
    char c = 'a';
    for (int i = 0; i < m; i++){
        if (s[i] == c){
            if (i % 2 == 0)
                q2.push_back(i);
            else
                q1.push_back(i);
        }
    }
    vector<int> can(n, 1);
    for (int i = 0; i < m - 1; i++)
        can[i] = 0;
    vector<int> cnt(n, 0);
    for (int i = m - 1; i < n; i++){
        if ((i - m + 1) % 2 == 0 && q1.size() != cur1)
            can[i] = 0;
        if ((i - m + 1) % 2 == 1 && q2.size() != cur2)
            can[i] = 0;
        cnt[i] += q1.size() - cur1 + q2.size() - cur2;
        if (q1.size() > cur1 && q1[cur1] == i - m + 1)
            cur1++;
        if (q2.size() > cur2 && q2[cur2] == i - m + 1)
            cur2++;
        if (s[i + 1] == c){
            if (i % 2 == 1)
                q2.push_back(i + 1);
            else
                q1.push_back(i + 1);
        }
    }

    q1.clear();
    q2.clear();
    cur1 = 0;
    cur2 = 0;
    c = 'b';
    for (int i = 0; i < m; i++){
        if (s[i] == c){
            if (i % 2 == 0)
                q2.push_back(i);
            else
                q1.push_back(i);
        }
    }
    for (int i = m - 1; i < n; i++){
        if ((i - m + 1) % 2 == 0 && q2.size() != cur2)
            can[i] = 0;
        if ((i - m + 1) % 2 == 1 && q1.size() != cur1)
            can[i] = 0;
        cnt[i] += q1.size() - cur1 + q2.size() - cur2;
        if (q1.size() > cur1 && q1[cur1] == i - m + 1)
            cur1++;
        if (q2.size() > cur2 && q2[cur2] == i - m + 1)
            cur2++;
        if (s[i + 1] == c){
            if (i % 2 == 1)
                q2.push_back(i + 1);
            else
                q1.push_back(i + 1);
        }
    }


    for (int i = 0; i < n; i++){
        if (can[i] == 0)
            cnt[i] = 0;
        else
            cnt[i] = m - cnt[i];
    }
    vector<int> dp1(n, 0);
    vector<int> dp2(n, INF);
    for (int i = 0; i < m - 1; i++)
        dp2[i] = 0;
    int maxi1 = 0, maxi2 = 0;
    for (int i = m - 1; i < n; i++){
        dp1[i] = dp1[i - 1];
        dp2[i] = dp2[i - 1];
        if (can[i] == 1){
            if (maxi1 + 1 > dp1[i] || (maxi1 + 1 == dp1[i] && maxi2 + cnt[i] < dp2[i])){
                dp1[i] = maxi1 + 1;
                dp2[i] = maxi2 + cnt[i];
            }
        }
        maxi1 = dp1[i - m + 1];
        maxi2 = dp2[i - m + 1];
    }
    cout << dp2[n - 1] << endl;
    return 0;
}