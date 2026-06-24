#include <iostream>

#include <algorithm>

using namespace std;

int main()

{

	int n,maxx=0,minn=10000;

	cin>>n;

	int a[100+20],b[100+20];

	for(int i=0;i<n;i++)

		cin>>a[i];

	for(int i=1;i<n;i++)

		maxx=max(maxx,a[i]-a[i-1]);

	for(int i=1;i<n-1;i++)

		minn=min(minn,max(a[i+1]-a[i-1],maxx));

	cout<<minn;

	return 0;

}