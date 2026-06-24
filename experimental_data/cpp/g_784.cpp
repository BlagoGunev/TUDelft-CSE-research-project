//
//  main.cpp
//  test
//
//  Created by Максим Бачурин on 04.02.17.
//  Copyright © 2017 Максим Бачурин. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1e9 + 7;
//const double eps = 1e-9;
const int inf = 1e9;
//const double PI = 3.1415926535897932384626433832795;

int subint(string s)
{
    int ans = 0;
    for(auto x : s)
    {
        ans += x - '0';
        ans *= 10;
    }
    return ans/10;
}

int main()
{
    //freopen("output.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    string s, sub;
    int res = 0;
    cin >> s;
    bool plus = true;
    for(int i = 0; i < s.size(); i++)
    {
        //cout << 1 << endl;
        while(i < s.size() && (s[i]!= '+' && s[i]!= '-'))
        {
            sub += s[i];
            i++;
        }
        
        //cout << sub << endl;
        if(plus)
            res += subint(sub);
        else
            res -= subint(sub);
        sub = "";
        if(s[i] == '+')
        {
            plus = true;
        }
        if(s[i] == '-')
        {
            plus = false;
        }
    }
    cout << res << endl;
    if(res>=100)
    {
        for(int i = 0; i < res/100 + 48; i++)
        {
            cout << "+";
        }
        cout << ".>";
        for(int i = 0; i < (res/10)%10 + 48; i++)
        {
            cout << "+";
        }
        cout << ".>";
        for(int i = 0; i < (res)%10 + 48; i++)
        {
            cout << "+";
        }
        //cout << ">";
    }
    else
    {
        if(res >= 10)
        {
            for(int i = 0; i < res/10 + 48; i++)
            {
                cout << "+";
            }
            cout << ".>";
            for(int i = 0; i < (res)%10 + 48; i++)
            {
                cout << "+";
            }
            //cout << ">";
        }
        else
        {
            for(int i = 0; i < (res)%10 + 48; i++)
            {
                cout << "+";
            }
            //cout << ">";
        }
    }
    cout << '.' << endl;
    return 0;
}