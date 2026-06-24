#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=201010 ;
int t;
long n;
long long a[N],b[N],c[N],ss,s,s1,su,p3,r,q,e,f;
int main(){
	scanf("%d",&t);
	while(t--){
		
		s=q=e=f=0;
		scanf("%ld",&n);
		
	    for(long i=1;i<=n;i++){scanf("%lld",&a[i]);b[i]=0;c[i]=0;}
		sort(a+1,a+n+1);
		for(long i=1;i<=n;i++){
			if(a[i]<=n){
				c[a[i]]++;
				
			}else break;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
					if(i*j>n)break;
					b[i*j]+=c[i];
				}
		}
		for(long i=1;i<=n;i++)
			if(s<b[i]){s=b[i];}
		printf("%lld\n",s);
	}
	return 0;
}