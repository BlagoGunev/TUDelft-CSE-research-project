///~~~LOTA~~~///

#include <iostream>

#include <string>

#include <cmath>

#include <map>

#include <tuple>

#include <vector>

#include <array>

#include <set>

#include <algorithm>

using namespace std;

#define str to_string

#define in binary_search

#define ll long long

#define pointer vector<int>::iterator

#define li long int

#define ld long double

#define append push_back

#define add insert

#define nl endl

#define all(x) (x).begin(),(x).end()

#define sum(a) accumulate(all(a),0)

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){

   	fast_io;

   	ll t,n,m,c;

   	cin>>t;

   	while(t--){

   		cin>>n;

   		for(int i=0;i<n;i++){

   			for(int j=0;j<i+1;j++){

   				if(j==0 || j==i){

   					cout<<"1 ";

   				}

   				else{

   					cout<<"0 ";

   				}

   			}

   			cout<<nl;

   		}

   	}

   	return 0;

}