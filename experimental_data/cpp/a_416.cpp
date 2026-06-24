#include <bits/stdc++.h>



#define REP(i, a, b) for(int i = a;i <= b;i++)

#define RIP(i, a, b) for(int i = a;i >= b;i--)

#define X first

#define Y second



using namespace std;



typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

typedef vector<vi> vvi;

typedef vector<vii> vvii;

typedef map<string, int> msi;

typedef map<int, int> mii;

typedef map<string, int> msi;



int l = -1e9-1, r = 1e9 + 2;



int main() {

    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;

    REP(i, 1, n) {

        string com;

        int x;

        char ans;

        cin >> com >> x >> ans;

//        cout << com << ' ' << x << ' ' << ans << endl;

        if(ans == 'N') {

            ans = 'Y';

            if(com == "<") com = ">="; else

            if(com == ">") com = "<="; else

            if(com == "<=") com = ">"; else

            if(com == ">=") com = "<";

        }

        if(com == "<") {r = min(r, x);} else

        if(com == ">") {l = max(l, x + 1);} else

        if(com == "<=") {r = min(r, x + 1);} else

        if(com == ">=") {l = max(l, x);}

//        cout << l << ' ' << r << endl;

    }

    if(r > l) cout << l; else cout << "Impossible";

    return 0;

}