#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
//    tc=1;
    cin>>tc;
    while(tc--)
    {
		int n;
		cin>>n;
		int b[2*n];
		for(int i=0;i<2*n;i++)
		cin>>b[i];
		sort(b,b+2*n);
		for(int i=0;i<n;i++)
		cout<<b[i]<<" "<<b[2*n-i-1]<<" ";
		cout<<endl;        
    }
	return 0;
}