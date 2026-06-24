#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

char s[100][100];

int main(){
    int n,ans = 0,best_ans = 1e9,ok = 0,have_update = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    int len = strlen(s[0]);
    for(int i=0;i<n;i++) {
        ans = 0;
        for(int j=0;j<n;j++) {
            if(i==j) continue; have_update = 0;
            for(int k = 0;k<len;k++) {
                    for(int kk = 0;kk<len;kk++){
                        if(s[i][kk] == s[j][(kk+k+len)%len]) ok = 1;
                        else {ok = 0;break;}
                    }
                    if(ok) {
                        have_update = 1;
                        ans += k;
                        break;
                    }
            } if(!have_update) {printf("-1\n");return 0;}
        }
        best_ans = min(best_ans,ans);
    }
    printf("%d\n",best_ans);
    return 0;
}