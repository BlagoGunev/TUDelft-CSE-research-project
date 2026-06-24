#include <bits/stdc++.h>

using namespace std;

 

typedef long long int ll;

typedef unsigned long long ull;





void solve(){

	int x;

	cin>>x;

	int steps=1;

	while(steps*(steps+1)/2<x){

		steps++;

	}

	if((steps*(steps+1)/2)-x==1){

		steps++;

	}

	cout<<steps<<endl;

}

int main() {

	// // For getting input from input.txt file

 //    freopen("input.txt", "r", stdin);

 

 //    // Printing the Output to output.txt file

 //    freopen("output.txt", "w", stdout);



	ios_base::sync_with_stdio(false);

    cin.tie(NULL); 



	int t=1;

	cin>>t;



	while(t-- > 0){

		solve();

	}

	return 0;

}