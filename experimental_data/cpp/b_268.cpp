#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

using namespace std;

int n;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    if(n == 1){
        printf("1\n");
        return 0;
    }
    int64_t ans = n;
    int k = 2;
    int i = n-2;
    for(;k < n;k++,i--){
        ans += k*i + 1;
    }
    ans++;
    printf("%d\n",ans);
    return 0;
}