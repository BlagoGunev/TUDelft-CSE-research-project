#include<bits/stdc++.h>

using namespace std;



pair<int,int> bid[1000+100];



int main(){

	int n;

	cin>>n;

	for(int i=0;i<n;i++){

		cin>>bid[i].first;

		bid[i].second=i+1;

	}

	sort(bid,bid+n);

	cout<<bid[n-1].second<<' '<<bid[n-2].first;

}