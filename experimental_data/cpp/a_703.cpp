#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >>t;
	int count1=0,count2=0;
	while(t--){
		int m,c;
		cin >> m >>c;
		if(m>c)
			count1++;
		else if(c>m)
			count2++;

	}
	if(count1>count2)
		cout << "Mishka" << endl;
	else if(count2>count1)
		 cout << "Chris" << endl;
	else
		 cout << "Friendship is magic!^^" << endl;
	return 0;
}