#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 300005
using namespace std;
int n,K,a[N],b[N],cnt1,cnt2;
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		if((long long)(b[i]+1)*K<cnt1+a[i]){
			puts("NO");return 0;
		}
		if((long long)(a[i]+1)*K<cnt2+b[i]){
			puts("NO");return 0;
		}
		if((long long)b[i]*K<cnt1+a[i]){
			cnt1=cnt1+a[i]-(long long)b[i]*K;
			cnt2=0;
		}
		else if((long long)a[i]*K<cnt2+b[i]){
			cnt2=cnt2+b[i]-(long long)a[i]*K;
			cnt1=0;
		}
		else{
			cnt1=cnt2=0;
		}
	}
	puts("YES");
	return 0;
}