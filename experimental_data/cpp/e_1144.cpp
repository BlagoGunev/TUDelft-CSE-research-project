#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<string>
#include<ctime>
#include<iomanip>
#include<sstream>
#include<assert.h>
#define FINF (-1000000)
#define llu long long unsigned
#define ll long long
#define BASE 10000
#define MAXB 105
#define lson 2*rt+1,l,mid
#define rson 2*rt+2,mid+1,r
#define L 2*rt+1//rt<<1
#define R 2*rt+2//(rt<<1)|1
#define PN putchar('\n');
#define mod 123456789
#define mod1 1000000007
#define mod2 1000000009
#define INF (0x3f3f3f3f)
#define LLINF (1LL<<60)
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define bfo(i,a,n) for(int i=(a);i<=(n);i++)
#define ofb(i,a,b) for(int i=(a);i>=(b);i--)
#define shua(x, y) memset(x, y, sizeof(x))
#define SZ(x) ((int)(x).size())
#define sqr(x) ((x)*(x))
#define pb push_back
//#define eps 1e-6
#define MAXM 55
#define MAXN 200002
using namespace std;
typedef pair< pair<int,int>, int > ppiii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<char,int> pci;
typedef vector<ll> vec;
typedef vector<vec> mat;

inline int su(char c){return c-'a';}

int res[MAXN];
char sa[MAXN],sb[MAXN];

void init() {
}
int main() {
	int n;
	cin>>n;
        scanf("%s%s",sa+1,sb+1);
        for(int i=n;i>=1;i--){
                int t=su(sa[i])+su(sb[i])+res[i];
                if(t>=26){
                        t-=26;
                        res[i-1]+=1;
                }
                res[i]=t;
        }
        for(int i=0;i<=n;i++){
		int t=res[i]/2,down=res[i]&1;
                if(down==1){
                        res[i+1]+=26;
                }
                if(i!=0){
                        putchar(t+'a');
                }

        }



	return 0;
}