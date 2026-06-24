#include <bits/stdc++.h>

using namespace std;

#if 1
    #define pv(x) cout<<#x<<" = "<<x<<"; ";cout.flush()
    #define pn cout<<endl
#else
    #define pv(x)
    #define pn
#endif

#ifdef ONLINE_JUDGE
    #define in cin
    #define out cout
#else
    ifstream in("date.in");
    ofstream out("date.out");
#endif

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define pb push_back
#define mp make_pair
const int NMax = 2e3 + 5;
const ll inf_ll = 1e18 + 5;
const int inf_int = 1e9 + 5;
const int mod = 100003;
using zint = int;

// there's no solution if the two strings have different letters;
// otherwise, move each letter of t (from the right to the left) to the beginning of s;

int N;
int freq[300];
char s[NMax],t[NMax];
vector< int > sol;

// do a shift of length x on s;
void shift(int x) {
    sol.pb(x);
    
    char aux[NMax] = {};
    reverse(s + N - x + 1, s + N + 1);
    strcpy(aux + 1, s + N - x + 1);
    strncat(aux + 1, s + 1, N - x);
    
    strcpy(s + 1, aux + 1);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> (s+1) >> (t+1);
    
    // check if the two strings have the same letters;
    for (int i = 1;i <= N;++i) {
        ++freq[ s[i] ];
    }
    for (int i = 1;i <= N;++i) {
        if (!freq[ t[i] ]) {
            out << -1;
            return 0;
        }
        
        --freq[ t[i] ];
    }
    
    for (int i = N;i > 1;--i) { // get each character of t from right to left
        char ch = t[i];
        
        int st = N - i + 1, idx = st;
        while (s[idx] != ch) { // find the character among unused letters of s;
            ++idx;
        }
        
        // move it to the start of s;
        shift(N);
        idx = N - idx + 1;
        if (idx < N) {
            shift(N - idx);
        }
        shift(1);
    }
    shift(1); // move the last letter;
    
    out << sol.size() << '\n';
    for (int x : sol) {
        out << x << ' ';
    }

    return 0;
}