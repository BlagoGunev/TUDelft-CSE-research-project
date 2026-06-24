#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair< int ,int > pii;
#define SIZE(X) ((int)(X.size()))
#define X first
#define Y second
#define LENGTH(X) ((int)(X.length()))
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) cin>>((a)[i])
typedef long long int int64;
typedef unsigned long long uLL;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FU(i,a,n) for(int i=a;i<=n;i++)
#define FD(i,a,n) for(int i=n;i>=a;i--)
#define ld long double
#define GI(n) scanf("%d",&n)
#define GS(n) scanf("%s"&s)
#define GII(n,m) scanf("%d %d",&n,&m)
#define PI(n) printf("%d\n",n)
#define PII(n,m) printf("%d %d\n",n,m)
#define PL(n) printf("%I64d\n",n)
#define PLL(n) printf("%I64d\n",n)
#define GLL(n) scanf("%I64d",&n)
#define GL(n) scanf("%I64d",&n)
#define PN printf("\n")
#define N 2007
#define MAX 200007

double pos1[N];
double pos2[N];
 
int main(){
    int n, t;
    double p;
    cin>>n>>p>>t;
    for(int i=0; i<=n; i++){
        pos1[i]=0.00;
        pos2[i]=0.00;
    }
    pos1[0]=1.00;
    for(int i=0; i<t; i++){
        for(int j=0; j<n; j++){
            pos2[j]=(double)p*pos1[j-1]+(double)(1.0-p)*pos1[j];
        }
        pos2[n]=(double)p*pos1[n-1]+(double)pos1[n];
        for(int j=0; j<=n; j++){
            pos1[j]=(double)pos2[j];
        }
    }
    double ans=0.00;
    for(int i=1; i<=n; i++){
        ans+=(double)pos2[i]*(double)i;
    }
    cout<<setprecision(7);
    cout<<ans<<endl;
    return 0;
}