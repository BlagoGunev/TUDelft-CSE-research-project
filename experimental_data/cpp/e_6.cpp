#include <stdio.h>

#include <stdlib.h>

#include <math.h>  

#include <string.h>  

#include <iomanip>  

#include <iostream>

#include <map>

#include <queue>

#include <stack>

#include <vector>

#include <algorithm>  

using namespace std;



typedef long long ll;

typedef long long LL;



const int maxn = (1e5)+9;





//max min heap, double pointer

struct node

{

	int l,v;

	node (int a,int b){

		l=a,v=b;

	}

	bool operator < (const node &a)const{

		return v < a.v;

	}

	bool operator > (const node &a)const{

		return v > a.v;

	}

};



priority_queue <node> p;

priority_queue < node,vector<node>,greater<node> > t;



void getnext(int l){

	while((p.top()).l < l){

		p.pop();

	}

	while((t.top()).l < l){

		t.pop();

	}

}



int h[maxn];

int lans[maxn];

int rans[maxn];

int main(){

	//freopen("1.txt","r",stdin);

	int n,k;

	scanf("%d%d",&n,&k);

	int i;

	for(i=1;i<=n;i++){

		scanf("%d",h+i);

	}

	int ans=0,cnt=0;

	int l=1,r=0;

	while(r<n){

		r++;

		p.push(node(r,h[r]));

		t.push(node(r,h[r]));

		getnext(l);

		while((p.top()).v-(t.top()).v > k){

			l++;

			getnext(l);

		}

		if(r-l+1>ans){

			ans = r-l+1;

			cnt=1;

			lans[0] = l;

			rans[0] = r;

		}else if(r-l+1 == ans){

			lans[cnt] = l;

			rans[cnt] =r;

			cnt++;

		}

	}

	printf("%d %d\n",ans,cnt);

	for(i=0;i<cnt;i++){

		printf("%d %d\n",lans[i],rans[i]);

	}

	return 0;

}