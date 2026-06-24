#include<bits/stdc++.h>

using namespace std;



#define int long long

#define pb push_back



int32_t main(){

int t;

cin>>t;

while(t--){

	string s;

	int n;

	cin>>n>>s;

	int sum=0;

	for (int i=n-1; i>=0;--i){

		if (s[i]==')') sum++;

		if (s[i]!=')') break;

	}



	if (sum>n-sum) cout << "Yes" << endl;

	else cout << "No" <<endl;

}

	return 0;

}