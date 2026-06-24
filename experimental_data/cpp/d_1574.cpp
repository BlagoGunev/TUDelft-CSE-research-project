#include<bits/stdc++.h>

#define pipii pair<int,pair<int,int> >

using namespace std;



int read() {

	char ch=getchar();

	int f=1,x=0;

	while(ch<'0'||ch>'9') {

		if(ch=='-')

			f=-1;

		ch=getchar();

	}

	while(ch>='0'&&ch<='9') {

		x=x*10+ch-'0';

		ch=getchar();

	}

	return f*x;

}



const int MAXN=2e5+10,b1=1e5+1,b2=3e5+3,m1=20060527,m2=21071179;



int n,m,cnt=1,num;

int tmp[11],a[11][MAXN],c[MAXN],ban[MAXN>>1][11];

map<pair<int,int>,bool> mp;



struct build {

	int ans,p[11];

	pair<int,int> hsh; 

}b[MAXN*5];



void inw() {

	int sum=0,h1=0,h2=0;

	num++;

	for(int i=1;i<=n;i++) {

		sum+=a[i][tmp[i]];

		b[num].p[i]=tmp[i];

		h1=(h1*b1%m1+tmp[i])%m1;

		h2=(h2*b2%m2+tmp[i])%m2;

	}

	b[num].ans=sum;

	b[num].hsh=make_pair(h1,h2);

}



bool cmp(build a,build b) {

	return a.ans>b.ans;

}



signed main() {

	cin>>n;

	for(int i=1;i<=n;i++) {

		tmp[i]=c[i]=read();

		

		for(int j=1;j<=c[i];j++) {

			a[i][j]=read();

		}

	}

	

	inw();

	

	cin>>m;

	for(int i=1;i<=m;i++) {

		int h1=0,h2=0;

		for(int j=1;j<=n;j++) {

			ban[i][j]=tmp[j]=read();

			h1=(h1*b1%m1+tmp[j])%m1;

			h2=(h2*b2%m2+tmp[j])%m2;

		}

		mp[make_pair(h1,h2)]=1;

	}

	

	for(int i=1;i<=m;i++) {

		for(int j=1;j<=n;j++) {

			tmp[j]=ban[i][j];

		}

		for(int j=1;j<=n;j++) {

			if(ban[i][j]==1) {

				continue;

			}

			tmp[j]--;

			inw();

			tmp[j]++;

		}

	}

	

	sort(b+1,b+num+1,cmp);

	

	for(int i=1;i<=num;i++) {

		if(!mp[b[i].hsh]) {

			for(int j=1;j<=n;j++) {

				cout<<b[i].p[j]<<" ";

			}

			puts("");

			return 0;

		}

	}

	return 0;

}