#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
	ll ar[4];
	for(int i=0;i<4;i++)
	{
		cin>>ar[i];
	}
	sort(ar,ar+4);
	cout<<ar[3]-ar[0]<<" "<<ar[3]-ar[1]<<" "<<ar[3]-ar[2];
	return 0;
}