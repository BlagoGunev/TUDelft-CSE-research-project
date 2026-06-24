#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int main()
{
    int n,ans;
    while (~scanf("%d",&n)){
            ans=0;
        if (n==1){
            printf("0\n");
            continue;
        }
        if (n%2)
            ans=(n-1)/2;
        else
            ans=n/2-1;
        printf("%d\n",ans);
    }
    return 0;
}