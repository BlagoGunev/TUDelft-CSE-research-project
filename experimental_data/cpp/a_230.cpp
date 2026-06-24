#include <bits/stdc++.h>

using namespace std;

pair <int, int>a[1001];

int main(){

	int s,n;

	cin>>s>>n;

	for(int i=0;i<n;i++){

		cin>>a[i].first>>a[i].second;

	}

	sort(a,a+n);

	for(int i=0;i<n;i++){

		if(s<=a[i].first){

			cout<<"NO";

			return 0;

		}

		else s=s+a[i].second;

	}

	cout<<"YES";

	return 0;

}