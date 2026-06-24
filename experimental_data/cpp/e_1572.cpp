#include<bits/stdc++.h>

using namespace std;

const int N=2e2+5;

int n,k;

struct Point{long long x,y;}a[N];

pair<int,long long> f[N][N];

long long cal(Point a,Point b,Point c){

	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);

}

int check(long long k){

	for(int len=3;len<=n;++len){

		for(int i=1,j=len;j<=n;++i,++j){

			f[i][j]=make_pair(0,0);

			for(int c=i+1;c<j;++c){

				pair<int,long long> tmp;

				tmp.first=f[i][c].first+f[c][j].first;

				tmp.second=f[i][c].second+f[c][j].second+cal(a[i],a[c],a[j]);

				if(tmp.second>=k) tmp.first++,tmp.second=0;

				f[i][j]=max(f[i][j],tmp);

			}

		}

	}

	return f[1][n].first;

}

int main(){

	cin>>n>>k;

	for(int i=1;i<=n;++i)

		scanf("%lld%lld",&a[i].x,&a[i].y);

	long long L=0,R=8e16,res=-1;

	while(L<=R){

		long long Mid=(L+R)>>1;

		

		if(check(Mid)>k) L=Mid+1,res=Mid;

		else R=Mid-1;

	}

	return printf("%lld\n",res),0;

}