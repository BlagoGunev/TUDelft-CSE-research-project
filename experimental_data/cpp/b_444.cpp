#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int N=100010;
inline int lowbit(int k){ return k&(-k); }
LL x;
int n,d;
LL getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
int a[N],b[N],p[N],ans[N],k[N],c[N],D[N]; // a,b, p:λ�� d: 1��ǰ׺�ͣ� c: ��״����ǰ׺�� k 1��λ�� 
int fa[N]; 
void initAB()
{
	int i;
	cin>>n>>d>>x;
	for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
inline void add(int x,int d){
	for (int i=x;i<=n;i+=lowbit(i)) c[i]+=d;
}
inline int sum(int x){
	int ans=0;
	for (int i=x;i;i-=lowbit(i)) ans+=c[i];
	return ans;
}
int find(int i){
	if (fa[i]==i) return i;
	fa[i]=find(fa[i]);
	return fa[i];
}
void init() 
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	initAB();
	int now=0;
	for (int i=0;i<=n;i++){
		p[a[i]]=i;
		fa[i]=i;
		if (b[i]) k[++now]=i;
		add(i+1,1);
		if (i) D[i]=D[i-1]+b[i];
		else D[i]=b[i];
	}
}
void work()
{
	for (int i=n;i;i--){
		int now=p[i];
		if (D[n-i]>sum(n)-sum(now)){
			for (int x=find(now);x<n;x=find(x+1)){
				if (b[x-now]){
					ans[x]=i;
					fa[x]=x+1;
					add(x+1,-1);
				}
			}
		}else{
			for (int j=1;j<=d && k[j]+now<n;j++){
				int t=k[j]+now;
				if (ans[t]==0){
					ans[t]=i;
					fa[t]=t+1;
					add(t+1,-1);
				}
			}
		}
	}
	for (int i=0;i<n;i++)
		printf("%d\n",ans[i]);
}
int main()
{
	init();
	work();
}