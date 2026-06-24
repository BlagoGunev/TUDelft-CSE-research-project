#include <stdio.h>

#include <string.h>

#include <string>

#include <iostream>

#include <algorithm>

#include <set>

#include <vector>

#include <queue>

#include <map>

#define fi first

#define se second

using namespace std;

typedef  long long ll;

typedef pair<int, int> PII;

const int inf = 0x7ffffff;



int fa[555555];

int lastnode;

double dp[555555][55];



void update(int u){

	int v=++lastnode;

	fa[v]=u;



	for(int i=0; i<55; i++) dp[v][i]=1.0;



	double chfrom,chto,fafrom,fato;



	chfrom=dp[u][0];

	dp[u][0]*=0.5;

	chto=dp[u][0];



	for (int i = 0; i < 50; ++i)

	{

		if(fa[u]==0) break;



		fafrom=dp[fa[u]][i+1];

		dp[fa[u]][i+1]*=(1+chto)/(1+chfrom);

		fato=dp[fa[u]][i+1];



		chfrom=fafrom;

		chto=fato;



		u=fa[u];

	}



}



void query(int u){

	double ans=0;

	for (int i = 1; i < 50; ++i)

	{

		ans+=i*(dp[u][i]-dp[u][i-1]);

	}

	printf("%.10f\n",ans);

}



int main() {

#ifndef ONLINE_JUDGE

    freopen("test.in", "r", stdin);

#endif



    lastnode=1;

    fa[1]=0;

    for(int i=0; i<55; i++) dp[1][i]=1.0;





    int n;

    scanf("%d",&n);

    for (int i = 0; i < n; ++i)

    {

    	int a,b;

    	scanf("%d%d",&a,&b);

    	if(a==1) update(b);

    	else query(b);

    }



    return 0;

}