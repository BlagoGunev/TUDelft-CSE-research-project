#include<cstdio>

#include<cctype>

#include<cstdlib>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<set>

#include<map>

#include<queue>

#include<vector>

#include<string>

#define ll long long

#define mp make_pair

#define pii pair<int,int>

#define siz(x) ((x).size())

using namespace std;

inline void Rd(int &res){

	char c;res=0;

	while(c=getchar(),c<'0');

	do{

		res=(res<<1)+(res<<3)+(c^48);

	}while(c=getchar(),c>='0');

}

double solve1(int a,int b){

	int k=(a-b)/(2*b);

	if(k==0)return -1;

	double rs=(double)(a-b)/(2*k);

	if(rs<0)return -1;

	return rs;

}

double solve2(int a,int b){

	int k=(a+b)/(2*b);

	if(k==0)return -1;

	double rs=(double)(a+b)/(2*k);

	if(rs<0)return -1;

	return rs;

}

int main(){

	int a,b;

	double ans=-1;

	scanf("%d %d",&a,&b);

	if(a==b){

		printf("%.12f\n",(double)a);

		return 0;

	}

	if(b>a){

		puts("-1");

		return 0;

	}

	double ans1=solve1(a,b);

	if(ans1!=-1)ans=ans1;

	double ans2=solve2(a,b);

	if(ans2!=-1){

		if(ans==-1||ans2<ans)ans=ans2;

	}

	if(ans!=-1)printf("%.12f\n",ans);

	else puts("-1");

	return 0;

}