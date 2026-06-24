#include <bits/stdc++.h>

using namespace std;

long n,m=0;

string s;

long tp(char x,char y) {

	return (x-y+10)%10;

}

bool ss(long i,long j) {

	for (long k=0;k<n;k++)

		if (tp(s[i+k],s[i])<tp(s[j+k],s[j])) return false;

		else if (tp(s[i+k],s[i])>tp(s[j+k],s[j])) return true;

	return true;

}

int main() {

	cin >> n >> s;

	s+=s;

	for (long i=0;i<n;i++)

		if (ss(m,i)) m=i;

	for (long i=0;i<n;i++)

		cout << (char) (tp(s[m+i],s[m])+'0');

}