#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m,k;
char s[200005];
int main(){
	scanf("%d", &t);
    while(t--){
    	scanf("%lld %lld %lld", &n, &m, &k);
        scanf("%s",s);
        long long ans=0;
        int sum=1;
        ans=m*2+k*(n+1);
        bool ok=0,flag=0;
        long long now=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')ans+=m+k,ok=1,flag=1;
            else{
                if(s[i-1]=='1')ans+=k,now=0;
                if(i<n&&s[i+1]=='1'&&ok)ans+=min(m*2,now*k)+m,now=0;
                else now++,ans+=m;
            }
        }
        if(flag==0)ans-=(m*2);
        printf("%lld\n", ans);
    }
    return 0;
}