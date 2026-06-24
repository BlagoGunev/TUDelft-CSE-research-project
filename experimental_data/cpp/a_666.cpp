#include <bits/stdc++.h>



#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)

#define FORD(i,b,e) for(int i=(b); i >= (e); --i)

#define SIZE(c) (int) (c).size()

#define FORE(i,c) FOR(i,0,SIZE(c)-1)

#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second



using namespace std;



typedef long long int LLI;

typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;



typedef vector < int > VI;

typedef vector < bool > VB;

typedef vector < PII > VP;

typedef vector < LLI > VL;
typedef vector < PLL > VPL;



typedef vector < VI > VVI;

typedef vector < VL > VVL;

typedef vector < VB > VVB;
typedef vector < VP > VVP;



const int MOD = 1000000007;

const int INF = 1000000001;
const LLI LLINF = 1000000000000000001LL;


/*************************************************************************/



int main() {

    ios_base::sync_with_stdio(0);



    string s;
    cin >> s;

    int n = SIZE(s);

    bool dp[2][n+1];
    FOR(i,0,1) FOR(j,0,n) {
        dp[i][j] = (j == n || j == n-2-i);
    }

    FORD(j,n-1,0) FOR(i,0,1) if (j <= n-3-i) {
        int k = j + 1 + i;

        dp[i][j] |= dp[1-i][k+1];
        dp[i][j] |= (dp[i][k+1] && s.substr(j,2+i) != s.substr(j+2+i,2+i));
    }

    set <string> suff;

    FOR(i,0,1) FOR(j,5,n-1) {
        if (dp[i][j]) {
            suff.insert(s.substr(j, 2+i));
        }
    }


    cout << SIZE(suff) << '\n';

    for (const string &t : suff) {
        cout << t << '\n';
    }


    return 0;

}



/*************************************************************************/