#include <cstdio>
#include <algorithm>
using namespace std;
int n,cnt; bool arr[100000]; char c;
int main() {
    scanf("%d",&n);
    for (int i = 0;i < n;i++) scanf(" %c",&c),arr[i] = (c == 'G')?1:0,cnt += (c == 'G')?1:0;
    int tmp = 0,ans = 0;
    for (int i = 0,j;i < n;i = j+1) {
        for (j = i;j < n && arr[j];j++);
        tmp += j-i; ans = max(ans,tmp);
        tmp = j-i+1;
    }
    ans = max(ans,tmp);
    ans = min(ans,cnt);
    printf("%d\n",ans);
    return 0;
}