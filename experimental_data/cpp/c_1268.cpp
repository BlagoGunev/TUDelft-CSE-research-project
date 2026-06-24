/////////////////////////   _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 300005;
const int inf = 1000 * 1000 * 1000;
const int mod = 998244353;

int n;
int a[N];
int ind[N];

int t[N];
long long A[N];

void upd(int pos){
    int delta = pos;
    for(; pos <= n; pos += pos & -pos){
        t[pos]++;
        A[pos] += delta;
    }
}

int get(int pos){
    int answ = 0;
    for(; pos > 0; pos -= pos & -pos){
        answ += t[pos];
    }
    return answ;
}

int get(int l,int r){
    return get(r) - get(l - 1);
}

long long G(int pos){
    long long answ = 0;
    for(; pos > 0; pos -= pos & -pos){
        answ += A[pos];
    }
    return answ;
}

long long G(int l,int r){
    return G(r) - G(l - 1);
}

long long pat[N];

long long calc(int x){
    int c1 = get(1 , x - 1);
    int c2 = get(x + 1 , n);
    long long s1 = G(1 , x - 1);
    long long s2 = G(x + 1 , n);

    long long pat = s2 - c2 * 1ll * x;
    pat += c1 * 1ll * x - s1;

    pat -= c1 * 1ll * (c1 + 1) / 2;
    pat -= c2 * 1ll * (c2 + 1) / 2;
    return pat;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ind[ a[i] ] = i;
    }

    pat[0] = 0;
    for(int i=1;i<=n;i++){
        pat[i] = pat[i - 1] + get(ind[i] + 1 , n);
        upd(ind[i]);

        int ina = 1 , inb = n , med;
        while(ina <= inb){
            int mid = (ina + inb) / 2;
            if(get(1 , mid) >= (i + 1) / 2){
                med = mid;
                inb = mid - 1;
            }
            else
                ina = mid + 1;
        }

        long long res = pat[i] + calc(med);
        printf("%lld ",res);
    }
    cout << endl;
    return 0;
}