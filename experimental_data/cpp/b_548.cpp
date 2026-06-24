/* 
 * File:   B_Mike_andfun.cpp
 * Author: Rok
 *
 * Created on 26. maj 2015, 18:50
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <iomanip>

#define ll long long
#define ull unsigned long long
#define lli long long int
#define PI 3.1415926535897932384626
#define INF 1e9
#define MOD 1000000007

using namespace std;

/*
 * 
 */

int n, m, q;
bool matrika[505][505];
int vsotaVrstic[505];

int main(int argc, char** argv) {
    
    cin >> n >> m >> q;
    
    int bit, max, stevec;
    for(int i = 0; i < n; i++)
    {
        max = 0;
        stevec = 0;
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &bit);
            matrika[i][j] = bit;
            if(!bit)
            {
                if(stevec > max)
                    max = stevec;
                stevec = -1;
            }
            stevec++;
        }
        if(stevec > max)
            max = stevec;
        vsotaVrstic[i] = max;
    }
    
    int x, y;
    for(int i = 0; i < q; i++)
    {
        max = 0;
        stevec = 0;
        scanf("%d %d", &x, &y);
        matrika[x-1][y-1] = !matrika[x-1][y-1];
        for(int j = 0; j < m; j++)
        {
            if(!matrika[x-1][j])
            {
                if(stevec > max)
                    max = stevec;
                stevec = -1;
            }
            stevec++;
        }
        if(stevec > max)
            max = stevec;
        vsotaVrstic[x-1] = max;
        for(int j = 0; j <  n; j++)
        {
            if(vsotaVrstic[j] > max)
            {
                max = vsotaVrstic[j];
            }
        }
        printf("%d\n", max);
    }

    return 0;
}