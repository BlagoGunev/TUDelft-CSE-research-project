#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define M 100500
int pri[M],sum[M];
char str[M];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
        scanf("%d",&pri[i]);
        sum[i]=i?sum[i-1]+pri[i]:pri[i];
        }
        scanf("%s",str);
        int strnum=strlen(str);
        int j=strnum-1;
        while(j>0&&str[j]=='0'){j--;}
        strnum=j;
        int ans=0,len=0;
        for(i=j;i>=0;i--){
            if(str[i]!='0'){
            ans=max(ans,len+sum[i-1]);
            len+=pri[i];
            }
        }
        ans=max(ans,len);
        cout<<ans<<endl;
    }
    return 0;
}