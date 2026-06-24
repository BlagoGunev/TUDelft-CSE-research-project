#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,resa,resb,usea,useb;
long long a[200005],b[200005],ans;
long long getlena(int idx){
	return a[n-idx+1]-a[idx];
}
long long getlenb(int idx){
	return b[m-idx+1]-b[idx];
}
int main(){
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		k=min((n+m)/3,min(n,m));
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
		sort(a+1,a+1+n),sort(b+1,b+1+m);
		printf("%d\n",k);
		resa=n,resb=m,usea=useb=0,ans=0;
		for(int i=1;i<=k;i++){
			if(!resa){
				ans=ans-getlena(usea)+getlenb(useb+1)+getlenb(useb+2);
				usea--,useb+=2,resb-=3;
			}
			else if(!resb){
				ans=ans-getlenb(useb)+getlena(usea+1)+getlena(usea+2);
				useb--,usea+=2,resa-=3;
			}
			else if(resa>1&&(resb<2||getlena(usea+1)>getlenb(useb+1))){
				ans+=getlena(usea+1),usea++,resa-=2,resb--;
			}
			else{
				ans+=getlenb(useb+1),useb++,resb-=2,resa--;
			}
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}