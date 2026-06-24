#include <cstdio>  
#include <algorithm>  
#include <ctime>  
using namespace std;  
  
int d[10];  
int n,a,b,i;  
int len,cnt,ans;  
  
inline int Min(int x, int y){ return x<y?x:y; }  
int main(){  
    while (scanf("%d",&n)==1){  
        scanf("%d",&a);  
        scanf("%d",&b);  
        d[1] = d[2] = d[3] = d[4] = a;  
        d[5] = d[6] = b;  
        ans = 6; cnt = 10;  
        for (srand(time(0)), i = 1000; i--; ans = Min(ans,cnt)){  
            random_shuffle(d+1,d+7);  
            cnt = len = 0;  
            for (int k=1; k<=6; k++) {  
                if (len < d[k]) {len = n; cnt++; }  
                len -= d[k];  
            }  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}