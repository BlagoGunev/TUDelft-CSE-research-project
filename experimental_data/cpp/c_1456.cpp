#include<bits/stdc++.h>
#define N 500009
using namespace std;
typedef long long ll;
int n,k,tg;
ll a[N],ans,num,x[N];
inline ll rd(){
    ll x=0;char c=getchar();bool f=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return f?-x:x;
}
int main(){
    n=rd();k=rd();
    for(int i=1;i<=n;++i)a[i]=rd();
    sort(a+1,a+n+1);
    for(int i=n;i>=1;--i){
    	ans+=num;
	//	cout<<num<<" ";
    	num+=a[i];
    	if(num<0){tg=i;x[i]=num;break;}
    }
  //  cout<<ans<<endl;
    for(int i=tg-1;i>=1;--i)x[i]=a[i];
    int cnt=0,ns=0;
    for(int i=k+2;i<=tg;++i){
    	cnt++;
    	if((cnt-1)%(k+1)==0)ns++;
    	ans+=x[i]*ns;
    }
    cout<<ans;
	return 0;
}