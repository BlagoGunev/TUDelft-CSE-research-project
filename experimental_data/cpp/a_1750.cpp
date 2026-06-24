#include <bits/stdc++.h>

#include <iostream>

// v.erase( unique(all(v)) , v.end() )    ----->   removes duplicates and resizes the vector as so

using namespace std;

#define ll long long

#define lld long double

const lld pi = 3.14159265358979323846;

#define pb push_back

#define all(a) a.begin(),a.end()

#define rall(a) a.rbegin(),a.rend()

#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

#define mod (int)(1e9+7)

#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers



int main(){

	ios::sync_with_stdio(0);

	int t;

	cin>>t;

	while(t--){

		int n;

		cin>>n;

		int arr[n];

		int sum=0,ans=0;

		for(int i=0;i<n;i++){

			cin>>arr[i];

			ans+=arr[i];

		}

		if(arr[0]==1)cout<<"YES\n";

		else cout<<"NO\n";

	

	}

}