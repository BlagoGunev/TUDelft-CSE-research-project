#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=200200;

int T,n;
char s[maxn];

bool chk(int p){
	int f=0;
	for (int i=p;i<n;i++){
		if (s[i]!=s[i%p]) f++;
	}
	if (f<=1) return true;
	f=0;
	for (int i=0;i<n;i++){
		if (i>=p && i<p*2) continue;
		if (s[i]!=s[i%p+p]) f++;
	}
	if (f<=1) return true;
	else return false;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%s",s);
		int ans=n;
		for (int i=1;i*i<=n;i++){
			if (n%i!=0) continue;
			if (chk(i)) ans=min(ans,i);
			if (chk(n/i)) ans=min(ans,n/i);
		}
		printf("%d\n",ans);
	}
	return 0;
}