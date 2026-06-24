#include<iostream>

#include<cstdio>

#include<cstring>

#include<vector>

using namespace std;

#define pb push_back



const int N=1e5+7;

int a[N],n,x,y,l;



vector<int> check(int x){

	vector<int> ans(0);

	int r=1;

	for(int l=1;l<=n&&r<=n;l++){

		while(r<=n&&a[r]-a[l]<x) ++r;

		if(r>n) break;

		if(a[r]-a[l]==x) ans.pb(l);

	}

	return ans;

}



int main(){

	scanf("%d%d%d%d",&n,&l,&x,&y);

	for(int i=1;i<=n;i++) scanf("%d",a+i);

	if(!check(x).empty()){

		if(!check(y).empty()) puts("0");

		else printf("1\n%d\n",y);

	}else{

		if(!check(y).empty()) printf("1\n%d\n",x);

		else{

			vector<int> pos=check(y-x);

			for(int i=0;i<pos.size();i++){

				if(a[pos[i]]>=x){

					printf("1\n%d\n",a[pos[i]]-x);

					return 0;

				}

				if(a[pos[i]]+y<=l){

					printf("1\n%d\n",a[pos[i]]+y);

					return 0;

				}

			}

			pos=check(x+y);

			for(int i=0;i<pos.size();i++){

				printf("1\n%d\n",a[pos[i]]+x);

				return 0;

			}

			printf("2\n%d %d\n",x,y);

		}

	}

	return 0;

}