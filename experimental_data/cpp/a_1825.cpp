#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
#include<time.h>
#include <sys/types.h>


typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;

int main()
{

    int D;
    D = 1;
    cin >> D;



    while (D--) {
        string p;
        cin >> p;
        set<char>s;
        for (int i = 0; i < p.size(); i++)s.insert(p[i]);

        if (s.size() == 1)cout << -1 << endl;
        else cout << p.size() - 1 << endl;

        
    }
    return 0; 
}