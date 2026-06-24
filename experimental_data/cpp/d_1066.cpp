#include <bits/stdc++.h>
using namespace std;

const int maxn=200010;
int arr[maxn];
int main(){
//freopen("input.txt","r",stdin);

	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}

	int curr_size=k;
	int curr_box=m-1;
	int tot=0;
	for(int i=n-1;i>=0;--i){
		while(curr_box>=0 && curr_size<arr[i]){
			curr_size=k;
			curr_box-=1;
		}
		if(curr_box<0)break;
		curr_size-=arr[i];
		++tot;
	}
	printf("%d\n",tot);
}