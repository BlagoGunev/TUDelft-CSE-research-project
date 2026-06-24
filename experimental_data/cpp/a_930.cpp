#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std; 
#define read(type) readInt<type>()
#define MP make_pair
#define PB push_back
#define rep(i, j, k) for(int i=(j);i<(k);++i)
#define repi(i, j, k) for(int i=(j);i<=(k);++i)
#define per(i, j, k) for(int i=(j);i>(k);--i)
#define peri(i, j, k) for(int i=(j);i>=(k);--i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> si;
template<typename T> inline T println(T x) { std::cout<< x << std::endl; }
template<typename T> inline T print(T x) { std::cout<< x; }
template <typename T> inline T readInt(){T n=0,s=1;char p=getchar();if(p=='-') s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getchar();if(p=='-') s=-1,p=getchar();while(p>='0'&&p<='9') {n = (n<< 3) + (n<< 1) + (p - '0'); p=getchar();}return n*s;}

int main(){
 //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); //usaco
 int n = read(int);
 vector<int> level(n, 0);
 rep(i, 1, n){
  level[i]=level[read(int)-1]+1; 
 }
 vector<int> cnt(n, 0); 
 rep(i, 0, n){
  cnt[level[i]] += 1; 
 }
 int ans=0; 
 rep(i, 0, n){
  ans+=cnt[i]%2; 
 }
 cout << ans << '\n';  
 return 0; 
}