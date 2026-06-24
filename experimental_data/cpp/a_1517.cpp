#include<iostream>

#define ll long long 

using namespace std;



int main(){

    ll t; cin>>t;

    while (t--)

    {

        ll n; cin>>n;

        if(n%2050!=0){

cout<<-1<<endl;

        }

        else if(n%2050==0){

            ll div=n/2050;

                int sum = 0;

        while (div != 0) {

            sum = sum + div % 10;

            div = div / 10;

        }

cout<<sum<<endl;

        }

    }

return 0;

}