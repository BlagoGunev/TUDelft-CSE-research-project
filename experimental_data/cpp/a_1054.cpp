#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long x,y,z,t1,t2,t3,diff,s,e,diff1;
	scanf("%lld %lld %lld %lld %lld %lld",&x,&y,&z,&t1,&t2,&t3);
	diff=abs(x-y);
	diff1=abs(x-z);
	e=diff1*t2+2*t3+diff*t2+t3;
	s=diff*t1;
	if(e<=s)
	  cout<<"YES";
	else
	  cout<<"NO";
	return 0;
}