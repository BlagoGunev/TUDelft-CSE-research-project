#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int X[100005][20];
long long two[100005];

int getHighestBit(int x)
{
    for(int i=19; i>=0; i--)
        if(x & (1<<i))
            return i;
    
    return 0;
}

int main() {
    
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    two[0] = 1;
    
    for(int i=1; i<=100000; i++)
        two[i] = two[i-1] * 2 % MOD;
    
    for(int i=0; i<20; i++)
        X[0][i] = -1;
    
    for(int i=1; i<=N; i++)
    {
        int x;
        scanf("%d", &x);
        
        for(int j=0; j<20; j++)
            X[i][j] = X[i-1][j];
        
        while(x) {
            int msb = getHighestBit(x);
            
            if(X[i][msb] == -1) {
                X[i][msb] = x;
                break;
            }
            
            x = (x ^ X[i][msb]);
        }
    }
    
    while(Q--)
    {
        int L, x;
        scanf("%d %d", &L, &x);
        
        int curr = 0, filled = 0;
        
        for(int i=19; i>=0; i--)
        {
            if(X[L][i] != -1)
                filled++;
            
            if((x & (1<<i)) == (curr & (1<<i)))
                continue;
            
            if(X[L][i] != -1)
                curr ^= X[L][i];
        }
        
        if(curr != x) {
            printf("0\n");
            continue;
        }
        
        long long ans = two[L-filled];
        printf("%lld\n", ans);
    }
    
    return 0;
}