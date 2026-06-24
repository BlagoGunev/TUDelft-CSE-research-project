#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;
#define ll long long
const int MAXN=2e5;

int sir[MAXN+1];
int sir2[MAXN+1];
int queries[MAXN+1];
ll coef1[MAXN+1], coef2[MAXN+1];
map<int, int> frecv1, frecv2;

void solve(){
    int n, m, q;
    cin>>n>>m>>q;
    ll sum1=0, sum2=0;
    frecv1.clear();
    frecv2.clear();
    for(int i=0; i<n; i++){
        cin>>sir[i];
        sum1+=sir[i];
        frecv1[sir[i]]++;
    }
    for(int i=0; i<m; i++){
        cin>>sir2[i];
        sum2+=sir2[i];
        frecv2[sir2[i]]++;
    }
    for(int i=0; i<q; i++){
        cin>>queries[i];
        int x=queries[i];
        int cx=x;
        int d=1;
        x=abs(x);
        int ok=0;
        while(d*d<=x){
            //sum1=d, sum2=x/d;
            if(x%d==0){
                int d2=cx/d;
                if(frecv1[sum1-d] && frecv2[sum2-d2])
                    ok=1;
                if(frecv1[sum1-d2] && frecv2[sum2-d])
                    ok=1;
                int d3=-d;
                d2=cx/d3;
                if(frecv1[sum1-d3] && frecv2[sum2-d2])
                    ok=1;
                if(frecv1[sum1-d2] && frecv2[sum2-d3])
                    ok=1;
            }
            d++;
        }
        if(!ok)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}

int main()
{
    int t=1;
    //scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}