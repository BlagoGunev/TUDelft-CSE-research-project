#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <cmath>
#include <bitset>
#include <stack>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <utility>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
 
#define mod 1000000007
#define ll long long
#define INF 1000000000
#define PI 3.1415926


int main (void)
{

  //  ifstream cin ("in.txt");

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int score = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        score += a;
    }

    int kiek = score/1000;

    if (score % 1000 > 500)
        kiek++;

    for (int i = 0; i < kiek; i++)
        cout << 'G';

    for (int i = 0; i < n - kiek; i++)
        cout << 'A';

    cout << endl;

  //  while (true) {}
 
}