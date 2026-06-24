#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int dp[1035];
int T,n;

void init(){
    for(int i=1;i<=1000;i++){
        dp[i] = INT_MAX;
    }

    for(int i=0;i<=1000;i++){
        dp[i+1] = min(dp[i]+1, dp[i+1]);
        dp[i+3] = min(dp[i]+1, dp[i+3]);
        dp[i+6] = min(dp[i]+1, dp[i+6]);
        dp[i+10] = min(dp[i]+1, dp[i+10]);
        dp[i+15] = min(dp[i]+1, dp[i+15]);
    }
}

int main(){
    init();
    cin >> T;
    while(T--){
        cin >> n;
        if(n <= 1000){
            cout << dp[n] << endl;
        }
        else{
            int t = (n-500) / 15;
            n -= t * 15;
            cout << t + dp[n] << endl;
        }
    }
}