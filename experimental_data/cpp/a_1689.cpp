#include <iostream>

#include <algorithm>

#include <cstring>

#include <cstdio>

#include <vector>

#include <cmath>

#include <map>

#include <set>

#include <stack>

#include <queue>

#include <numeric>

#include <sstream>

#include <unordered_map>

#define ll long long

#define ull unsigned long long

#define re return

#define pb push_back

#define Endl "\n"

#define endl "\n"

#define x first

#define y second

#define all(x) (x).begin(),(x).end()



using namespace std;



using PII = pair<int, int>;



const int N = 1e5 + 10;

const int M = 1e5 + 10;

const int mod = 1000000007;

const int INF = 0x3f3f3f3f;



int dx[4] = {-1,0,1,0};

int dy[4] = {0,1,0,-1};



int T;

int n, m, k;

string a, b;



void solve(){

    cin >> n >> m >> k;

    cin >> a >> b;

    sort(all(a));

    sort(all(b));



    int i = 0;

    int j = 0;

    int cnta = 0;

    int cntb = 0;

    string ans;

    while(i < a.size() && j < b.size()){

        if((cntb >= k) || (cnta < k && a[i] < b[j])){

            ans += a[i];

            i++;

            cnta++;

            cntb = 0;

        }

        else if((cnta >= k) || (cntb < k && b[j] < a[i])){

            ans += b[j];

            j++;

            cntb++;

            cnta = 0;

        }

    }

    cout << ans << endl;

}



int main(){

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    T = 1;

    cin >> T;

    while(T--){

        solve();

    }

}