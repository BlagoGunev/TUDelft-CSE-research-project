#include<bits/stdc++.h>
using namespace std;
#define maxn 210000
//#define int long long
typedef long long ll;
char s[maxn];
void work(){
    scanf("%s",s+1);
    int n=strlen(s+1),t=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0')t++;
        else{
            ans++;
            int v=1,k=2;
            for(int j=i+1;j<=min(20+i,n);j++,k++){
                v=v*2+s[j]-'0';
                if(t+k>=v)ans++;
                else break;
            }
            t=0;
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    int t;scanf("%d",&t);
    while(t--)work();
    return 0;
}