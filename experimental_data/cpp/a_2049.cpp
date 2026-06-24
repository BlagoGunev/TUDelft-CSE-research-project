#include<bits/stdc++.h>
using namespace std;
int t,n,a[55]; 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int cnt=0;
		for(int i=1,j=1;i<=n;i=++j)if(a[i]){
			while(j<n && a[j+1])j++;
			cnt++;
		}
		printf("%d\n",min(cnt,2));
	}
}