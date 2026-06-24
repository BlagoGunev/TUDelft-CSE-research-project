#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct node{
	int num,no;
}a[maxn];
bool cmp1(node x,node y){
	if(x.num==y.num) return x.no<y.no;
	return x.num>y.num;
	
}
bool cmp2(node x,node y){
	return x.no<y.no;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].num);
		a[i].no=i;
	}
	sort(a,a+n,cmp1);
	int m;
	scanf("%d",&m);
	while(m--){
		sort(a,a+n,cmp1);
		int k,pos;
		scanf("%d%d",&k,&pos);
		sort(a,a+k,cmp2);
		printf("%d\n",a[pos-1]);
	}
}