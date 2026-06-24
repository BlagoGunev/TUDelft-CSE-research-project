#include<bits/stdc++.h>

using namespace std;

typedef long long L;

typedef pair<int,int> P;

const int N=2e5+2;

int a[N];

void so()

{

	L s=0,x;

	unordered_map<int,int>m;

	int n;cin>>n;

	for(int i=0;i<n;i++) cin>>a[i],s+=a[i],m[a[i]]++;

	

	if(2*s%n!=0) {cout<<"0"<<'\n';return;}

	L d=0;x=2*s/n;

	for(int i=0;i<n;i++)

	{

		int b=x-a[i];

		if(m.count(b)) d+=m[b];

		if(b==a[i]) d--;

	}

	cout<<d/2<<'\n';

}

int main()

{

	ios::sync_with_stdio(0);

	cin.tie(0);cout.tie(0);

	int q=1;

	cin>>q;

	while(q--) so();

	return 0;

}