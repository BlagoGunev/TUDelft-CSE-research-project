#include<stdio.h>
#include<algorithm>
using namespace std;
char str[100005];
int cnt[4];
int main ()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    for(int i  =0;i<n;i++){
        if(str[i]=='A') cnt[0]++;
        else if(str[i]=='C') cnt[1]++;
        else if(str[i]=='G') cnt[2]++;
        else cnt[3]++;
    }
    int mx = 0;
    for(int i  =0;i<4;i++){
        mx = max(mx,cnt[i]);
    }
    int a = 0;
    for(int i =0;i<4;i++){
        if(cnt[i]==mx) a++;
    }
    int mod = 1000000007;
    int ans = 1;
    for(;n;n>>=1){
        if(n&1) ans = (long long)ans*a%mod;
        a = (long long)a*a%mod;
    }
    printf("%d\n",ans);
    return 0;
}