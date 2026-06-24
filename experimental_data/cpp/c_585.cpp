#include <string>

#include <vector>

#include <map>

#include <list>

#include <iterator>

#include <set>

#include <queue>

#include <iostream>

#include <sstream>

#include <stack>

#include <deque>

#include <cmath>

#include <memory.h>

#include <cstdlib>

#include <cstdio>

#include <cctype>

#include <algorithm>

#include <utility>

#include <cassert>

#include <complex>

#include <time.h>

using namespace std;



#define FOR(i, a, b) for(int i=(a);i<(b);i++)

#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)

#define FILL(A,value) memset(A,value,sizeof(A))



#define ALL(V) V.begin(), V.end()

#define SZ(V) (int)V.size()

#define PB push_back

#define MP make_pair

#define LL long long

#define Pi 3.14159265358979

#define x0 ikjnrmthklmnt

#define y0 lkrjhkltr

#define y1 ewrgrg



typedef long long Int;

typedef unsigned long long UInt;

typedef vector<int> VI;

typedef pair<int, int> PII;

typedef complex<double> base;



const int INF = 10;

const int MAX = 200047;

const int MAXD = 100047;



Int a, b;

string s = "";



Int nsd(Int a, Int b)

{

    if (!a || !b)

        return a+b;

    return nsd(b%a, a);

}



void nsdq(Int a, Int b)

{

    if (!a || !b) return;

    Int k1=0,k2=0,t;

    string ss ="";

    if (a>b)

    {

        k1 = a/b;

        ss += 'A';

        t = k1;

        if (b*k1 == a) t--;

    }

    else

    {

        k2 = b/a;

        ss += 'B';

        t = k2;

        if (b == a*k2) t--;

    }

    while (t)

    {

        ss += char('0' + t%10);

        t/=10;

    }

    reverse(ss.begin(), ss.end());

    s += ss;

    nsdq(a-k1*b, b-k2*a);

}



int main()

{

    cin >> a >> b;

    if (nsd(a,b) != 1)

    {

        cout << "Impossible\n";

        return 0;

    }

    nsdq(a,b);

    cout << s;

    return 0;

}