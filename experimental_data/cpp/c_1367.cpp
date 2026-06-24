#include <bits/stdc++.h>

using namespace std;
char a[200005];
int in[200005];
int main()
{
    int t,n,tmp,k,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        scanf("%s",a);
        tmp=0;ans=0;
        in[tmp++]=-k-1;
        for(int i=0;i<n;++i){
            if(a[i]=='1')
                in[tmp++]=i;
        }
        in[tmp++]=n+k;
            int i=0,j=0;
            for(;i<n&&j<tmp;++i){
                while(i-in[j]>k&&in[j+1]-i>k){
                    ++ans,i+=k+1;
                }
                while(i>in[j+1])
                    ++j;
            }
            printf("%d\n",ans);
    }
}