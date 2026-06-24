#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 3050500
const int mod=1e9+7,Up=3e6;
int fp[N+N];
int v[N],tot,p[N],sp[N],n,m,jc[N],inv[N],K,D,t;
int id(int x){
    return x>t?t+n/x+5:x;
}
int C(int n,int m){
    return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ans;
}
int f(int p,int c){
    return C(c*K+D,D);
}
int calcf(int n,int k){
	int res=fp[id(n)]-sp[k-1];
	for(int i=k;i<=tot;++i){
		if(p[i]*p[i]>n)break;
		int now=p[i];
		for(int c=1;now*p[i]<=n;++c,now*=p[i]){
			res+=f(p[i],c)*calcf(n/now,i+1)%mod+f(p[i],c+1);res%=mod;
		}
	}
	return res;
}
/*
这个题里面f(p)=4，因为是约数个数的平方
*/
void init(int n){//sqrt n
	vector<int>ud;tot=0;
	for(int l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),n);
		ud.push_back(n/l);
	}
	//这玩意可以直接滚动数组，每次找最前面的
    /*从大到小存储，每次直接算，如果不必再算就pop*/
	t=sqrt(n)+1;
	for(auto x:ud)fp[id(x)]=(x-1)%mod;
	for(int i=2;i<=t;++i){
		if(!v[i]){
			v[i]=1;p[++tot]=i;sp[tot]=sp[tot-1]+1,sp[tot]%=mod;
			for(int j=i;j<=t;j+=i)v[j]=1;
			if(ud.empty())continue;
			for(auto x:ud){
				if(i*i<=x)fp[id(x)]-=fp[id(x/i)]-sp[tot-1],fp[id(x)]%=mod;
			}
			while(!ud.empty()&&i*i>ud[ud.size()-1]){
				ud.pop_back();
			}
		}
	}
    for(int i=1;i<=t;++i)v[i]=0;
	for(int i=1;i<=tot;i++)sp[i]*=f(1,1),sp[i]%=mod;
	for(int l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),n);fp[id(n/l)]*=f(1,1),fp[id(n/l)]%=mod;
	}
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    jc[0]=1;
    for(int i=1;i<=Up;++i)jc[i]=jc[i-1]*i%mod;inv[Up]=power(jc[Up],mod-2);
    for(int i=Up;i;--i)inv[i-1]=inv[i]*i%mod;
    int T;cin>>T;
    while(T--){
        cin>>n>>K>>D;
        init(n);
        int res=calcf(n,1)+1;
        res=(res%mod+mod)%mod;
        cout<<res<<"\n";
    }
}