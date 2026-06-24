#include<iostream>
#include<cassert>
using namespace std;
int N;
int A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(i+1<N)ans=max(ans,min(A[i],A[i+1]));
			if(i+2<N)ans=max(ans,min(A[i],A[i+2]));
		}
		cout<<ans<<"\n";
	}
}