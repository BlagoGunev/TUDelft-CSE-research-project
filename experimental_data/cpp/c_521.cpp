#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200005
#define mo 1000000007
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Dor(i,r,l) for(int i=r;i>=l;i--)
int n,k; char s[N];
int Fac[N],Rev[N],Pow[N],F[N],Ans;
int power(int a,int b){
    int c=1;
    while(b){
        if(b&1) c=1LL*c*a%mo;
        b>>=1; a=1LL*a*a%mo;
    }
    return c;
}
int C(int n,int m){
    if(m>n) return 0;
    return 1LL*Fac[n]*Rev[m]%mo*Rev[n-m]%mo;
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    
    Fac[0]=1; For(i,1,n) Fac[i]=1LL*Fac[i-1]*i%mo;
    Rev[n]=power(Fac[n],mo-2); Dor(i,n,1) Rev[i-1]=1LL*Rev[i]*i%mo;
    
    Pow[0]=1; For(i,1,n) Pow[i]=1LL*Pow[i-1]*10%mo;
    
    For(i,1,n) F[i]=(F[i-1]+1LL*Pow[i-1]*C(n-1-i,k-1))%mo;
    For(i,1,n){
        Ans=(Ans+1LL*(s[i]-'0')*F[n-i])%mo;
        Ans=(Ans+1LL*(s[i]-'0')*Pow[n-i]%mo*C(i-1,k))%mo;
    }
    printf("%d\n",Ans);
    
}