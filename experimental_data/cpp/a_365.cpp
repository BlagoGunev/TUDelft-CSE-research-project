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

    int n , k ;

    cin >> n >> k ;

    int x;

    int z =0 ;

    for (int i = 0 ; i < n ; i++)

    {

        cin >> x ;

        set<int>a;

        while(x)

        {

            if (x%10<=k)

            {

                a.insert(x%10);

                

            }

            x/=10;

        }

        if (k+1==a.size())z++;

    }

    cout << z << "\n";

    return 0;

}