#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int a[200],b[200];
int main()
{
    int t;
    cin>>t;
    while(t--){
	    int n,m,k;
	    cin>>n>>m>>k;
	    int sum=0;
	    for(int i=1;i<=n;i++) cin>>a[i];
	    for(int i=1;i<=m;i++) cin>>b[i];
	    sort(a+1,a+1+n);
	    sort(b+1,b+1+m);
	    for(int i=1;i<=n;i++){
	    	if(a[i]>k) break;
	    	for(int j=1;j<=m;j++){
	    		if(b[j]>k) break;
	    		if(a[i]+b[j]<=k) sum++;
	    		else break;
			}
		}
		cout<<sum<<endl;
	}
    return 0;
}