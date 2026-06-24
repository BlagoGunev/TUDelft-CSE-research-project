#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000")

#include <map>

#include <set>

#include <cmath>

#include <ctime>

#include <deque>

#include <queue>

#include <stack>

#include <vector>

#include <cstdio>

#include <string>

#include <cstdlib>

#include <cstring>

#include <iostream>

#include <algorithm>



using namespace std;



const int MAXN = 100010;



int a[MAXN];



int main ()

{

    int n;

    scanf ("%d", &n);

    for (int i = 1; i <= n; i ++)

    {

        scanf ("%d", &a[i]);

    }

    long long ans = 0;

    for (int i = 1; i < n; i ++)

    {

        int j = i + 1;

        while (a[j] <= a[j - 1])

        {

            j ++;

            if (j > n)

            {

                break;

            }

        }

        j --;

        ans += (long long) (a[i] - a[j]);

        i = j;

    }

    printf ("%lld\n", ans);

    return 0;

}