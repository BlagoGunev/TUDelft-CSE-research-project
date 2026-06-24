#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define x0 x0___
#define y0 y0___
#define pb push_back
#define SZ(X) ((int)X.size())
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define ALL(X) X.begin(),X.end()
#define RALL(X) X.rbegin(),X.rend()
#define rep(i,j,k) for(int i = j;i <= k;i ++)
#define per(i,j,k) for(int i = j;i >= k;i --)
#define mem(a,p) memset(a,p,sizeof(a))


const ll MOD = 1E9 + 7;
ll qmod(ll a,ll b,ll c) {ll res=1;a%=c; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%c;a=a*a%c;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

template<typename T, typename S>
void upmax(T& a,S b){if(a<b) a=b;}
template<typename T, typename S>
void upmin(T& a,S b){if(a>b) a=b;}
template<typename T>
void W(T b){cout << b << endl;}
void gettle() {while(1);}
void getre() {int t=0;t/=t;}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int hh, mm;
    int H,D,C,N;
    scanf("%d %d", &hh, &mm);
    scanf("%d %d %d %d", &H, &D, &C, &N);
    if(hh >= 20) {
        printf("%.6f\n", (H + N - 1) / N * 0.8 * C);
    } else {
        int t = 60 - mm;
        t += (20 - hh - 1) * 60;
        double res = (H + N - 1) / N * C;
//        W(res);
        H += t * D;
//        W(H);
        upmin(res, (H + N - 1) / N * 0.8 * C);
        printf("%.6f\n", res);
    }
    return 0;
}