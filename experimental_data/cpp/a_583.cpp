#include <iostream>

using namespace std;



int h[52], v[52];

int n,m;



int main()

{

	int i,x,y;

	cin>>n;

	m = n*n;

	for(i=1; i<=m; i++){

		cin>>x>>y;

		if(!h[x] && !v[y]){

			cout<<i<<' ';

			h[x]=1;

			v[y]=1;

		}

	}

	return 0;

}