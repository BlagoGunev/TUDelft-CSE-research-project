#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#define ll long long
#define Inf 100000000000000000ll
#define MAXN 100000
using namespace std;


int P[1111111];
int neg_to_pos[1111111];

char buf[8000000];


int readint() {
    int m;
    static char *bp=buf;
    if(*bp<'0' || *bp>'9')
        *bp++;
    
    for(m=*bp++-48; *bp>=48; bp++) m = m*10+*bp-48;
    bp++;
    return m;
}


ll BruteForce(int n) {
    ll ans = -1;
    for(int shift=0;shift<n;shift++) {
        ll curr = 0;
        for(int i=0;i<n;i++) {
            int j=(i-shift+n)%n;
            curr += labs(j-P[i]);
        }
        if (shift==0)
            ans = curr;
        else
            ans = min(ans, curr);
    }
    return ans;
    
}

int main() {
    
    
    fread(buf, 1, 7999999, stdin);

    int n=readint();
    for(int i=0;i<n;i++) {
        P[i]=readint();
        P[i]--;
    }
     

    for(int i=0;i<=n;i++)
        neg_to_pos[i]=0;
    
    for(int i=0;i<n;i++) {
        int k=(P[i]-i+n)%n;
        if (k == 0)
            continue;
        if ((i+k)%n==P[i] && (i+k-1+n)%n<P[i]) {
            neg_to_pos[k]++;
        }
    }
    
    int num_less=0;
    int num_great=0;
    
    ll curr = 0;
    for(int i=0;i<n;i++) {
        curr += labs(P[i]-i);
        if (i<P[i])
            num_less++;
        else
            num_great++;
    }
    
    int opt_shift=0;
    
    ll ans = curr;
    for(int k=1;k<n;k++) {

        // for k
        curr += num_great-1-num_less+P[n-k]-(n-1-P[n-k]);

        
        if (ans > curr) {
            opt_shift = k;
            ans = curr;
        }
        
        
        num_less -= neg_to_pos[k];
        
        if (P[n-k]>0)
            num_less++;
        
        
        num_great = n-num_less;
    }
    
    printf("%lld %d\n",ans,opt_shift);
    
    
}