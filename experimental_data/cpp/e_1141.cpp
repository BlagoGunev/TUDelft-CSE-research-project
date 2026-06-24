#include <bits/stdc++.h>

#define nl  << "\n"

#define spc << " " <<

#define pt cout <<

using namespace std;

typedef long long ll;

#define int long long

#define pii pair<int, int>

int mod = 1e9 + 7;

int MAX = 1e9 + 1;

int MIN = -1e9;

double eps = 1e-7;



int dieTime(int req,vector<int> &arr,int n){

    for(int i=0;i<n;i++){

        req += arr[i];

        if(req <= 0)

            return i+1;

    }

    return n;

}



signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int h,n,netDam = 0,minDam = MAX; cin >> h >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){

        cin >> arr[i];

        netDam += arr[i];

        minDam = min(minDam,netDam);

    }

    minDam = abs(minDam);

    if(h <= minDam)

        pt dieTime(h, arr, n) nl;

    else if(netDam >= 0)

        pt -1 nl;

    else{

        netDam = abs(netDam);

//        pt minDam spc h spc netDam nl;

        int num = ceil((double)(h-minDam)/netDam);

//        pt num nl;

        h = h-num*netDam;

        int ans = num*n;

//        pt ans nl;

        ans += dieTime(h, arr, n);

        pt ans nl;

    }

}