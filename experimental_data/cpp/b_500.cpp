#include <bits/stdc++.h>
#include<iostream>

#include<stdio.h>

#include<string.h>

#include<math.h>

#include<algorithm>

#include<stdlib.h>

#include<queue>

#include<stack>

#include<map>

#include<set>

#include<vector>

const double PI = acos(-1.0);

const double e = exp(1.0);

#define ll int64_t

template<class T> T gcd(T a, T b) {

	return b ? gcd(b, a % b) : a;

}

template<class T> T lcm(T a, T b) {

	return a / gcd(a, b) * b;

}

using namespace std;

const ll mod = 1e9 + 7;



int n,t;



int p[305];

char str[305][305];

int fa[305];

int find(int x){

//	printf("x=%d fa=%d\n",x,fa[x]);

	if(fa[x]!=x){

		 fa[x]=find(fa[x]);

	}

	return fa[x];

}

void to(int a,int b){



	if(find(a)!=find(b)){

//		printf("hehe %d %d=%d %d\n",a,b,fa[a],fa[b]);

		fa[find(b)]=find(a);

	}

}

int main() {

	//freopen("1.txt", "r", stdin);

	scanf("%d",&n);

    for(int i=1;i<=n;i++)

    	scanf("%d",&p[i]);

    for(int i=1;i<=n;i++)

    	fa[i]=i;

    for(int i=1;i<=n;i++){

    	scanf("%s",str[i]+1);

        for(int j=1;j<=n;j++)

        	if(str[i][j]=='1'){

        		to(i,j);

        	}

    }

    for(int i=1;i<=n;i++)

    	find(i);

    for(int i=1;i<=n;i++){

    	int a=p[i];

        int pos=i,minn=a+1;

    	for(int j=i+1;j<=n;j++){

    		if(p[j]<minn && fa[i]==fa[j]){

    			pos=j;

    			minn=p[j];

    		}

    	}

    	if(i==pos) continue;

    	swap(p[i],p[pos]);

    }

    for(int i=1;i<=n;i++)

    	printf("%d ",p[i]);

	return 0;

}