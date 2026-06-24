#include<cstdio>

#include<algorithm>

#include<cstring>

#include<cctype>

#include<vector>

#include<map>

#include<ctime>

#include<iostream>

using namespace std;



inline int read(){

	int x=0; char c=getchar();

	while(!isdigit(c)) c=getchar();

	while(isdigit(c)) x=x*10+(c^'0'),c=getchar();

	return x;

}



const int inf=0x3f3f3f3f;



int n,q,m,c[1510][1510],b[2250010];

pair<short,int> up[1510][1510][11],lft[1510][1510][11];

bool v[2250010];

int ans[1510];





inline void calc(int x,int y){

	vector<pair<short,int> > f;

	while(x<=n&&y<=n){

		for(auto &t: f) if(t.second<inf) t.first++;

		for(int t=0;t<11;t++) if(up[x][y][t].second) f.push_back(up[x][y][t]);

			for(int t=0;t<11;t++) if(lft[x][y][t].second) f.push_back(lft[x][y][t]);

//		for(auto t: lft[x][y]) f.push_back(t);

		sort(f.begin(),f.end());

		int k=0;

		for(auto t: f){

			if(t.second<inf&&!v[t.second]){

				f[k++]=t,v[t.second]=true;

			}

		}

		f.resize(k);

		for(auto t: f)

			if(t.second<inf) v[t.second]=false;

		while(f.size()<11) f.push_back(make_pair(inf,inf));

		f.resize(11);

//			printf("(%d, %d)\n",x,y);

//			for(auto t: f){

//				printf("<%d, %d>\n",t.first,t.second);

//			}

//			puts("----------");

		int l=min(x,y);

		if(f[q].second) l=min(l,(int)f[q].first);

//			printf("l[%d][%d] = %d\n",i,j,l);

		ans[1]++,ans[l+1]--;

		x++;

		y++;

	}

}



int main(){

//	freopen("1.in","r",stdin);

//	freopen("1.out","w",stdout);

	

	double st=clock();

	

	n=read(),q=read();

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++){

			c[i][j]=read();

			b[++m]=c[i][j];

		}

	sort(b+1,b+m+1);

	m=unique(b+1,b+m+1)-b-1;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++) c[i][j]=lower_bound(b+1,b+m+1,c[i][j])-b;

	

	for(int j=1;j<=n;j++)

		for(int i=1;i<=n;i++){

			for(int t=0;t<11;t++){

				up[i][j][t]=up[i-1][j][t];

			}

			for(int t=0;t<11;t++)

				if(up[i][j][t].second) up[i][j][t].first++;

//			puts("???");

//			bool flag=false;

			for(int k=0;k<11;k++){

				if(up[i][j][k].second==c[i][j]){

					for(int l=k;l<10;l++) up[i][j][l]=up[i][j][l+1];

					up[i][j][11]=make_pair(0,0);

//					flag=true;

					break;

				}

			}

			for(int t=10;t;t--) up[i][j][t]=up[i][j][t-1];

			up[i][j][0]=make_pair(0,c[i][j]);

			

//			printf("up[%d][%d]:\n",i,j);

//			for(int t=0;t<11;t++) printf("<%d, %d>\n",up[i][j][t].first,up[i][j][t].second);

		}

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++){

				for(int t=0;t<11;t++) lft[i][j][t]=lft[i][j-1][t];

			for(int t=0;t<11;t++)

				if(lft[i][j][t].second) lft[i][j][t].first++;

			

//			bool flag=false;

			for(int k=0;k<11;k++){

				if(lft[i][j][k].second==c[i][j]){

					for(int l=k;l<10;l++) lft[i][j][l]=lft[i][j][l+1];

					lft[i][j][11]=make_pair(0,0);

//					flag=true;

					break;

				}

			}

			for(int t=10;t;t--) lft[i][j][t]=lft[i][j][t-1];

			lft[i][j][0]=make_pair(0,c[i][j]);

//				printf("lft[%d][%d]:\n",i,j);

//			for(int t=0;t<11;t++) printf("<%d, %d>\n",lft[i][j][t].first,lft[i][j][t].second);

	

		}

	

	for(int i=1;i<=n;i++){

		calc(1,i);

//		cerr<<i<<endl;

	}

	for(int i=2;i<=n;i++){

		calc(i,1);

//		cerr<<i<<endl;

	}

	

//	for(int i=1;i<=n;i++){

//		for(int j=1;j<=n;j++){

//

//		}

//	}

//

	for(int i=1;i<=n;i++) ans[i]+=ans[i-1];

	for(int i=1;i<=n;i++)

		printf("%d\n",ans[i]);

	

// 	cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;

	

	return 0;

}

/*

7 10

10 1 2 2 7 11 4

8 8 13 9 7 7 10

5 6 5 10 6 3 6

10 13 5 7 5 3 3

12 1 3 9 12 3 5

1 2 11 9 7 9 2

13 8 13 10 3 11 1



*/