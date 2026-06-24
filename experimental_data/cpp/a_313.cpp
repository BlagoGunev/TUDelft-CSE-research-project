#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cctype>
#include<ctime>
#include<cassert>
#include<algorithm>
using namespace std;
#define ll __int64
//#define ll long long int
const int INF=1000000009;
const int MOD=1073741824;
const double PI=3.1415926535897932384626433832795;
const double E=2.7182818284590452353602874713527;
const double EPS=1e-9;
template<class T> inline T fmin(T a,T b){   return a<b?a:b;  }
template<class T> inline T fmax(T a,T b){   return a>b?a:b;  }
template<class T> inline void fswap(T &x,T &y){   T t;t=x,x=y,y=t; }
template<class T> inline T fabs(T n){   return n>=0 ? n:-n;  }
//template<class T> inline T fmod(T a,T m){  return a<m? (a<0? (a%m+m)%m:a):a%m;  }
template<class T> inline T gcd(T a,T b){    while(b){   T t=b;b=a%b;a=t;  } return a;  }
template<class T> inline T lcm(T a,T b){    return a/gcd(a,b)*b;   }
const int N=10005;
const int M=10005;
int n,m,T,cas=1;
vector<int> vec;
struct node
{
    int a,b;
};
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout); 

    int i,j,k,sum,flag,cnt,p,q; 
    while(cin>>n)
    {
        int t1,t2,t3;
        if(n>=0)
        {
            cout<<n<<endl;
            continue;
        }
        else
        {
            t1=n;
            int temp=-n;
            t2=-temp/10;
            t3=-(temp/100*10+temp%10);
            int ans=t1;
            if(t2>ans)
                ans=t2;
            if(t3>ans)
                ans=t3;
            cout<<ans;

        }
       
    }
    
    return 0;
}