#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define REPN(i,a,n) for(int i=a;i<a+n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOR2(i,b,a) for(int i=b;i>=a;i--)


#define MOD 1000000000+7
#define MAXN 1000000+5
char s[MAXN];
//#define LOCAL
int main(){
        #ifdef LOCAL
                freopen("input.txt","r",stdin);
                //freopen("output.txt","w",stdout);
        #endif // LOCAL
        scanf("%s",s);
        int l=strlen(s);
        int i=l;
        int b=0;
        int ans=0;
        while(i--){
               if(s[i]=='b')b++;
               if(s[i]=='a'){
                        ans+=b;
                        ans%=MOD;
                        b*=2;
                        b%=MOD;
               }
        }
        printf("%d",ans);
        return 0;
}