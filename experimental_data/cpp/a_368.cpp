#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;
int main(){
	int n,d;
	int A[102];
	int m;
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>A[i];
	cin>>m;
	long long ans=0;
	sort(A,A+n);
	int k=min(n,m);
	for(int i=0;i<k;i++){
		ans+=A[i];
	}
	if(m-n>0)
		ans-=d*(m-n);
	cout<<ans<<endl;
	return 0;
}