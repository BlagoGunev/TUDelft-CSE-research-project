#include <bits/stdc++.h>
using namespace std;
int n;
char s[200050];
int a[1000],b[1000];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
	scanf("%d%s",&n,s+1);a[0]=0;
	for(int i=1;i<=n;i++)
		if(n%i==0){
			a[++a[0]]=i;
			bool f=true;
			for(int j=1;j<=i;j++){
				int term=j,cnt=0;
				while(term<=n){
					if(s[term]=='1') cnt++;
					term+=i;
				}
				if(cnt&1) {f=false;break;}
			}
			b[a[0]]=f;
		}
	//for(int i=1;i<=a[0];i++) cout<<a[i]<<" "<<b[i]<<endl;
	int ans=0;
	for(int i=0;i<n;i++){
		int j=gcd(i,n);
		int c=lower_bound(a+1,a+a[0]+1,j)-a;
		if(b[c]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}