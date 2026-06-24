#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

#define y1 roman_kaban
#define rank oryshych_konb
//const int mod = int(1e9) + 7;

const int MX = 200500;


int main()
{
    //freopen("in.txt","r", stdin);
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    d = sqrt(d);
    double x1 = (-b + d) / 2 / a;
    double x2 = (-b - d) / 2 / a;
    if(x1 < x2) swap(x1, x2);
    printf("%.10f\n", x1);
    printf("%.10f\n", x2);
    return 0;
}