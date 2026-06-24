#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
 
const int N = 4e5 + 10;
 
int h[N], ne[2*N], e[2*N], idx, d[N], st[N];
 
 
void add(int a, int b){
    ne[idx] = h[a], e[idx] = b, h[a] = idx++;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);
        idx = 0;
        for(int i = 1; i <= n; i++){
            d[i] = st[i] = 0;
            h[i] = -1;
        }
        if(n == 1) d[1] = 1;
        for(int i = 0; i < n-1; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
            d[a]++, d[b]++;
        }
        
        queue<int> q;
 
        for(int i = 1; i <= n; i++){
            if(d[i] == 1) q.push(i), st[i] = 1;
        }
        int ans = 0;
        while(!q.empty() && k){
            ans += q.size();
            int x = q.size();
            for(int i = 0; i < x; i++){
                int x = q.front();
                q.pop();
                for(int j = h[x]; ~j; j =ne[j]){
                    int b = e[j];
                    if(st[b]) continue;
                    if(--d[b] == 1) q.push(b), st[b] = 1;
                }
            }
            k--;
        }
        printf("%d\n", n - ans);
    }
}