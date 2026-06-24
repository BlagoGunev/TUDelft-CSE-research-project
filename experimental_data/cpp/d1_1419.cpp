#include "algorithm"

#include "iostream"

#include "cstring"

#include "vector"

#include "cmath"

#include "set"

#define nl "\n"

#define te cin >> t

#define pb push_back

#define pob pop_back

#define st for(int z=1;z<=t;z++)

#define ll long long

#define vect(type1,name) vector<type1>name

#define full(x) x.begin(),x.end()

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;



void hello(){



   ll n,i,j;

   cin >> n;

   ll arr[n],arrr[n];

   for(ll i=0;i<n;i++){

   cin >> arr[i];

   arrr[i] = arr[i];

   }

   if(n < 3){

   cout << 0 << nl;

   for(ll i=0;i<n;i++)

   cout << arr[i] << " ";

   cout << nl;

   }

   else{

   if(n%2 == 0)

   cout << n/2-1 << nl;

   else

   cout << n/2 << nl;

   bool b = true;

   sort(arrr,arrr+n);

   sort(arr,arr+n,greater<int>());

   for( i=0, j=0; n ; ){

   if(b){

   cout << arr[i] << " ";

   b = false,i++,n--;

   }

   else{

   cout << arrr[j] << " ";

   b = true,j++,n--;

   }

   }

   cout << nl;

   }



}

int main(){



   FIO

   //ll t;

   //te;st

   hello();

   return 0;

}