#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
#define LL long long
#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define lc (x<<1)
#define rc ((x<<1)|1)
const int N=1000000,NN=2000000,MN=1000010;
const LL inf=10000000000000000ll;
int prime[MN];
LL cnt[MN*2],sum0[MN*2],sum1[MN*2],tot;
void init(int n){
    int i,j;
    for (i=1;i<=n;i++){int x;scanf("%d",&x);cnt[x]++;}
    for (i=NN;i>=1;i--){
        sum0[i]=sum0[i+1]+cnt[i];
        sum1[i]=sum1[i+1]+cnt[i]*((LL)(NN-i+1));
    }
 //   for (i=1;i<=100;i++) printf("i:%d  sum0[i]:%I64d   sum1[i]:%I64d\n",i,sum0[i],sum1[i]);
    
    static int b[MN];
    for (i=2;i<=N;i++){
        if (b[i]) continue;
        prime[++tot]=i;
        for (j=i+i;j<=N;j+=i) b[j]=1;
    }
}
inline LL cal(int i,int j,int d,LL x,LL y){
    int p=j-i+1,q=max(p,j-d);
    LL s1=(sum0[p]-sum0[q])*x;
    LL s2=((sum1[q]-sum1[j])-((LL)(NN+1-j))*(sum0[q]-sum0[j]))*y;
    return s1+s2;
}
int main(){
  //  freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int n,d;LL x,y,ans=inf;
    cin>>n>>x>>y;d=((int)(x/y));
    init(n);
    for (int ii=1;ii<=tot;ii++){
        int i=prime[ii];
        LL sum=0;
        for (int j=i;j<=NN;j+=i){
            if (j-i>=N) break;
            sum+=cal(i,j,d,x,y);
            if (sum>ans) break;
        }
   //     printf("%d %d\n",i,sum);
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
  //  system("pause");
    return 0;
}