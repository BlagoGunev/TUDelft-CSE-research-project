#include <bits/stdc++.h>

using namespace std;



typedef long long int lli;



int main(){

   lli n,m;

   lli idx = 0;



   cin >> n >> m;

   bool arr[1001];

   lli ans = n; 



   memset(arr,true,sizeof arr);

   string to, the, direction, of;

   lli sidx;

   for(lli i = 0; i < m; i++){

      cin >> to >> the >> direction >> of >> sidx;

      if(direction == "right"){

         for(lli j = 0; j < sidx; j++){

            if(arr[j] == true){

               arr[j] = false;

               ans--;

            }

         }

         idx = sidx;

      }

      else{

         for(lli j = n-1; j >= sidx-1; j--){

            if(arr[j] == true){

               arr[j] = false;

               ans--;

            }

         }

         idx = sidx;

      }

   }

   if(ans > 0)

      cout << ans << endl;

   else

      cout << -1 << endl;

}