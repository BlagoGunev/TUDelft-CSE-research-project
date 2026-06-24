#include<stdio.h>
#define N 200007
#define ll long long

inline int read(){
	int x=0,flag=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') flag=0;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-48;c=getchar();}
	return flag? x:-x;
}

int T,n,m,a[N],top,pos[N];
ll sta[N];

int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		ll now=0; top=0;
		for(int i=1;i<=n;i++){
			a[i]=read(),now+=a[i];
			if(sta[top]<now) sta[++top]=now,pos[top]=i;
		}
		if(now<=0){
			for(int i=1;i<=m;i++){
				int x=read();
				if(x>sta[top]) printf("-1 ");
				else{
					int l=1,r=top,ret=top;
					while(l<=r){
						int mid=(l+r)>>1;
						if(sta[mid]>=x) r=mid-1,ret=mid;
						else l=mid+1;
					}
					printf("%d ",pos[ret]-1);
				}
			}
			putchar('\n');
		}else{
			for(int i=1;i<=m;i++){
				int x=read();
				ll tmp=x>sta[top]? (x-sta[top]-1)/now+1:0;
				ll ans=1ll*n*tmp;
				x-=tmp*now;
				int l=1,r=top,ret=top;
				while(l<=r){
					int mid=(l+r)>>1;
					if(sta[mid]>=x) r=mid-1,ret=mid;
					else l=mid+1;
				}
				printf("%lld ",ans+pos[ret]-1);
			}
			putchar('\n');
		}
	}
}