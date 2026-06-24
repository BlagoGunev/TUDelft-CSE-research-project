#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=l;i<=r;i++)
#define D(i,l,r) for(int i=l;i>=r;i--)
namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,c;int f;
	char gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++; 
		}
		return*iS++;
	}
	template<class I>void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
};
using io::gi;
using io::gc;
const int N=300050;
int n,lx,rx;
struct node{
	int a,id;
	bool operator <(const node &cmp)const{
		return a<cmp.a;
	}
}p[N];
int AA[N],Ca[N];
int main(){
	gi(n);gi(lx);gi(rx);
	for(int i=1;i<=n;i++){
		gi(p[i].a);p[i].id=i;
	}
	sort(p+1,p+n+1);
	int cc=0;
	for(int i=n;i>=1;i--)if(cc==0){
    	if(p[i].a>=(rx+n-i+1-1)/(n-i+1)){
     		AA[i]=1;cc=1;Ca[i]=i;
     	}
	}
	else Ca[i]=Ca[i+1],AA[i]=1;
	
	for(int i=1;i<=n;i++){
		int as=(lx+i-1)/i;
		int A=lower_bound(p+1,p+n+1,(node){as,0})-p;
		if(A==n+1||A+i-1>=n)continue;
		if(AA[A+i]==1){
			printf("Yes\n");
			printf("%d %d\n",i,n-Ca[A+i]+1);
			for(int j=A;j<=A+i-1;j++)printf("%d ",p[j].id);printf("\n");
			for(int j=Ca[A+i];j<=n;j++)printf("%d ",p[j].id);printf("\n");
			return 0;
		}
	}
	
	memset(AA,0,sizeof(AA));
	memset(Ca,0,sizeof(Ca));
	cc=0;
	for(int i=n;i>=1;i--)if(cc==0){
    	if(p[i].a>=(lx+n-i+1-1)/(n-i+1)){
     		AA[i]=1;cc=1;Ca[i]=i;
     	}
	}
	else Ca[i]=Ca[i+1],AA[i]=1;
	
	for(int i=1;i<=n;i++){
		int as=(rx+i-1)/i;
		int A=lower_bound(p+1,p+n+1,(node){as,0})-p;
		if(A==n+1||A+i-1>=n)continue;
		if(AA[A+i]==1){
			printf("Yes\n");
			printf("%d %d\n",n-Ca[A+i]+1,i);
			for(int j=Ca[A+i];j<=n;j++)printf("%d ",p[j].id);printf("\n");
			for(int j=A;j<=A+i-1;j++)printf("%d ",p[j].id);printf("\n");
			return 0;
		}
	}
	printf("No");
	return 0;
}