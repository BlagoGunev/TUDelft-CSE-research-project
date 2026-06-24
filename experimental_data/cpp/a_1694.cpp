#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int t,a,b,minn,more1,more0;

	cin>>t;

	while(t--){

		cin>>a>>b;//TODO

		minn=min(a,b);

		for(int i=1;i<=minn;i++){

			cout<<"10";//TODO

		}

		more1=b-minn;

		more0=a-minn;

		for(int i=1;i<=more1;i++){

			cout<<"1";//TODO

		}

		for(int i=1;i<=more0;i++){

			cout<<"0";//TODO

		}

		cout<<endl;



		

	}

	return 0; 

}