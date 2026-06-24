#include <iostream>

#include <vector>

#include <map>

#include <iterator>

#include <queue>

#include <fstream>

#include <math.h>

#include <sstream>

#include <algorithm>

#include <iomanip>



using namespace std;



#define FOR(i,a,b) for(long long int i = a; i < b; i++)

#define mp make_pair

#define pb push_back



typedef pair <int , int> pii;

typedef long long ll;





int main(){

   ll n , x;

   cin >> n >> x;

   ll k;

   ll dc = 0;

   char p;

   for(int i = 0; i < n; i++){

      cin >> p >> k;

      if(k > x && p == '-'){

         dc++;

      }

      else if(p == '-'){

         x -= k;

      }

      else{

         x += k;

      }

   }

   cout << x << endl << dc << endl;

   return 0;

}