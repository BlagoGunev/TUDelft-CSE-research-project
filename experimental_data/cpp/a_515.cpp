#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
	long a,b;
	long long s;
	cin>>a>>b>>s;
	
	if((s>=(abs(a)+abs(b)))&&(((abs(a)+abs(b))-s)%2==0))
		cout<<"Yes";
	else
		cout<<"No";
	
	return 0;
}