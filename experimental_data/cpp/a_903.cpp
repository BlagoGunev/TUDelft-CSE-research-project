#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#define IN freopen("f:\\in.txt", "rt", stdin);
#define OUT freopen("f:\\out.txt", "wt", stdout);
#define FOR(n) for(int i = 0; i < n; i++)
#define ll long long int
#define STESTCASE int t;scanf("%d", &t);getchar();for(int tc = 1; tc <= t; tc++)
#define TESTCASE int t;scanf("%d", &t);for(int tc = 1; tc <= t; tc++)
#define PF printf
#define SF scanf
#define EP 0.000000001
#define MAX 10000009
using namespace std;

int main()
{
    TESTCASE
    {
        int n;
        cin >> n;
        if(n%3 == 0 or n%7 == 0) cout << "YES" << endl;
        else if(n < 15 and n > 6)
        {
            bool flag = 0;

            int temp = n;

            temp %= 7;
            if(temp % 3 == 0 or (temp + 7) % 3 == 0) flag = 1;

            if(!flag)
            {
                temp = n;

                temp %= 3;
                if(temp % 7 == 0 or (temp + 6) % 7 == 0)
                {
                    flag = 1;
                }
            }

            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else
        {
            if(n < 6) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }



    return 0;
}