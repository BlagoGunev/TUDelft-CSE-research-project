// █████╗ ██████╗ ██████╗  █████╗ ██╗     ██████╗  █████╗ ██╗  ██╗███╗   ███╗ █████╗ ███╗  ██╗

//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║     ██╔══██╗██╔══██╗██║  ██║████╗ ████║██╔══██╗████╗ ██║

//███████║██████╦╝██║  ██║███████║██║     ██████╔╝███████║███████║██╔████╔██║███████║██╔██╗██║

//██╔══██║██╔══██╗██║  ██║██╔══██║██║     ██╔══██╗██╔══██║██╔══██║██║╚██╔╝██║██╔══██║██║╚████║

//██║  ██║██████╦╝██████╔╝██║  ██║███████╗██║  ██║██║  ██║██║  ██║██║ ╚═╝ ██║██║  ██║██║ ╚███║

//╚═╝  ╚═╝╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚══╝



#include <algorithm>

#include <bitset>

#include <cmath>

#include <cstdint>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <deque>

#include <iomanip>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <unordered_map>

#include <vector>



using namespace std;



#define ll long long

#define ull unsigned long long

#define endl '\n'

#define YES cout << "YES" << endl

#define Yes cout << "Yes" << endl

#define yes cout << "yes" << endl

#define NO cout << "NO" << endl

#define No cout << "No" << endl

#define no cout << "no" << endl

#define clr(arr, x) (memset(arr, x, sizeof arr))

#define all(x) (x.begin(), x.end())

#define allr(x) (x.rbegin(), x.rend())

#define rep(i, n) for (int i = 0; i < n; i++)



typedef vector<int> vi;

typedef pair<int, int> pi;



ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int fact(ll n) {

    if (n <= 1)

        return 1;

    return n * fact(n - 1);

}

int nPr(ll n, ll r) {

    return fact(n) / fact(n - r);

}

ll nCr(ll n, ll r) {

    if (r == 0 || n == r) return 1;

    return nCr(n - 1, r - 1) * n / r;

}



bool valid(int r, int c, int n, int m) {

    return (r <= n && c <= m && r >= 0 && c >= 0);

}



vector<pair<int, int>> Merge_intervals(vector<pair<int, int>> &v) {

    sort(v.begin(), v.end());

    vector<pair<int, int>> res;

    for (auto &i: v) {

        if (res.empty()) {

            res.push_back(i);

        } else {

            int l = i.first;

            int r = i.second;

            int x = res.back().first;

            int y = res.back().second;

            if (l <= y || (l <= x && r >= y)) {

                res.pop_back();

                res.emplace_back(min(l, x), max(r, y));

            } else {

                res.emplace_back(l, r);

            }

        }

    }

    return res;

}



string string_gcd(string str1, string str2) {

    if (str1 + str2 == str2 + str1) {

        return str1.substr(0, gcd(str1.size(), str2.size()));

    } else {

        return "";

    }

}

void file() {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

}

void Abdalrahman() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

}



void solve() {

    int t; cin >> t;



    while(t--){

        int n; cin >> n;

        int temp =2;

        bool a = 0, b = 1;

        int x = 1, y = 0;

        n--;

        while(n){

            if(b){

                y += temp;

                n-=temp;

                if(n < 0){

                    y += n;

                    break;

                }

                temp++;

                y += temp;

                n-=temp;

                temp++;

                if(n < 0){

                    y += n;

                    break;

                }

                b = 0;

            }

            else{

                x += temp;

                n-=temp;

                temp++;

                if(n < 0){

                    x += n;

                    break;

                }

                x+=temp;

                n-=temp;

                temp++;

                if(n < 0){

                    x += n;

                    break;

                }

                b = 1;

            }

        }



        cout << x << ' ' << y << endl;



    }

}



int main() {

    Abdalrahman();

    file();

    solve();



    return 0;

}