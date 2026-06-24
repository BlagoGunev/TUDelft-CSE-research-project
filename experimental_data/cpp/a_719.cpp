#include<bits/stdc++.h>

using namespace std;



int main()

{

	int n, prev, next;

	bool up = false;

	cin>>n;

	cin>>next;

	for(int i=1; i<n; i++)

	{

		prev = next;

		cin>>next;

		if(prev > next) up = false;

		else up = true;

	}

	if(next == 15) up = false;

	if(next == 0) up = true;

	

	if(n==1) cout<<((next==15)?"DOWN":((next==0)?"UP":"-1"))<<endl;

	else if(up) cout<<"UP"<<endl;

	else cout<<"DOWN"<<endl;

	

	return 0;

}