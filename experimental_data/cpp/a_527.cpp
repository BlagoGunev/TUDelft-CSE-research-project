#include <iostream>

#include <vector>

#include <map>

#include <iterator>

#include <queue>

#include <fstream>

#include <math.h>

#include <sstream>

#include <algorithm>



using namespace std;



#define FOR(i,a,b) for(int i = a; i < b; i++)

#define mp make_pair



typedef pair <int , int> pii;

typedef long long ll;





int main(){

   ll a,b;

   cin >> a >> b;

   if(a < b){

      swap(a,b);

   }

   ll i = 0;

   while(a != b && a != 0 && b != 0){

      i += a/b;

      a = a%b;

      if(a < b){

         swap(a,b);

      }

   }

   cout << i << endl;

}