#include<bits/stdc++.h>
using namespace std;
const int maxn = 3*1e5+10;
const int MOD = 1e9+7;
int a[maxn];
int t[maxn];
int n;
template <typename T>
inline void read(T& x) {
    char ch; while (!((((ch=getchar())>='0') && (ch <= '9')) || (ch == '-')));
    x = ch-'0'; while (((ch=getchar())>='0') && (ch <= '9')) x = x*10+ch-'0';
}
long long mul(long long a,long long b){
   // cout<<a<<" "<<b<<endl;
    long long ans = 0;
    while(b){
        if(b&1)
            ans = (ans+a)%MOD;
        b>>=1;
        a=(a+a)%MOD;
    }
    return ans%MOD;
}
int main(){
    scanf("%d",&n);
    a[0]=1;
    for(int i=1;i<=n;i++){
         a[i]=(long long)a[i-1]*2%MOD;
    }
    for(int i=1;i<=n;i++)
       read(t[i]);
    sort(t+1,t+1+n);
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long temp = a[n-i]-1;
        long long temp2 = a[i-1]-1;
        sum+=((long long)t[i]%MOD*(temp2-temp)%MOD)%MOD;
        sum=sum%MOD;
    }
    cout<<sum<<endl;
    return 0;
}