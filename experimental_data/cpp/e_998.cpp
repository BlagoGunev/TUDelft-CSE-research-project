#include<cstdio>
typedef long long ll;
const int maxn=1000005;
const int mod=998244353;
int Pow3[maxn];
int Pow3n[maxn];
int n;
int pow3(ll x){
  return Pow3[x%n]*1ll*Pow3n[x/n]%mod;
}
int fac[maxn],ifac[maxn];
int qpow(int a,ll x){
  int ans=1;
  for(;x;x>>=1,a=a*1ll*a%mod){
    if(x&1)ans=ans*1ll*a%mod;    
  }
  return ans;
}
void init(){
  fac[0]=1;
  for(int i=1;i<maxn;++i)fac[i]=fac[i-1]*1ll*i%mod;
  ifac[maxn-1]=qpow(fac[maxn-1],mod-2);
  for(int i=maxn-1;i>=1;--i){
    ifac[i-1]=ifac[i]*1ll*i%mod;
  }
}
int C(int n,int m){
  return fac[n]*1ll*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
  init();
  scanf("%d",&n);
  Pow3[0]=1;
  for(int i=1;i<=n;++i)Pow3[i]=Pow3[i-1]*3ll%mod;
  Pow3n[0]=1;
  int pow3n=Pow3[n];
  for(int i=1;i<=n;++i){
    Pow3n[i]=Pow3n[i-1]*1ll*pow3n%mod;
  }
  int ans1=0;
  for(int i=1;i<=n;++i){//at least i rows are lucky
    if(i&1){
      ans1=(ans1+C(n,i)*1ll*pow3(i)%mod*pow3((n-i)*1ll*n)%mod)%mod;
    }else{
      ans1=(ans1-C(n,i)*1ll*pow3(i)%mod*pow3((n-i)*1ll*n)%mod+mod)%mod;
    }
  }
  int ans2=ans1*2ll%mod;
  for(int i=1;i<=n;++i){
    int tmp=0;
    
    if(n%2==0){
      tmp=qpow((mod+1-pow3(n-i))%mod,n);
      tmp=(tmp-pow3((n-i)*1ll*n)+mod)%mod;
     }
    else{
      tmp=qpow((mod+1-pow3(n-i))%mod,n);
      tmp=((tmp)+pow3((n-i)*1ll*n))%mod;
      tmp=(mod-tmp)%mod;
    }

    
    tmp=tmp*3ll%mod*C(n,i)%mod;

    if(i&1){
      ans2=(ans2+tmp)%mod;
    }else{
      ans2=(ans2-tmp+mod)%mod;
    }
    
  }
  printf("%d\n",(ans2)%mod);
  return 0;
}