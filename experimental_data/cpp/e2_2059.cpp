#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
const int N=600005,inf=1e9;
struct node{int to,next,v;}w[N<<1];
vector<int>a[N],b[N],F[N];
int n,m,T,val[N],Is[N],stk[N],tp[N];
int Id(int I,int J){return m*(I-1)+J;}
map<int,int>mp;
struct Tree{int l,r,add,min;}tree[N<<1];
void Ph(int k){tree[k].min=min(tree[k<<1].min,tree[k<<1|1].min);}
void Pt(int k,int u){tree[k].add+=u;tree[k].min+=u;}
void Pd(int k){if(tree[k].add)Pt(k<<1,tree[k].add),Pt(k<<1|1,tree[k].add),tree[k].add=0;}
void Build(int k,int l,int r){
	tree[k].l=l,tree[k].r=r;int mid((l+r)>>1);
	tree[k].min=tree[k].add=0;
	if(l==r){tree[k].min=val[l];return;}
	Build(k<<1,l,mid),Build(k<<1|1,mid+1,r);Ph(k);
}
int Fnd(int k){
	if(tree[k].l==tree[k].r)return tree[k].l;
	Pd(k);
	if(tree[k<<1|1].min==0)return Fnd(k<<1|1);
	else return Fnd(k<<1);
}
void Addrg(int k,int l,int r,int u){
	if(l>r||l>tree[k].r||r<tree[k].l)return;
	if(l<=tree[k].l&&tree[k].r<=r){Pt(k,u);return;}
	Pd(k);Addrg(k<<1,l,r,u),Addrg(k<<1|1,l,r,u);Ph(k);
}
int main(){
	int i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);mp.clear();
		for(i=0;i<=2*n*m;i++)Is[i]=0;
		for(i=1;i<=n;i++){
			a[i].clear();a[i].push_back(0);
			for(j=1;j<=m;j++)
			scanf("%d",&x),a[i].push_back(x);
		}
		for(i=1;i<=n;i++){
			b[i].clear();b[i].push_back(0);
			for(j=1;j<=m;j++)
			scanf("%d",&x),b[i].push_back(x),mp[x]=Id(i,j);
		}
		int lst=0,flg=0,ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(!mp.count(a[i][j])){flg=1;break;}
				int pos=mp[a[i][j]];
				if(pos<=lst){flg=1;break;}
				if(pos==lst+1){lst=pos;}
				else{
					if(j==1)lst=pos;
					else{
						if(lst<i*m){flg=1;break;}
						else lst=pos;
					}
				}
			}
			if(flg)break;
		}
		if(!flg)ans=n*m;
		else{
			int I=i,J=j;
			if(J==1)ans=Id(I,J)-1;
			else{
				int dis=mp[a[I][1]]-Id(I,1);
				if(m-J+1<=dis)ans=Id(I,J)-1;
				else ans=Id(I,1)-1;
			}
		}
		printf("%d\n",n*m-ans);
		int pos=1,now=0;Is[0]=1;stk[0]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(pos<=ans)Is[a[i][j]]=i+1,val[pos]=m-j;
				pos++;
			}
		}
		for(i=0;i<=ans;i++)tp[i]=0,F[i].clear();
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(Is[b[i][j]]){
					now++;stk[now]=b[i][j];
				}
				else F[now].push_back(b[i][j]);
			}
		}
	//	printf("%d %d\n",now,ans);
		Build(1,0,ans);int tot=ans;
		for(i=0;i<=ans;i++){
	//		printf("%d,%d:",stk[i],val[i]);
			int ln=F[i].size()-1;
			reverse(F[i].begin(),F[i].end());
	//		for(int u:F[i])printf("%d ",u);
	//		putchar('\n');
		}
		while(tot!=n*m){
			int it=Fnd(1);
			if(tp[it]==F[it].size())Addrg(1,it,it,inf);
			else{
				printf("%d %d\n",Is[stk[it]],F[it][tp[it]]);
				tp[it]++;Addrg(1,it+1,ans,-1);tot++;
			}
		}
	}
}