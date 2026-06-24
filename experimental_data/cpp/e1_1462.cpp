#include<bits/stdc++.h>
using namespace std;
#define N 200100
#define ll unsigned long long
inline int read()
{
    int s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
}
int T,n,a[N],mx,tcnt,lstans[N],vis[N],num[N];
ll ans;
int main()
{
    T=read();
    while(T--)
    {
        n=read();mx=-1;ans=0;
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=tcnt;i++) {num[lstans[i]]=0;vis[lstans[i]]=0;}
        tcnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[a[i]]) lstans[++tcnt]=a[i],vis[a[i]]=1;
            num[a[i]]++;mx=max(mx,a[i]);
        }
        //cerr<<num[1]<<endl;
        //cerr<<" "<<tcnt<<endl;
        sort(lstans+1,lstans+tcnt+1);
        //cerr<<1<<endl;
        for(int i=1;i<=tcnt;i++)
        {
            if(num[lstans[i]]<3) continue;
            //cerr<<lstans[i]<<endl;
            //cerr<<num[1]<<endl;
            ans+=(1ll*num[lstans[i]]*(num[lstans[i]]-1)*(num[lstans[i]]-2)/6);
        }
        //cerr<<2<<endl;
        for(int i=1;i<=tcnt;i++)
        {
            int tmp=i+1;
            while((lstans[tmp]-lstans[i]<=2)&&(tmp<=tcnt))
            {
                //cerr<<tmp<<endl;
                if(num[lstans[tmp]]>=2)
                {
                    ans+=(1ll*num[lstans[i]]*num[lstans[tmp]]*(num[lstans[tmp]]-1)/2);
                }
                if(num[lstans[i]]>=2)
                {
                    ans+=(1ll*num[lstans[tmp]]*num[lstans[i]]*(num[lstans[i]]-1)/2);
                }
                tmp++;
            }
        }
        ////cerr<<3<<endl;
        for(int i=1;i<=tcnt-2;i++)
            for(int j=i+1;j<=tcnt-1&&lstans[j]-lstans[i]<=2;j++)
                for(int k=j+1;k<=tcnt&&lstans[k]-lstans[i]<=2;k++)
                    ans+=1ll*num[lstans[i]]*num[lstans[j]]*num[lstans[k]];
        printf("%llu\n",ans);
    }
    return 0;
}