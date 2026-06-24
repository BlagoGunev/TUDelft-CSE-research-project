#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
typedef pair<int,int> PII;
typedef long long LL;
const int N=200010;
int n,y11,m,y2,a[N],b[N],c[N];
int main(){
	scanf("%d%d",&n,&y11);
	ref(i,1,n)scanf("%d",&a[i]);
	scanf("%d%d",&m,&y2);
	ref(i,1,m)scanf("%d",&b[i]);
	if(n==1&&m==1){
		cout<<2<<endl;
		return 0;
	}
	int nn=n+m;
	int res=0;
	for(int i=2;i<=1000000000;i<<=1){
		ref(j,n+1,nn)a[j]=b[j-n]+i/2;
		ref(j,1,nn)c[j]=a[j]%i;
		sort(c+1,c+nn+1);
		int last=1;
		ref(j,1,nn+1)if(j>nn||c[j]!=c[j-1])
			res=max(res,j-last),last=j;
	}
	cout<<res<<endl;
}