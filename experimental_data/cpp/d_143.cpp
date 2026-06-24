#include<cstdio> 

#include<cstdlib>

#include<iostream>

#include<cmath> 

#include<vector> 

#include<algorithm> 

#include<map> 

#include<string> 

#include<cstring> 

using namespace std;



long long i,j,k,l,x,y,m,n,t,t1,s,e[11],a,b,c,d;

string r,p;

long long u (long long a, long long b, long long c){

   return 2*a*b+2*a*c+b*c+4*a+2*b+2*c+4;

}

int main() {

	cin >> n >>m;

	if (n ==1 || m ==1){

	   cout << n*m;

	   return 0;

	}

	if (n > m)

	   swap (n,m); 

	if ( n == 2){

	   s = m/4 *2;

	   m %= 4;

	   if (m > 2)

	      m = 2;

	   s += m;

	   cout << 2 * s;

	   return 0;

	}

	

   cout << (n*m+1)/2;

}