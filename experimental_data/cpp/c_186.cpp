#include <iostream>



using namespace std;

const int MOD = 1e9+7;

//binary power super-shaaaaaaakh

long long pow(long long n){

	if(n==0)

		return 1;

	else{

		long long t=pow(n/2);

		t=(t*t)%MOD;

		if(n%2==1)

			t=(t*2)%MOD;

		return t;

	}

}

int main(){

    long long n;

    cin>>n;

    int ans=0;

    cout<<((pow(n)*(pow(n)+1))/2)%MOD;

}