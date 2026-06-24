#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>  
#include <string>
using namespace std;
 
typedef long long ll;
const int INF = (int)1E9 + 10;
const double EPS = 1E-9;
const int MAXN = (int)(5e5 + 10);
const int MOD = (int)(1e9+7);
 
#define mp make_pair 
#define FOR(i,s,f) for(int i=s; i<f; i++)
#define BFOR(i,s,f) for(int i= (f-1); i>=s; i--)
 
//int dir[2][4] = {{ -1, 0, 1, 0 },
//{ 0, 1, 0, -1 }}; 
//************************************************

struct pt
{
    int x, y;

    bool operator < ( const pt &p ) const
    {
        if(y == p.y) return x < p.x;
        return y < p.y;
    }
};

pt arr[MAXN];

int main()
{
//freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);

int n; cin >> n;

FOR(i,0,n)
{
    scanf("%d%d", &arr[i].x , &arr[i].y);
}

sort (arr, arr+n);

int cnt = 1; pt last = arr[0];

FOR(i,1,n)
{
    if(arr[i].x > last.y && arr[i].y > last.y)
    {
        cnt ++; last = arr[i];
    }
}

cout << cnt << endl;

//fclose(stdin); fclose(stdout);
    return 0;
}