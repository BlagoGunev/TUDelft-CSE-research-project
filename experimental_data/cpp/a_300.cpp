//***		library		***//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <fstream>
#include <utility>
#include <sstream>
#include <list>
#include <iomanip>
#include <functional>
#include <deque>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <climits>
#include <cctype>
#include <cassert>
#include <bitset>
#include <limits>
#include <numeric>

using namespace std ;

//***		typedef		***//

typedef long long LL ;
typedef long double LD ;
typedef vector < string > VS;
typedef vector < VS > VVS;
typedef vector < int > VI;
typedef vector < VI > VVI;
typedef vector < bool > VB;
typedef complex < LD > Point;
typedef pair<int,int> Pii;
typedef pair<LL,LL> Pll;

//***		define 		***//

#define EPS 1e-8
#define PI 3.14159265359
#define MS(x,r) memset(x,r,sizeof x)
#define FOR(i,start,end) for(int i=start ; i<end ; i++)
#define REP(i,start,end) for(int i=start ; i>=end ; i--)
#define FOREACH(it,x) for(it=(x.begin()) ; it!=(x.end()) ; it++)
#define REPEACH(it,x) for(it=(x.end()-1) ; it!=(x.begin()-1) ; it--)
#define SZ(x) ((int)x.size())
#define All(x) x.begin(),x.end()
#define MK make_pair
#define PB push_back
#define F first
#define S second
#define X real()
#define Y imag()

//***		Moves		***//

int  knightx[] = { -2 , -1 , +1 , +2 , +2 , +1 , -1 , -2 } , knighty[] = { +1 , +2 , +2 , +1 , -1 , -2 , -2 , -1 } ;		//knight moves(8)
int  kingx[] = { -1 , -1 , 0 , +1 , +1 , +1 , 0 , -1 } , kingy[] = { 0 , +1 , +1 , +1 , 0 , -1 , -1 , -1 } ;		//king moves(8)
int  dx2D[] = { -1 , 0 , +1 , 0 } , dy2D[] = { 0 , +1 , 0 , -1 } ;		//adjacent moves(4 moves in 2D)
int  dx3D[] = { 0 , 0 , 0 , 0 , +1 , -1 } /*page*/, dy3D[] = { 0 , +1 , 0 , -1 , 0 , 0 } /*row*/, dz3D[] = { -1 , 0 , +1 , 0 , 0 , 0 } /*col*/;		//adjacent moves(6 moves in 3D)

//***		Math  	 ***//

int GCD(int a,int b){ if(a==b) return a ;	return GCD(b,a%b) ; }
int LCM(int a,int b){ return a * ( b / GCD(a,b) ); }
LL POWER(LL a,LL b){ LL res=1 ;	for(LL p=b ; p ; p>>=1 , a*=a ){ if(p & 1) res*=a ; } return res ; }
LD Line(Point a){ return abs(a); }
LD DRG(LD d1,LD d2){ return ( (asin(d1/d2)*180)/PI ); }

//***	manipulation ***//

bool isDigit(char c){ return( c>='0' && c<='9') ; }
bool isLowerCase(char c){ return( c>='a' && c<='z') ; }
bool isUpperCase(char c){ return( c>='A' && c<='Z') ; }
bool isLetter(char c){ return( isUpperCase(c) || isLowerCase(c) ) ; }
char toLowerCase(char c){ return( isUpperCase(c) ? (c+32) : c ) ; }
char toUpperCase(char c){ return( isLowerCase(c) ? (c-32) : c ) ; }
VS Parse(string temp){ VS ans ;	ans.clear() ; istringstream is(temp) ; for(string s ; is>>s ;ans.push_back(s)) ; return ans ; }
LL toInt(string temp){ LL num=0 ; FOR(i,0,temp.size()){ num*=10 ; num+=(temp[i]-48) ; }	return num ; }
void Prim(bool a[]){ for(int i=3; i<=100001 ; i+=2){ bool k=true; FOR(j,2,sqrt((double)i)+1) { if(i%j==0) {	k=false;break; } }if(k==true)a[i]=k; } }
LD cross( Point a, Point b ){ return ( a.real()*b.imag() - a.imag()*b.real() ) ; } // A*B = |A|*|B|*sin(#) zarb khareji
LD real_conj( Point a, Point b ){ return real( conj(a)*b ) ; } // A.B = |A|*|B|*cos(#) zarb dakheli
LD dot( Point a, Point b ){ return ( a.real()*b.real() + a.imag()*b.imag() ) ; }
LD ang( Point a, Point b ){ return atan2(cross(a,b), dot(a,b)); }

//***	  function 	 ***//

//***	  Main 	 ***//

int main(){
	
	int n,n1,n2,n3;
	cin>>n;
	vector<int> a1,a2,a3;
	bool t=true;
	FOR(i,0,n){
		int x;
		cin>>x;
		if(x>0)
			a2.push_back(x);
		else if(x==0)
			a3.push_back(x);
		else if(x<0)
			a1.push_back(x);
	}
	if(SZ(a1)%2==0){
		a3.push_back(a1[0]);
		a1.erase(a1.begin()+0);
	}
	if(SZ(a2)==0){
		a2.push_back(a1[0]);
		a1.erase(a1.begin()+0);
		a2.push_back(a1[0]);
		a1.erase(a1.begin()+0);
	}
	cout<<SZ(a1);
	FOR(i,0,SZ(a1)) cout<<" "<<a1[i];
	cout<<endl;
	cout<<SZ(a2);
	FOR(i,0,SZ(a2)) cout<<" "<<a2[i];
	cout<<endl;
	cout<<SZ(a3);
	FOR(i,0,SZ(a3)) cout<<" "<<a3[i];
	cout<<endl;
    return 0;

}