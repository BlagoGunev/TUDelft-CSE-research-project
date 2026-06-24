//#include "stdafx.h"

# define _CRT_SECURE_NO_DEPRECATE
# include <fstream>
# include <iostream>
# include <stdlib.h>
# include <queue>
# include <string>
# include <cstdio>
# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <vector>
# include <unordered_map>
# include <set>
# include <map>
# include <iomanip>
# include <math.h>
# include <stack>
# include <functional>
# define inf 9223372036854775807
# define mp make_pair
# define pb push_back
# define FOR(k,a,z) for (int k=a;k<z;k++)
# define pi 3.14159265359
# define maxint 2147483647
# define ll long long

#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))


using namespace std;

vector<int> di;
vector<int> a[100001];
int n,m;

void hei(int & x) {
    if (x>n) {
        x=x-n;
    }
    return;
}
bool com(int x,int y) {
    hei(y);
    if (a[x].size()!=a[y].size()) return false;
    FOR(k,0,a[x].size()) {
        if (a[x][k]!=a[y][k]) return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n>>m;
    int x,y;
    FOR(k,0,m) {
        scanf("%d",&x);
        scanf("%d",&y);
        if (x>y) swap(x,y);
        if (y-x==n/2) {
            a[y].pb(n-(y-x));
            a[x].pb(n-(y-x));
        } else {
            if (y-x<=n/2) a[x].pb(y-x); else {
                a[y].pb(n-(y-x));
            }
        }
        
    }
    FOR(k,1,n+1) {
        sort(a[k].begin(),a[k].end());
    }
    
    
    if (n==2) {
        di.pb(1);
    } else {
        FOR(k,1,n) {
            if (n%k==0) di.pb(k);
        }
    }
    
    FOR(k,0,di.size()) {
        int x = 1;
        bool ppc= true;
        while (x<=n) {
            FOR(j,0,di[k]) {
                if (!com(x+j,x+di[k]+j)) {
                    ppc = false;
                    break;
                }
            }
            if (ppc==false) break;
            x+=di[k];
        }
        if (ppc) {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}