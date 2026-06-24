#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int TT;
    cin>>TT;
    while(TT--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(A.begin(),A.end());
        int ac = 0, wa = 1e13;
        while(wa-ac > 1){
            int md = (ac+wa)/2;
            int c = 0;
            for(int x:A) c += max(0ll,md-x);
            if(c <= K) ac = md;
            else wa = md;
        }
        for(int i=0;i<N;i++){
            int t = max(0ll,ac-A[i]);
            A[i] += t;
            K -= t;
        }
        int ans = (ac-1)*N+1+K;
        for(int x:A)if(x > ac) ans++;
        cout<<ans<<endl;
    }
}