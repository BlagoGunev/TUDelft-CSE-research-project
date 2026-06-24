#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAXN = 1111;

int n, m;

long double comb(int k)
{
    int a,b;
    a = n*m, b = n;

    long double ret = 1.0 / (long double)(n*n);
    b = min(b, a-b);
    for(int i=0;i<b;i++){
        ret /= (long double)(a-i);
        ret *= (long double)(b-i);
    }
    
    a = n*m-m, b = n-k;

    b = min(b, a-b);
    for(int i=0;i<b;i++){
        ret *= (long double)(a-i);
        ret /= (long double)(b-i);
    }

    a = m, b = k;
    b = min(b, a-b);
    for(int i=0;i<b;i++){
        ret *= (long double)(a-i);
        ret /= (long double)(b-i);
    }
    return ret;
}

int main()
{
    cin>>n>>m;
    long double ans = 0;
    for(int i=1;i<=min(n, m);i++)
        ans +=  comb(i) * (long double)(i*i);
    ans *= (long double)(n);
    printf("%.11f\n", (double)ans); 
}