#include<iostream>

#include<string>

#include<vector>

#include<set>

#include<algorithm>

#include<math.h>

#include<utility>

#include<queue>

#include<map>

using namespace std;

long long n,k;

vector<long long>a,b;

bool check(long long mid)

{

	long long sum=0,x;

	for(int i=0;i<n;i++)

	{

	x=mid*a[i]-b[i];

	if(x>0)sum+=x;

	}

	

	return sum<=k;





}





int main() {

 cin>>n>>k;

 long long x;

 for(int i=0;i<n;i++)

 {cin>>x;a.push_back(x);}

 

 for(int i=0;i<n;i++)

	{cin>>x;b.push_back(x);}

 long long l=0,r=3e9,res;

 

 while(l<=r)

 {

	 long long mid=(l+r)/2;

	 if(check(mid))

	 {

	 l=mid+1;

	 res=mid;

	 }

	 else r=mid-1; 

	 

 }



 cout<<res<<endl;

}