#include<bits/stdc++.h>

#define ll long long

#define For(i,a,b) for(int i=(a);i<=(b);++i)

#define Rof(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;

const int Maxn=1e6,Mod=998244353,g=3;



inline ll read()

{

    ll x=0,f=1;

    char ch=getchar();

    while(ch<'0' || ch>'9')

    {

        if(ch=='-') f=-1;

        ch=getchar();

    }

    while(ch>='0' && ch<='9')

    {

        x=x*10+ch-'0';

        ch=getchar();

    }

    return x*f;

}



int n,F[Maxn+5],G[Maxn+5],hzh[Maxn+5],rev[Maxn+5]; ll m;

int len,lim=1,inv[Maxn+5],fac[Maxn+5],ifac[Maxn+5];



inline int Pow(int x,ll y)

{

    int res=1;

    while(y)

    {

        if(y&1) res=1ll*res*x%Mod;

        x=1ll*x*x%Mod,y>>=1;

    }

    return res;

}

inline void Reverse(int *A)

{

    For(i,0,lim-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));

    For(i,0,lim-1) if(i<rev[i]) swap(A[i],A[rev[i]]);

}

inline void NTT(int *A,int opt)

{

    int ninv=Pow(lim,Mod-2); Reverse(A);

    for(int l=2;l<=lim;l<<=1)

    {

        int wi=Pow(g,(Mod-1)/l),mid=(l>>1);

        if(opt==-1) wi=Pow(wi,Mod-2);

        for(int j=0;j<lim;j+=l)

        {

            int w=1;

            for(int k=0;k<mid;++k)

            {

                int f=A[j+k],t=1ll*w*A[j+k+mid]%Mod;

                A[j+k]=(f+t)%Mod,A[j+k+mid]=(f-t+Mod)%Mod;

                w=1ll*w*wi%Mod;

            }

        }

    }

    if(opt==-1) For(i,0,lim-1) A[i]=1ll*A[i]*ninv%Mod;

}

inline void Init()

{

    n=read(),m=read(),inv[1]=fac[0]=ifac[0]=1;

    For(i,0,n) F[i]=read();

    For(i,1,n) fac[i]=1ll*fac[i-1]*i%Mod;

    ifac[n]=Pow(fac[n],Mod-2);

    Rof(i,n-1,1) ifac[i]=1ll*ifac[i+1]*(i+1)%Mod;

    For(i,2,n+1) inv[i]=1ll*(Mod/i)*(Mod-inv[Mod%i])%Mod;

    while(lim<=n*2) lim<<=1,len++;

    For(i,0,n) hzh[i]=inv[i+1];

    For(i,0,n) hzh[i]=Pow(hzh[i],m);

}

inline void Trans1()

{

    For(i,0,n) F[i]=1ll*F[i]*fac[i]%Mod;

    For(i,0,n) G[i]=ifac[i];

    reverse(G,G+n+1);

    NTT(F,1),NTT(G,1);

    For(i,0,lim-1) G[i]=1ll*F[i]*G[i]%Mod;

    NTT(G,-1);

    For(i,0,n) F[i]=1ll*ifac[i]*G[n+i]%Mod;

    For(i,n+1,lim) F[i]=G[i]=0;

}

inline void Trans2() {For(i,0,n) F[i]=1ll*F[i]*hzh[i]%Mod;}

inline void Trans3()

{

    For(i,0,n)

    {

        F[i]=1ll*F[i]*fac[i]%Mod;

        if(i&1) F[i]=(Mod-F[i])%Mod;

    }

    For(i,0,n) G[i]=ifac[i];

    reverse(G,G+n+1);

    NTT(F,1),NTT(G,1);

    For(i,0,lim-1) G[i]=1ll*F[i]*G[i]%Mod;

    NTT(G,-1);

    For(i,0,n)

    {

        F[i]=1ll*ifac[i]*G[n+i]%Mod;

        if(i&1) F[i]=(Mod-F[i])%Mod;

    }

    For(i,n+1,lim) F[i]=G[i]=0;

}



int main()

{

    // freopen("1.in","r",stdin);



    Init();

    Trans1(),Trans2(),Trans3();

    For(i,0,n) printf("%d ",F[i]);

    printf("\n");

    return 0;

}