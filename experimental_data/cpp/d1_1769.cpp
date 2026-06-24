/*
    author:  Maksim1744
    created: 03.12.2022 12:30:06
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

array<array<array<array<array<array<array<array<array<char, 2>, 6>, 5>, 6>, 5>, 6>, 5>, 6>, 5> dp{};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string suits = "CDSH";
    string vals = "6789TJQKA";

    array<bool, 36> hasa{};
    array<bool, 36> hasb{};

    for (int i = 0; i < 18; ++i) {
        string s;
        cin >> s;
        hasa[(find(suits.begin(), suits.end(), s[1]) - suits.begin()) * 9 + (find(vals.begin(), vals.end(), s[0]) - vals.begin())] = 1;
    }
    for (int i = 0; i < 18; ++i) {
        string s;
        cin >> s;
        hasb[(find(suits.begin(), suits.end(), s[1]) - suits.begin()) * 9 + (find(vals.begin(), vals.end(), s[0]) - vals.begin())] = 1;
    }

    for (int l1 = 0; l1 <= 4; ++l1) {
        for (int r1 = 5; r1 >= 0; --r1) {
            for (int l2 = 0; l2 <= 4; ++l2) {
                for (int r2 = 5; r2 >= 0; --r2) {
                    for (int l3 = 0; l3 <= 4; ++l3) {
                        for (int r3 = 5; r3 >= 0; --r3) {
                            for (int l4 = 0; l4 <= 4; ++l4) {
                                for (int r4 = 5; r4 >= 0; --r4) {
                                    array<char, 2> has_move{};
                                    for (int who = 0; who < 2; ++who) {
                                        auto& has = (who == 0 ? hasa : hasb);
                                        int taken = 0;
                                        for (int i = l1; i <= r1 + 3; ++i)
                                            taken += has[0 * 9 + i];
                                        for (int i = l2; i <= r2 + 3; ++i)
                                            taken += has[1 * 9 + i];
                                        for (int i = l3; i <= r3 + 3; ++i)
                                            taken += has[2 * 9 + i];
                                        for (int i = l4; i <= r4 + 3; ++i)
                                            taken += has[3 * 9 + i];

                                        auto& cur = dp[l1][r1][l2][r2][l3][r3][l4][r4][who];

                                        if (who == 0) cur = -1;
                                        else cur = 1;

                                        auto upd_with = [&](char val) {
                                            has_move[who] = 1;
                                            if (taken == 17) cur = (who == 0 ? 1 : -1);
                                            if (who == 0) cur = max(cur, val);
                                            else cur = min(cur, val);
                                        };

                                        if (l1 != 0 && has[0 * 9 + l1 - 1]) upd_with(dp[l1 - 1][r1][l2][r2][l3][r3][l4][r4][who ^ 1]);
                                        if (l2 != 0 && has[1 * 9 + l2 - 1]) upd_with(dp[l1][r1][l2 - 1][r2][l3][r3][l4][r4][who ^ 1]);
                                        if (l3 != 0 && has[2 * 9 + l3 - 1]) upd_with(dp[l1][r1][l2][r2][l3 - 1][r3][l4][r4][who ^ 1]);
                                        if (l4 != 0 && has[3 * 9 + l4 - 1]) upd_with(dp[l1][r1][l2][r2][l3][r3][l4 - 1][r4][who ^ 1]);

                                        if (l1 != 4 && r1 != 5 && has[0 * 9 + r1 + 3 + 1]) upd_with(dp[l1][r1 + 1][l2][r2][l3][r3][l4][r4][who ^ 1]);
                                        if (l2 != 4 && r2 != 5 && has[1 * 9 + r2 + 3 + 1]) upd_with(dp[l1][r1][l2][r2 + 1][l3][r3][l4][r4][who ^ 1]);
                                        if (l3 != 4 && r3 != 5 && has[2 * 9 + r3 + 3 + 1]) upd_with(dp[l1][r1][l2][r2][l3][r3 + 1][l4][r4][who ^ 1]);
                                        if (l4 != 4 && r4 != 5 && has[3 * 9 + r4 + 3 + 1]) upd_with(dp[l1][r1][l2][r2][l3][r3][l4][r4 + 1][who ^ 1]);
                                    }
                                    auto& a = dp[l1][r1][l2][r2][l3][r3][l4][r4][0];
                                    auto& b = dp[l1][r1][l2][r2][l3][r3][l4][r4][1];
                                    if (!has_move[0]) a = b;
                                    if (!has_move[1]) b = a;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int res = dp[4][0][4][0][4][0][4][0][0];

    assert(res != 0);

    if (res == -1)
        cout << "Bob\n";
    else
        cout << "Alice\n";

    return 0;
}