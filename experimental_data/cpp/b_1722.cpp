#include <algorithm>

#include <iostream>

#include <iomanip>

#include <numeric>

#include <utility>

#include <math.h>

#include <string>

#include <map>

#include <set>

#define ll long long

#define ld long double

#define lli long long int

#define rep(i, a, b) for(int i = a; i < b; i++)

#define per(i, a, b) for(int i = a; i > b; i--)

#define testCaseLL ll testCase; cin >> testCase; while(testCase--)

#define testCaseI int testCase; cin >> testCase; while(testCase--)

using namespace std;



void fast(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

}



void solve(){

    int n;

    string a, b;

    testCaseI{

        int n;

        cin >> n >> a >> b;

        replace(begin(a),end(a),'G','B');

        replace(begin(b),end(b),'G','B');

        if(a == b)cout << "YES" << endl;

        else cout << "NO" << endl;

    }

}



int main()

{

    fast(); solve();

    return 0;

}