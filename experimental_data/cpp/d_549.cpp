//#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

char c[200][200];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%c", &c[i][j]);
        }
        scanf("\n");
    }
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int val = (c[i - 1][j] - 'A') + (c[i][j - 1] - 'A') + (c[i - 1][j - 1] - 'A') + (c[i][j] - 'A');
            if (val == ('B' - 'A') * 3 + ('W' - 'A') || val == ('W' - 'A') * 3 + ('B' - 'A'))
            {
                cnt++;
            }
            if (c[i - 1][j] == c[i][j - 1] && c[i][j] == c[i - 1][j - 1] && c[i][j] != c[i][j - 1])
                cnt++;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int val = (c[i - 1][m - 1] - 'A') + (c[i][m - 1] - 'A');
        if (val == ('W' - 'A') + ('B' - 'A'))
            cnt++;
    }
    for (int i = 1; i < m; i++)
    {
        int val = (c[n - 1][i - 1] - 'A') + (c[n - 1][i] - 'A');
        if (val == ('W' - 'A') + ('B' - 'A'))
            cnt++;
    }
    printf("%d", cnt + 1);
}