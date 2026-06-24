#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
const int INF = 2147483647;
const double PI = 3.141592653589793;
const int N = 110;
const double eps = 1e-9;

int n,k,e,x0,yy,x1,x[N],y[N],i;
double od[N],Pr[N],P[N][N];

double jedz (double a, double b) {
       double ind = (a+b)/2.0,sum;
       int i,j;
       if (b-a < eps) return ind;
       for (i=0;i<n;i++) {
           Pr[i]=(od[i]<=ind?1.0:exp(1-((od[i]*od[i])/(ind*ind))));
           //printf("%3lf\n",Pr[i]);
       }
       P[0][0]=1-Pr[0];
       P[0][1]=Pr[0];
       for (i=1;i<n;i++) {
           P[i][0]=P[i-1][0]*(1-Pr[i]);
           for (j=1;j<=i;j++) {
               P[i][j]=P[i-1][j]*(1-Pr[i]) + P[i-1][j-1] * Pr[i];
               //printf("%d %d %.3lf\n",i,j,P[i][j]);
           }
           P[i][i+1]=P[i-1][i] * Pr[i];
       }
       sum=0.0;
       //for (i=0;i<=n;i++) printf("%d %.3lf  ",i,P[n-1][i]); printf("\n");
       for (i=k;i<=n;i++) sum += P[n-1][i];
       //printf("%3lf %3lf\n",ind,sum);
       if (sum >= ((1000-e)/1000.0)) return jedz(a,ind);
       return jedz(ind,b);
}

int main () {
scanf ("%d %d %d %d %d",&n,&k,&e,&x0,&yy);
for (i=0;i<n;i++) {
    scanf ("%d %d",&x[i],&y[i]);
    od[i]=sqrt((x[i]-x0) * (x[i]-x0) + (y[i]-yy) * (y[i]-yy)); 
    //printf("%3lf\n",od[i]);
}
printf("%.10lf\n",jedz(0.0,4000.0));
return 0;
}