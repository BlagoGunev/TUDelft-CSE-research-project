#include <bits/stdc++.h>



using namespace std;





#define SONIC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl '\n'



const int inf9 = 1e9 ;

const int long long inf18 = 1e18 + 18 ;

const int mod = 1e9 + 9 ;

const int N = 2e6 + 6 ;

const double PAI = 3.141592653 ;









//

vector < vector < int > > adj( N ) ;

vector < bool > vis( N , false ) ;

queue < int > q ;

int depth[ N ] ; 

int sons[ N ] ;

vector < int > happiness ;

///





void addEdge( int u , int v ){

	adj[ u ].emplace_back( v ) ;

	adj[ v ].emplace_back( u ) ;

}





signed main(){



		SONIC



//freopen ("hamza.in","r", stdin);

//freopen ("hamza.in","r", stdout);



int t ; cin >> t ;

while( t-- ){



int long long n , pos = 0 , neg = 0 ; cin >> n ; 

int arr[ n ] ; 



	for ( int i = 0 ; i < n ; ++i ){

		cin >> arr[ i ] ; 

		

		if ( arr[ i ] > 0 ) pos += arr[ i ] ;

		else if ( arr[ i ] < 0 ){

		   

			if ( pos == 0 ) neg += arr[ i ] ;

			else{

			   

				if ( pos >= -arr[ i ] ) pos += arr[ i ] ;

            else{

         	neg += arr[ i ] + pos ;

               pos = 0 ;

				}

				

			}

			

		}

		

	}

	

		cout << abs( neg ) << endl ;

				

}

    return NULL ;

}