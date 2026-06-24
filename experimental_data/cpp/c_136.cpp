#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
#include <string>
#include <fstream>

using namespace std ; 

#define vi vector<int>
#define vvi vector< vi >
#define vb vector<bool>
#define pb push_back
#define imax 1023456789

int main() {
	
	int n ; 
	
	cin >> n ; 
	
	vi numbers ; 
	
	int num ; 
	
	for ( int i = 0 ; i < n ; i ++ ) {
//		cin >> num ; 
		scanf("%d",&num) ;
		numbers.push_back( num ) ; 
	}
	
	int mx = *max_element( numbers.begin() , numbers.end() ) ; 
	
	if ( mx == 1 ) {
		numbers[ 0 ] = 2 ;
	}
	
	else {
		for ( int i = 0 ; i < numbers.size() ; i ++ ) {
			if ( numbers[ i ] == mx ) {
				numbers[ i ] = 1 ; 
				break ; 
			}	
		}
	}	
	
	sort( numbers.begin() , numbers.end() ) ; 
	
	cout << numbers[ 0 ] ;
	
	for ( int i = 1 ; i < numbers.size() ; i ++ ) {
		printf(" %d",numbers[ i ] ) ;
	}
	
	cout << endl ; 
		
	return 0 ;
}