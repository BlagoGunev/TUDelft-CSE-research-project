#include <bits/stdc++.h>
using namespace std;
const int maxn=200007;
int a[200007];
int lgao[maxn],ldi[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int pos=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==m) pos=i;
	}
	long long ans=0;
	int cnt=0;
	for(int i=pos;i>=1;i--){
		if(a[i]<m) cnt--;
		else if(a[i]>m)cnt++;
		if(cnt>0) lgao[cnt]++;
		else if(cnt<0) ldi[-cnt]++;
		else lgao[0]++,ldi[0]++;
	}
	cnt=0;
	for(int i=pos;i<=n;i++){
		if(a[i]<m) cnt--;
		else if(a[i]>m)cnt++;
		if(cnt>0){
			ans+=ldi[cnt];
			ans+=ldi[cnt-1];
		}
		else if(cnt<0) ans+=lgao[-cnt],ans+=lgao[-cnt+1];
		else{
			ans+=lgao[0];
			ans+=lgao[1];
		}
	}
	cout<<ans<<endl;
	return 0;
}