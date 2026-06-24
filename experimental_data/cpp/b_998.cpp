#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;

int main()
{
	int n,sum=0,sum2=0,cnt=0,coin,ans=0;

	cin>>n>>coin;

	int a[n];

	vector<int>v;

	for(int i=0;i<n;i++){

		cin>>a[i];

	}

	for(int i=0;i<n-1;i++){

        if(a[i]%2==0)
			sum++;

	    else
		    sum2++;

	    if(sum==sum2){

			v.push_back(abs(a[i+1]-a[i]));

	    }

	}

	sort(v.begin(),v.end());

	for(int i=0;i<v.size();i++){


		cnt+=v[i];

		if(cnt<=coin)
			ans++;

	}

	cout<<ans<<endl;
}