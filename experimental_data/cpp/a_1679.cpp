// If you copy and paste my solution I will murder you in your sleep.



#include <iostream>

#include <vector>

#include <set>

#include <map>

#include <cmath>

#include <stack>

#include <queue>

#include <algorithm>

#include <iomanip>

#include <cassert>

#include <unordered_set>



#define int long long



using namespace std;





signed solve() {



    int n;

    cin >> n;

    if (n % 2 == 1 or n<4){

        cout << -1 << endl;

        return 0;

    }

    int a, b;

    a = (n / 4);

    b = (n / 6);

    if (n % 6 == 4) b++;

    else if (n % 6 == 2) b++;

    cout << b << ' ' << a << endl;

    return 0;

}





signed main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    int test = 1;

    cin >> test;

    while (test--) {

        solve();

    }

    return 0;

}