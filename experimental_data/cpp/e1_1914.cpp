#include<bits/stdc++.h>
using namespace std;
map<pair<vector<long long>, vector<long long> >, long long> mp;
long long solve(vector<long long> a, vector<long long> b, long long sum1, long long sum2, long long turn){
    bool something = false;
    for(long long i = 0; i < a.size(); i++){
        if(a[i] > 0 && b[i] > 0){
            something = true;
        }
    }
    if(!something){
        return sum1 - sum2;
    }
    if(turn == 0){
        long long ans = -1e18;
        for(long long i = 0; i < a.size(); i++){
            if(a[i] > 0 && b[i] > 0){
                vector<long long> thing1;
                vector<long long> thing2;
                long long sum3 = 0;
                long long sum4 = 0;
                for(long long j = 0; j < a.size(); j++){
                    if(j != i){
                        thing1.push_back(a[j]);
                        sum3 += a[j];
                        thing2.push_back(b[j]);
                        sum4 += b[j];
                    }
                    else{
                        thing1.push_back(a[j] - 1);
                        sum3 += (a[j] - 1);
                        thing2.push_back(0);
                    }
                }
                ans = max(ans, solve(thing1, thing2, sum3, sum4, 1));
            }
        }
        return ans;
    }
    else{
        long long ans = 1e18;
        for(long long i = 0; i < a.size(); i++){
            if(a[i] > 0 && b[i] > 0){
                vector<long long> thing1;
                vector<long long> thing2;
                long long sum3 = 0;
                long long sum4 = 0;
                for(long long j = 0; j < a.size(); j++){
                    if(j != i){
                        thing1.push_back(a[j]);
                        sum3 += a[j];
                        thing2.push_back(b[j]);
                        sum4 += b[j];
                    }
                    else{
                        thing1.push_back(0);
                        thing2.push_back(b[j] - 1);
                        sum4 += (b[j] - 1);
                    }
                }
                ans = min(ans, solve(thing1, thing2, sum3, sum4, 0));
            }
        }
        return ans;
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        long long sum1 = 0;
        for(long long i = 0; i < n; i++){
            cin >> a[i];
            sum1 += a[i];
        }
        long long sum2 = 0;
        for(long long i= 0; i < n; i++){
            cin >> b[i];
            sum2 += b[i];
        }
        cout << solve(a, b, sum1, sum2, 0) << "\n";
        mp.clear();
    }
}