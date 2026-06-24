#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

struct interval{
	int l,r,ord;
}num[200001];
bool cmp(const interval &a,const interval &b){return a.l<b.l||(a.l==b.l&&a.r<b.r);}
std::priority_queue<std::pair<int,int> >heap;
int n,ans[200001],ord[200001],a[200001],b[200001],chk[200001];
std::vector<int>vec[200001];
int c[200001];
void update(int ind,int num){
	if(!ind)return;
	for(;ind<=n;ind+=ind&-ind)c[ind]+=num;
}
int query(int ind){
	int tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i]=num[i].l=read(),b[i]=num[i].r=read(),num[i].ord=i;
	std::sort(num+1,num+n+1,cmp);
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<=n&&num[now].l<=i){
			heap.push(std::make_pair(-num[now].r,num[now].ord));
			++now;
		}
		ans[heap.top().second]=i;
		ord[i]=heap.top().second;
		heap.pop();
	}
//	return 0;
	for(int i=1;i<=n;i++)vec[b[ord[i]]].push_back(i);
	for(int i=1;i<=n;i++){
		update(a[ord[i]],1);
		update(b[ord[i]]+1,-1);
		for(int j=0;j<vec[i].size();j++)chk[vec[i][j]]+=query(vec[i][j]);
		chk[i]-=query(i);
	}
	for(int i=1;i<=n;i++){
//			printf("%d %d\n",i,ord[i]);
//			printf("%d %d\n",query(root[b[ord[i]]],1,n,i),query(root[i],1,n,i));
			if(chk[i]){
				for(int j=i+1;j<=b[ord[i]];j++)
					if(a[ord[j]]<=i&&b[ord[j]]>=i){
						puts("NO");
						for(int i=1;i<=n;i++)write(ans[i]),putchar(' ');putchar('\n');
						std::swap(ans[ord[i]],ans[ord[j]]);
						for(int i=1;i<=n;i++)write(ans[i]),putchar(' ');putchar('\n');
						return 0;
					}
				return 0;
			}
	}
	puts("YES");
						for(int i=1;i<=n;i++)write(ans[i]),putchar(' ');putchar('\n');
}