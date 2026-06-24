#include <iostream>

#include <fstream>

#include <map>

#include <cmath>

#include <math.h>

#include <set>

#include <vector>

#include <sstream>

#include <string>

#include <cstring>

#include <cstdio>

#include <algorithm>

#include <cstring>

#include <queue>

#include <cstdlib>

#include <iomanip>

#include <bitset>

#include <unordered_map>



typedef long long int lli;

typedef long double ld;



const lli INF = 9999999999999999, MOD = 1e9 + 7, MAXN = 10000; //18

const ld EPS = 0.0000001;

#define forn(a, b) for (lli i = a; i < b; i++)

#define fore(p, a, b) for (lli p = a; p < b; p++)

#define all(a) a.begin(), a.end()

#define rall(a) a.rbegin(), a.rend()

#define pb(a) push_back(a)

#define mp(a, b) make_pair(a, b)

#define fo first

#define so second

#define cotu cout



using namespace std;



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++){

        if (s[i] == 'r') cout << i + 1 << "\n";

    }

    

    for (int i = s.size() - 1; i >= 0; i--){

        if (s[i] == 'l') cout << i + 1 << "\n";

    }

    return 0;

}