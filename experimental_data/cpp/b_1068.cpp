#include "bits/stdc++.h"
using namespace std;


int main() {
    long long b; scanf("%lld" , &b);
    if(b == 1) {
        printf("1\n");
        return 0;
    }
    int ans = 0;
    for(int i = 1; 1LL * i * i <= b; ++i) {
        if(b % i == 0) {
            ans++;
            long long div = b / i;
            if(i != div) {
                ans++;
            }
        }
    }
    printf("%d\n" , ans);
}