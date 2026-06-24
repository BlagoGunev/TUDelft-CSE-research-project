#include <bits/stdc++.h>
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

set < int > ljbg;
multiset < int > happy;
int n ;

int main( int argc , char * argv[] ){
	cin >> n ;
	for(int i = 0 ; i < n ; ++ i){
		int x ;
		cin >> x;
		happy.insert( x );
	}
	for(int i = 1 ; i <= 500000000 ; ++ i)
		if( i <= 1000000 )
			ljbg.insert( i );
	for(auto it : happy)
		cout << it << " ";
	cout << endl;
	return 0;
}