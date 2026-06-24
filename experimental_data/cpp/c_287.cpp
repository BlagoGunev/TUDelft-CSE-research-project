/*
    
*/
 
#include<iostream>
#include<cstdio>
#include <sstream>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<bitset>
#include<climits>
#include <list>
#include <functional>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 1e9
#define EPS 1e-7
#define PI acos(-1)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pis pair<int,string>
#define F first
#define S second
#define ROW first
#define COL second

long long gcd(long long x, long long y) {
    return y == 0 ? x : gcd(y, x % y);
}
int toInt(char xx) {
    return xx - '0';
}
char toChar(int xx) {
    return xx + '0';
}
int isDigit(char xx) {
    return ('0' <= xx && xx <= '9');
}
bool isCharacter(char xx) {
    return (('a' <= xx && xx <= 'z') || ('A' <= xx && xx <= 'Z'));
}
void swapInt(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

/*** IMPLEMENTATION ***/
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
const int Mod = 1000000007 ;
const int maxn = 1e5 + 10 ;
int exitInput = 0;

int n ; 
int p[maxn] ; 

void read() 
{
#define endread { exitInput = 1 ; return ; } 
	cin >> n ; 
}


void init() 
{
	
}

void solve() 
{ 
	if(n == 1) 
	{
		printf("1") ; return ;
	}
	if(n == 2)
	{
		printf("-1") ; return ;
	}
	
	if(n%4 == 3 || n%4 == 2)
	{
		printf("-1") ; return ;
	}
	
	int np = 0;
	if(n%4 == 1)
	{
		np = 1 ;
		p[(n+1)/2] = (n+1)/2 ;
	}
		
		int i = 1, j = 2 ; 
		
		while(np < n)
		{
			while(p[i]) i++ ;
			j = i+1 ; 
			while(p[j]) j++ ;
			
			//cout << i << ' ' << j << endl ;
			
			p[i] = j ; 
			p[j] = n - i + 1 ; 
			p[n-i+1] = n - j + 1 ;
			p[n-j+1] = i ;
			
			np += 4 ;
		}
	
	cout << p[1] ;
	for(int i = 2; i <= n ;++i)
	{
		cout << ' ' << p[i];
	}
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    int ntest = 1;
    int itest = 1;  
    
	//cin >> ntest; 
	for (itest = 1; itest <= ntest ; ++itest) 
    //for (itest = 1; ; ++itest) 
    {
        read();
        if (exitInput) {
            break;	
        }   
        if(itest > 1)
        {
        	//cout << endl ;
            //printf("\n") ;
        }
        //cout << itest << " " ;
        //printf("Case %d: ",itest) ;
        init();
        solve();
        
    }
    return 0;
}