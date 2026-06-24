#include<bits/stdc++.h>
char s[100007],s1[17];
int*bit[13][13][4];
int tr[256],ls[13];
void ins(int*f,int mx,int w,int x){
	for(++w;w<=mx;w+=w&-w)f[w]+=x;
}
void ins(int w,int u,int x){
	for(int i=1;i<=10;++i)ins(bit[i][w%i][u],ls[i],w/i,x);
}
int sum(int*f,int w){
	int s=0;
	for(++w;w>0;w-=w&-w)s+=f[w];
	return s;
}
int sum(int l,int r,int d,int u){
	if(l>r)return 0;
	r=l+(r-l)/d*d;
	return sum(bit[d][r%d][u],r/d)-sum(bit[d][l%d][u],l/d-1);
}
int main(){
	tr['A']=0;
	tr['T']=1;
	tr['G']=2;
	tr['C']=3;
	scanf("%s",s+1);
	int len=strlen(s+1),q,op,l,r;
	for(int i=1;i<=10;++i){
		ls[i]=(len+1000)/i;
		for(int j=0;j<i;++j){
			for(int k=0;k<4;++k){
				memset(bit[i][j][k]=new int[ls[i]],0,sizeof(int)*ls[i]);
			}
		}
	}
	for(int i=1;i<=len;++i)ins(i,tr[s[i]],1);
	for(scanf("%d",&q);q;--q){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%s",&l,s1);
			ins(l,tr[s[l]],-1);
			ins(l,tr[s[l]=s1[0]],1);
		}else{
			scanf("%d%d%s",&l,&r,s1);
			int L=strlen(s1),ans=0;
			for(int i=0;i<L;++i){
				ans+=sum(l+i,r,L,tr[s1[i]]);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}