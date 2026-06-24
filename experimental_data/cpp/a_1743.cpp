#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define endl "\n"

#define vi vector<int>



int main() {

   int test;

   cin >> test;

   while(test--){

      ll sum = 0;

      ll n,m,count,in;

      cin >> n;

      for(int i=0;i<n;i++){

         cin >> m;

      }

      m=10-n;

      if(m<2){

         cout<< "0\n";

         continue;

      }

      else{

         count=1,in=2;

         for(int i=3;i<=m;i++){

            count+=in;

            in++;

         }

      }

      cout << count*6 << endl; 

   }

}