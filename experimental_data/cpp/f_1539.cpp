#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

#define ll long long

#define ge getchar 

#define pun putchar('\n')

#define pu putchar

#define puk putchar(' ')

#define nn 200004

#define mm 1<<19

int n,a[nn],p[nn],an[nn];

int s[mm],ls[mm],rs[mm];

bool cc(int u,int v){

	return a[u]<a[v];

}

inline void imax(int&a,int b){a=max(a,b);};

void bu(int l=1,int r=n,int t=1){

	if(l==r){

		s[t]=-1;

		ls[t]=rs[t]=0;

	}else{

		int m=l+r>>1;

		bu(l,m,t<<1);bu(m+1,r,t<<1|1);

		s[t]=s[t<<1]+s[t<<1|1];

		ls[t]=rs[t]=0;

	}

}

void add(int i,int l=1,int r=n,int t=1){

	if(l==r){

		s[t]+=2;

		ls[t]=rs[t]=max(0,s[t]);

	}else{

		int m=l+r>>1;

		if(i<=m)add(i,l,m,t<<1);else add(i,m+1,r,t<<1|1);

		s[t]+=2;

		ls[t]=max(ls[t<<1],s[t<<1]+ls[t<<1|1]);

		rs[t]=max(rs[t<<1|1],s[t<<1|1]+rs[t<<1]);

	}

}

int qq(int i,int lx=0,int rx=0,int l=1,int r=n,int t=1){

	if(l==r){

		return lx+rx;

	}

	int m=l+r>>1,lt=t<<1,rt=t<<1|1;

	if(i<=m){

		rx=max(s[rt]+rx,ls[rt]);

		return qq(i,lx,rx,l,m,lt);

	}else{	

		lx=max(s[lt]+lx,rs[lt]);

		return qq(i,lx,rx,m+1,r,rt);

	}

}

int main(){

	//freopen("1.in","r",stdin);

	//freopen("1.out","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=i;

	sort(p+1,p+n+1,cc);

	bu();

	int i=1;

	while(i<=n){

		int ai=a[p[i]];

		int j=i-1;

		while(j<n&&a[p[j+1]]==ai)j++,add(p[j]);

		for(int k=i;k<=j;k++){

			an[p[k]]=qq(p[k])/2;

		}		

		i=j+1;

	}

	bu();

	i=n;

	while(i>=1){

		int ai=a[p[i]];

		int j=i+1;

		while(j>1&&a[p[j-1]]==ai)j--,add(p[j]);

		for(int k=j;k<=i;k++){

			imax(an[p[k]],(qq(p[k])+1)/2);

		}		

		i=j-1;

	}

	for(int i=1;i<=n;i++)printf("%d ",an[i]);pun;

    return 0;

}