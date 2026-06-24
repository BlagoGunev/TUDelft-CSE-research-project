// ins B code
#include<iostream>
using namespace std;
#define int long long
const int N = 14, mod = 1e9+7;
int A[N], ans, a, tmp, unused;
int32_t main(){
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<100;i++)
    for(int i=0;i<N;i++){
        if(A[i]==0) continue;
        int sm = 0;
        tmp = A[i]/N;
        for(int j=0;j<N;j++){
            int t = tmp+(j!=i?A[j]:0);
            for(int k=i+1,ln=0;ln<A[i]%N;ln++,k++){
                if(k%N==j) t++;
            }
            if(t%2==0) sm+=t;
        }
        ans = max(ans, sm);
    }
    cout << ans;
}