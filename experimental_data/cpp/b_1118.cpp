#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#define rg register
#define il inline
using namespace std;
typedef unsigned long long ll;
ll read(){
    ll ans=0,flag=1;char ch;
    while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;
    ans=ch^48;
    while((ch=getchar())>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48);
    return flag*ans;
}
void write(ll x){
    if(x<0){putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int sumo[200005];
int sume[200005];
int pre[200005];
int main()
{
    int n=read();
    for(rg int i=1;i<=n;i++)
        pre[i]=read();
    for(rg int i=n;i>0;i--){
        if(i%2==0){
            sume[i]=pre[i]+sume[i+2];
            sumo[i]=sumo[i+1];
        }
        else{
            sume[i]=sume[i+1];
            sumo[i]=sumo[i+2]+pre[i];
        }
    }
    int ans=0;
    for(rg int i=1;i<=n;i++){
        int even=sume[1]-sume[i];
        int odd=sumo[1]-sumo[i];
        even+=sumo[i+1];
        odd+=sume[i+1];
        if(even==odd)ans++;
//        cout<<odd<<' '<<even<<endl;
    }
    cout<<ans<<endl;
    return 0;
}