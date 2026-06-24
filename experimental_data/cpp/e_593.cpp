#include<bits/stdc++.h>

#define N 21

#define LL long long

//n^3m^3qlogt

using namespace std;

const int mod=1e9+7;const LL mod2=1LL*mod*mod;

int len;

int c[N][N],buf[N][N];

void mul(int a[N][N],int b[N][N]){

	for(int i=1;i<=len;i++){

		for(int j=1;j<=len;j++){

			long long t=0;

			for(int k=1;k<=len;k++){

				t+=(LL)(a[i][k])*b[k][j];

				if(t>=mod2) t-=mod2;

			}

			c[i][j]=t%mod;

		}

	}

	memcpy(b,c,sizeof(c));

}

void mul_2(int a[21][21],int b[21][21]){

	for(int i=1;i<=len;i++){

		long long t=0;

		for(int k=1;k<=len;k++){

			t+=(LL)(a[i][k])*b[k][1];

			if(t>mod2) t-=mod2;

		}

		c[i][1]=t%mod;

	}

	for(int i=1;i<=len;i++) b[i][1]=c[i][1];

}

int n,m,q;

inline int id(int r,int c){

	return (r-1)*m+c;

}

int mp[N][N];

int tra[N][N],base[N][N];

int out[N][N];

void fastpow_tra(int ti){

	while(ti){

		if(ti&1) mul_2(tra,out);

		mul(tra,tra);

		ti>>=1;

	}

}

int xx[5]={0,0,0,-1,1},yy[5]={0,1,-1,0,0};//yy

void make_matrix(){

	for(int i=1;i<=len;i++) base[i][i]=1;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			if(mp[i][j]==0)

			for(int t=1;t<=4;t++){

				int x1=i+xx[t],y1=j+yy[t];

				if(x1>=1&&x1<=n&&y1>=1&&y1<=m)

					base[id(i,j)][id(x1,y1)]=1;

			}

}

inline void update(int x,int y){

	for(int t=1;t<=4;t++){

		int x1=x+xx[t],y1=y+yy[t];

		if(x1>=1&&x1<=n&&y1>=1&&y1<=m)

			base[id(x,y)][id(x1,y1)]=base[id(x1,y1)][id(x,y)]=(mp[x1][y1]==0&&mp[x][y]==0);

	}

}

int main(){

	scanf("%d%d%d",&n,&m,&q);len=id(n,m);

	out[1][1]=1;

	make_matrix();

	for(int i=1,last=1;i<=q;i++){

		int ins,x,y,ti;

		scanf("%d%d%d%d",&ins,&x,&y,&ti);

		memcpy(tra,base,sizeof(tra));

		fastpow_tra(ti-last);

		if(ins==1){

			printf("%d\n",out[id(x,y)][1]);

		}else if(ins==2){

			mp[x][y]++;

			out[id(x,y)][1]=0;

			update(x,y);

		}else if(ins==3){

			mp[x][y]--;

			update(x,y);

		}

		last=ti;

	}

	return 0;

}