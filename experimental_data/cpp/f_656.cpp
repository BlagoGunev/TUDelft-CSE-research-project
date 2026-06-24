/*

   _____                                ________         .__            __               

  /  _  \_______  ______ ____   ____    \_____  \ _______|  |__   _____/  |_  _______  __

 /  /_\  \_  __ \/  ___// __ \ /    \    /   |   \\___   /  |  \_/ __ \   __\/  _ \  \/ /

/    |    \  | \/\___ \\  ___/|   |  \  /    |    \/    /|   Y  \  ___/|  | (  <_> )   / 

\____|__  /__|  /____  >\___  >___|  /  \_______  /_____ \___|  /\___  >__|  \____/ \_/  

        \/           \/     \/     \/           \/      \/    \/     \/                  

*/

#include <cstring>

#include <list>

#include <climits>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iomanip>

#include <iostream>

#include <fstream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <algorithm>

#include <vector>

#include <string>

#include <map>

#include <set>

#include <queue>

#include <stack>

#include <deque>

#include <bitset>

#include <cassert>

#include <cctype>

#include <stdexcept>



/*

SU!*J4Ax

*/



#define sqr(x) (x * x)

#define cub(x) sqr(x) * (x)

#define endl "\n"

#define all(x) x.begin() , x.end()

#define fp pop_front

#define bp pop_back

#define pf push_front

#define pb push_back

#define mp make_pair

#define sz size()                                                           

#define se second             

#define fi first

#define _ std::ios_base::sync_with_stdio(false); std::cin.tie(0);



using namespace std;



typedef long long ll;

typedef double dd;

typedef string st;

typedef char ch;

typedef unsigned long long ull;

typedef bool bl;

typedef long double ld;

typedef int I;



const ld pi = 3.14159265358979323846;

const ll mod = 1e9 + 7;

const ll N = 3e3;



st s;

ll res;



int main() { _

	cin >> s;

	for(ll i = 1; i < (ll)s.sz; ++i) {

		res += (ll)(s[i] - '0');

		if(s[i] == '0') res += 9;

   	} 

   	cout << res + 1;

    return 0;

}