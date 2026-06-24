#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
const int maxn = 4e6+5;
const int MOD = 1e9+7;
#define mod(x) x % MOD
#define INF 0x3f3f3f3f

int a[maxn];

int main(){
    int n = 0;
    while(~scanf("%d", &n)){
        int sum = 0;
        bool flag = 0;
        for(int i = 1;i <= 2 * n;i++){
            scanf("%d", a + i);
            sum += a[i];
        }
        for(int i = 1;i < 2 * n;i++){
            if(a[i] != a[i+1]){
                flag = 1;
            }
        }
        if(flag == 0){
            puts("-1");
            continue;
        }
        sort(a + 1,a + 1 + 2 * n);
        if(sum % 2 == 1){
            for(int i = 1;i <= 2 * n;i++){
                printf("%d%c",a[i], i == 2 * n ?'\n':' ');
            }
        }
        else{
            ll res = 0;
            for(int i = 1;i <= n;i++){
                res += 1ll * a[i];
            }
            if(res == sum / 2){
                int index1 = 0, index2 = 0;
                bool f = 0;
                for(int i = 1;i <= n;i++){
                    for(int j = n + 1;j <= 2 * n;j++){
                        if(a[i] != a[j]){
                            swap(a[i],a[j]);
                            f = 1;break;
                        }
                    
                    }
                    if(f == 1) break;
                }
                if(f == 0) puts("-1");
                else{
                    for(int i = 1;i <= 2*n;i++){
                        printf("%d%c",a[i], i == 2 * n ?'\n':' ');
                    }
                }

            }
            else{
                for(int i = 1;i <= 2*n;i++){
                    printf("%d%c",a[i], i == 2 * n ?'\n':' ');
                }
            }
        }
    }
    return 0;
}