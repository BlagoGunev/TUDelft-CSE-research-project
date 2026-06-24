#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
typedef int i32;
typedef long double ld;
void like(void)
{
	i64 x,y;
	cin>>x>>y;
	if(y<x*2)
	cout<<"-1 -1"<<endl;
	else
	cout<<x<<' '<<x*2<<endl; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
   		like();
	return 0;
}