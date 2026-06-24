#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,r,t;
	cin>>n>>m>>r;
	int MAX=-1,MIN=0x3f3f3f3f;
	for(int i=0;i<n;++i)
		cin>>t,MIN=min(MIN,t);
	for(int j=0;j<m;++j)
		cin>>t,MAX=max(MAX,t);
	//cout<<MIN<<" "<<MAX<<endl;
	if(MIN>=MAX)
		cout<<r;
	else
		cout<<(r/MIN)*MAX+(r%MIN);
	return 0;
}