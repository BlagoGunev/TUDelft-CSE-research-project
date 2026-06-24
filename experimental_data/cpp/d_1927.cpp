#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int T,n,Q,a[maxn];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		map<int,int> S;//l->r
		for(int i=1;i<=n;i++)
			cin>>a[i];
		
		S[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				(*S.rbegin()).second=i-1;
				S[i]=i;
			}
		}
		(*S.rbegin()).second=n;
		cin>>Q;
		while(Q--){
			int l,r;
			cin>>l>>r;
			auto it1=S.upper_bound(l),it2=S.upper_bound(r);
			it1--;it2--;
			if(it1==it2)puts("-1 -1");
			else {
				it1++;
				printf("%d %d\n",l,(*it1).first);
			}
		}
	}
	return 0;
}