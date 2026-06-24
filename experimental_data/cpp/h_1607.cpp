#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
struct node{
	int a,b,m,l,r,s,id;
}a[MAXN];
bool operator <(node a,node b){
	if(a.s!=b.s) return a.s<b.s;
	return a.r<b.r;
}
int x[MAXN],y[MAXN],ans;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].m);
			a[i].l=max(0,a[i].a-a[i].m);
			a[i].r=min(a[i].a,a[i].a-a[i].m+a[i].b);
			a[i].s=a[i].a+a[i].b-a[i].m;
			y[i]=a[i].m;
			a[i].id=i;
		}
		sort(a+1,a+n+1);
		ans=0;
		for(int i=1,j; i<=n; i++){
			if(i==1||a[i].s!=a[i-1].s||a[i].l>j){
				j=a[i].r;
				ans++;
			}
			x[a[i].id]=a[i].a-j;
		}
		printf("%d\n",ans);
		for(int i=1; i<=n; i++)
			printf("%d %d\n",x[i],y[i]-x[i]);
	}
	return 0;
}