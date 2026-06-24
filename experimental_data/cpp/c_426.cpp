/*
    LucaspalA<<<<<____>>> :)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
//#include "race.h"
#define f first
#define s second
#define m_p make_pair
#define ll long long
#define MAX 210
#define pb push_back
#define pr pair <int,int>

using namespace std;

pr a[MAX];
int b[MAX], par[MAX];
int main()
{
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].f;
        a[i].s = i;
        b[i] = a[i].f;
        par[i] = par[i-1] + b[i];
    }
    int maxx = -(1<<30);
    sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int mx = k, sum = 0, num = (j-i+1);

            for(int q = n; q >= 1; q--)
            {
                if(!num) continue;

                if(a[q].s >= i && a[q].s <= j) {sum += a[q].f; num--; continue;}
                if(mx && (a[q].s < i || a[q].s > j)) mx--, sum += a[q].f, num--;

            }

                //cout << i << " " << j <<" " << mx << " " << sum << " " << num <<" " << par[j] - par[i-1] << endl;
            maxx = max(maxx,sum);
        }
    }
    cout << maxx << endl;
    return 0;
}