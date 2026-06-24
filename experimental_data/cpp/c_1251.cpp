#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3e5+10;
char s[maxn];
char a[maxn];
char b[maxn];
char ans[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int n=0;
        int m=0;
        for(int i=0;s[i];i++){
            if((s[i]-'0')%2==1){
                a[n++]=s[i];
            }
            else{
                b[m++]=s[i];
            }
        }
        a[n]=0;
        b[m]=0;
        int j=0,k=0;
        for(int i=0;i<m+n;i++){
            if(j>=n){
                ans[i] = b[k++];
            }
            else if(k>=m){
                ans[i] = a[j++];
            }
            else{
                if(a[j]<b[k]){
                    ans[i] = a[j++];
                }
                else{
                    ans[i] = b[k++];
                }
            }
        }
        ans[n+m]=0;
        printf("%s\n",ans);
    }
    return 0;
}