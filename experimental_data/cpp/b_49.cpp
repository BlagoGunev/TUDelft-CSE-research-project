#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <vector>

#include <map>

#include <queue>

#include <string>

#include <algorithm>

#include <set>



#define ll long long

#define F first

#define S second                                                       

#define pb push_back

#define mp make_pair

#define INF (int)(1e9 + 7)

#define EPS 1e-6

                                                                       

using namespace std;



const ll N = (ll)1e5 + 7;

string s1, s2;

char c1 = '0', c2 = '0';

int k;

int to_dec(string s, int k)

{

    int res = 0, pw = 1;

    for(int i = (int)s.length() - 1; i >= 0; i--)

    {

        res += (s[i] - '0') * pw;

        pw *= k;

    }

    return res;

}



int main()

{

    cin >> s1 >> s2;

    for(int i = 0; i < (int)s1.size(); i++)

        c1 = max(c1, s1[i]);

    for(int i = 0; i < (int)s2.size(); i++)

        c2 = max(c2, s2[i]);

    c1 = max(c1, c2);

    if(c1 == '9')

        k = 10;

    else

        k = c1 - '0' + 1;

    //cout << k << endl;

    int per = to_dec(s1, k), vtor = to_dec(s2, k);

    int ans = 0, sum = per + vtor;

    while(sum)

    {

        ans++;

        sum /= k;    

    }

    cout << ans << endl;   

    

    return 0;

}