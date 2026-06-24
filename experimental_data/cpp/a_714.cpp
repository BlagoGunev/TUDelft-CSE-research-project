#include <iostream>

#include <stdio.h>

#include <string>

#include <cmath>

#include <iomanip>

#include <vector>

#include<algorithm>

#include <string>

#include<queue>

#include <deque>

#include <set>

#include<stack>

#include <bitset>

#include <numeric>

#include<map>

#define all(v)          ((v).begin()), ((v).end())

#define sz(v)           ((int)((v).size()))

#include <fstream>

using namespace std;

typedef vector<int> vi;

typedef vector<vi > vii;

int  __builtin_popcount(unsigned int) ;





int main()

{

    long long l , r , l1 , r1 , k ;

    cin >> l >> r >> l1 >> r1 >> k ;

    long long z =0;

    l1 = max(l,l1);

    r1 = min(r,r1);

    z= r1 - l1 ;

    z++;

    if (k>=l1&&k<=r1)z--;

    if (z<0)z=0;

    

    cout << z << endl;

    return 0;

}