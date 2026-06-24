/*
ID: wanbo2
PROG: test
LANG: C++
*/
#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
#define M(a,i) memset(a,i,sizeof(a))

int main() {
#ifndef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n;
    while(n--) {
        cin >> m;
        cout << (m + 1) % 2 << endl;
    }
#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}