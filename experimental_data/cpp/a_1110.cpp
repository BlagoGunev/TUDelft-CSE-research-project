#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define debug1(a) cout<<a<<"\n";
#define debug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define debug2(a,b) cout<<a<<" "<<b<<"\n";
#define debug4(a,b,c,d) cout<<a<<" "<< b <<" "<<c<<" "<<d<<"\n";

ll mod = 1000000007;

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	 int b,k;
	 cin>>b>>k;
	 int arr[k];
	 for (int i = 0; i < k; ++i)
	 {
	 	cin>>arr[i];
	 }

	 int even =0 ,odd = 0;

	 for (int i = 0; i < k; ++i)
	 {
	 	if(arr[i]%2 == 0 || b%2 == 0 && i != k-1)
	 		even++;
	 	else if(i  != k-1)
	 		odd++;
	 	else if(i == k-1 && arr[i]%2 == 0)
	 		even++;
	 	else
	 		odd++;

	 }

	 if(odd %2 == 0)
	 {
	 	cout<<"even\n";
	 }
	 else
	 {
	 	cout<<"odd\n";
	 }
	return 0;
}