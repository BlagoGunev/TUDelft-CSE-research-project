/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#define MAX 25
#define MOD 1000000007
#define INF 100000000000000000
#define EPS 0.00000001
#define ll long long
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    a = min(a, b);
    int res = 1;
    for(int i=2; i<=a; ++i)
        res *= i;
    printf("%d", res);
}