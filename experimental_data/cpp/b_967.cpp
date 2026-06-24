#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;

ll n, A, B, ct[10005],sum=0, x,numr, ans = 0, nonBlock;

int main()
{
    fast_io;
    bool done = false;
    cin >> n >> A >> B;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ct[x]++;
        sum += x;
        if (i==0){
            numr = A*x;
            nonBlock = x;
        }
    }
    if (numr >= B*sum){
        done = true;
    }
    for (int i = 10000; i > 0 && not done; --i) {
        if (i!=nonBlock){
            while(ct[i]>0 && not done){
                ct[i]--;
                sum-=i;
                ans++;
                if (numr>=B*sum){
                    done = true;
                }
            }
        }
        else{
            while(ct[i]>1 && not done){
                ct[i]--;
                sum-=i;
                ans++;
                if (numr>=B*sum){
                    done = true;
                }
            }
        }
    }
    cout << ans;
    return 0;
}