#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;

int main()
{
    scanf("%d",&t);
    while(t--){
        ll s;
        scanf("%d%lld", &n, &s);
        ll sum = 0;
        int maxv = 0, maxi = 0;
        int ans = -1;
        for(int i = 1; i <= n; i++){
            int cur;
            scanf("%d", &cur);
            sum += cur;

            if(cur > maxv){
                maxv = cur;
                maxi = i;
            }

            if(sum - maxv <= s)ans = maxi;
        }

        if(sum <= s)ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}