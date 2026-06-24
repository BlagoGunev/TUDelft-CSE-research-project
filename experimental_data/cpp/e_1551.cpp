#include<bits/stdc++.h>

#define LL long long

#define N 1000005

#define inf 0x7f7f7f7f7f7f

using namespace std;



inline LL read(){

	LL e=0,ch=1;char c=getchar();

	while(c<'0'||c>'9'){if(c=='-')ch=-1;c=getchar();}

	while(c>='0'&&c<='9'){e=e*10+c-48;c=getchar();}

	return e*ch;

}



LL t,n,k;

LL a[N],f[N];



int main(){

    t=read();

    while(t--){

        n=read();k=read();

        for(int i=1;i<=n;++i) a[i]=read();

        for(int i=1;i<=n;++i){

            f[i]=0;

            for(int j=0;j<i;++j){

                if(a[i]<=a[j]) continue;

                if(i-j>=a[i]-a[j]){

                    f[i]=max(f[i],f[j]+1);

                }

            }

        }

        LL ans=inf;

        for(int i=1;i<=n;++i){

            if(f[i]>=k){

                ans=min(ans,max(0ll,i-a[i]));

            }

        }

        if(ans==inf) ans=-1;

        cout<<ans<<'\n';

    }

	return 0;

}