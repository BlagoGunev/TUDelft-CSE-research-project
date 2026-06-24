#include <bits/stdc++.h>

#define base 1000000007LL

#define ll long long

#define X first

#define Y second

#define mp make_pair

#define pb push_back

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)

#define FORE(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)



using namespace std;



typedef pair<int, int> II;

typedef vector<II> vi;



int n, x, y;



int loai(int y)

{

    if (y < n) return 1;

    int k = y / n;

    if (k % 2) return 1;

    return 2;

}



int num(int y)

{

    if (y < n) return 1;

    int k = y / n;

    if (k % 2) return 3*(k/2)+2;

    return 3*(k/2);

}



int main()

{

    ios::sync_with_stdio(0);

    //freopen("inp.txt", "r", stdin);

    cin >> n >> x >> y;

    if (y % n == 0) cout << -1;

    else {

        int p = loai(y);

        int cuc = num(y);

        if (p == 1) {

            if (abs(x) < n/2 + n%2) cout << cuc;

            else cout << -1;

        }

        else {

            if (x > 0 && x < n) cout << cuc+1;

            else if (x < 0 && x > -n) cout << cuc;

            else cout << -1;

        }

    }

    return 0;

}