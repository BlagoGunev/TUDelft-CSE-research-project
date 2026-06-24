#include <iostream>

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <map>

#include <algorithm>

#include <string>

using namespace std;

typedef long long LL;

const int maxn=100005;

int f,n,a,b,set[maxn],x,v,y;

struct no{

	int v,d;

	bool operator<(no a)const{

		return v<a.v;

	}

}num[maxn];

int find(int x){

	int l,r,mid;

	l=1,r=n+1;

	while(r-l>1){

		mid=r+l>>1;

		if(num[mid].v>x)r=mid;

		else l=mid;

	}

	if(num[l].v!=x)return 0;

	return l;

}

bool dfs(int x)

{

      if (!x) return false;

      if (set[num[x].d]) return true;

      set[num[x].d]=1;   

      if (find(a-num[x].v))

        if (!dfs(find(a-num[x].v))) return false;

      if (!dfs(find(b-num[x].v))) return false;

      return true;

}

bool bb(int ab){

	if(ab==0)return false;

	if(set[num[ab].d])return true;

	set[num[ab].d]=1;

	if(find(a-num[ab].v)){

		if(!bb(find(a-num[ab].v)))return false;

	}

	if(!find(b-num[ab].v))return false;

	return true;

}

int main(){

	memset(set,0,sizeof(set));

	scanf("%d%d%d",&n,&a,&b);

	for(int i=1;i<=n;i++){

		scanf("%d",&num[i].v);

		num[i].d=i;

	}

	sort(num+1,num+n+1);

	f=1;

	for(int i=1;i<=n;i++){

		if(find(a-num[i].v))continue;

		if(!dfs(i)){

			f=0;

			break;

		}

	}

	if(f){

		printf("YES\n");

		printf("%d",set[1]);

		for(int i=2;i<=n;i++)printf(" %d",set[i]);

		printf("\n");

	}

	else printf("NO\n");

	return 0;

}