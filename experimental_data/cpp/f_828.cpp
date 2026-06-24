#include<bits/stdc++.h>
int as[500007];
int n,m,f[500007],h[500007],fe[500007];
int gf(int x){
	while(x!=f[x])x=f[x];
	return x;
}
struct E{
	int to,id;
	E(int a,int b):to(a),id(b){}
};
std::vector<E>es[500007];
struct edge{
	int a,b,c,id;
	bool operator<(const edge&w)const{return c<w.c;}
	void ae(){
		es[a].push_back(E(b,id));
		es[b].push_back(E(a,id));
	}
}e[500007];
void mins(int&a,int b){if(a>b)a=b;}
std::queue<int>q;
int fas[20][200007],dep[200007];
int fvs[20][200007];
void init(){
	memset(fvs,0x7f,sizeof(fvs));
	q.push(1);
	dep[1]=1;
	while(q.size()){
		int w=q.front();q.pop();
		for(int i=0;i<es[w].size();++i){
			int u=es[w][i].to;
			if(u==fas[0][w])continue;
			fas[0][u]=w;
			dep[u]=dep[w]+1;
			q.push(u);
		}
	}
	for(int i=1;i<20;++i){
		for(int w=1;w<=n;++w)fas[i][w]=fas[i-1][fas[i-1][w]];
	}
//	for(int w=1;w<=n;++w)printf("%d:%d %d\n",w,fas[0][w],fas[1][w]);
}
void chk(int a,int b,int c){
//	printf("(%d %d %d)\n",a,b,c);
	if(dep[a]<dep[b])std::swap(a,b);
	int d=dep[a]-dep[b];
	for(int i=0;d;++i,d>>=1)if(d&1){
		mins(fvs[i][a],c);
		a=fas[i][a];
	}
	if(a==b)return;
	for(int i=19;i>=0;--i)if(fas[i][a]!=fas[i][b]){
		mins(fvs[i][a],c);
		mins(fvs[i][b],c);
		a=fas[i][a];
		b=fas[i][b];
//	printf("%d(%d %d)\n",i,a,b);
	}
//	printf("(%d %d)\n",a,b);
	mins(fvs[0][a],c);
	mins(fvs[0][b],c);
}
void dns(){
	for(int i=18;i>=0;--i){
		for(int w=1;w<=n;++w){
			int f=fas[i][w];
			mins(fvs[i][w],fvs[i+1][w]);
			mins(fvs[i][f],fvs[i+1][w]);
		}
	}
	for(int w=1;w<=n;++w){
		for(int i=0;i<es[w].size();++i){
			int u=es[w][i].to;
			if(u==fas[0][w]&&fvs[0][w]<0x7f7f7f7f)as[es[w][i].id]=fvs[0][w]-1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		as[i]=-1;
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
		e[i].id=i;
	}
	std::sort(e+1,e+m+1);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int x=gf(e[i].a),y=gf(e[i].b);
		if(x==y){
			x=e[i].a,y=e[i].b;
			int mn=0;
			while(x!=y){
				if(h[x]>h[y])std::swap(x,y);
				if(fe[x]>mn)mn=fe[x];
				x=f[x];
			}
			as[e[i].id]=mn-1;
		}else{
			e[i].ae();
			if(h[x]<h[y])std::swap(x,y);
			if(h[x]==h[y])++h[x];
			fe[y]=e[i].c;
			f[y]=x;
		}
	}
	init();
	for(int i=1;i<=m;++i)if(as[e[i].id]>-1){
		chk(e[i].a,e[i].b,e[i].c);
	}
	dns();
	for(int i=1;i<=m;++i)printf("%d ",as[i]);
	return 0;
}