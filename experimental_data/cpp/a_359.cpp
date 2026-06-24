#include <bits/stdc++.h>

#define ll long long

#define ld long double

#define ull unsigned ll

#define F first

#define S second

#define mp make_pair

#define pb push_back



using namespace std;



const int MIN = 1e3 + 2;

const int MXN = 1e5 + 3;

const int INF = 1e9 + 7;

const ll LINF = 1e18 + 15;

const double EPS = 1e-9;



int a[51][51], n, m;



int main(){

    cin >> n >> m;

    for (int i = 1; i <= n; i++){

        for (int j = 1; j <= m; j++){

            cin >> a[i][j];

            if ((i == 1 || j == 1 || i == n || j == m) && a[i][j] == 1){

                cout << 2;

                return 0;

            }

        }

    }

    cout << 4;

	return 0;

}