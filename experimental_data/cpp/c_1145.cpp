#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

 
#define eb emplace_back
#define pb push_back
#define ld long double 
#define int long long
#define f first
#define s second
#define fast() ios_base::sync_with_stdio(0); cin.tie(0)


using namespace std;

const
    int INF = 1e18 + 7;


signed main() {
    #ifdef _LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fast();
    int n;
    cin >> n;
    if (n == 3)
    	cout << 13;
    else if (n == 0)
    	cout << 15;
    else if (n == 1)
    	cout << 14;
    else if (n == 2)
    	cout << 12;
    else if (n == 4)
    	cout << 8;
    else if (n == 5)
    	cout << 9;
    else if (n == 6)
    	cout << 10;
    else if (n == 7)
    	cout << 11;
    else if (n == 8)
    	cout << 0;
    else if (n == 9)
    	cout << 1;
    else if (n == 10)
    	cout << 2;
    else if (n == 11)
    	cout << 3;
    else if (n == 12)
    	cout << 4;
    else if (n == 13)
    	cout << 5;
    else if (n == 14)
    	cout << 6;
    else 
    	cout << 7;
    return 0;
}