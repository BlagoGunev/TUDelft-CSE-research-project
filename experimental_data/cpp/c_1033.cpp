#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int a[101000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int i,n,x,j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = i;
    }
    string s(n + 1, 'C');
    for (i = n; i > 0; i--)
    {
        for (j = a[i] % i; j <= n; j += i)
            if (s[j] == 'B')
            {
                s[a[i]] = 'A';
                break;
            }
        if (s[a[i]] != 'A')
            s[a[i]] = 'B';
    }
    s.erase(0, 1);
    cout << s;
    return 0;
}