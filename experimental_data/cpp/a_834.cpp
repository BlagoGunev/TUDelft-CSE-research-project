#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    char f,l;
    long long n;
    cin>>f>>l>>n;
    if( n % 2 == 0)
        cout<<"undefined";
    else if( ( n % 4 == 1 && ( f == '^' && l == '>' || f == '>' && l == 'v' ||
                            f == 'v' && l == '<' || f == '<' && l == '^' ) ) ||
               ( n % 4 == 3 && ( l == '^' && f == '>' || l == '>' && f == 'v' ||
                            l == 'v' && f == '<' || l == '<' && f == '^' ) )            ){
        cout<<"cw";
    }
    else {
        cout<<"ccw";
    }
	return 0; 
}