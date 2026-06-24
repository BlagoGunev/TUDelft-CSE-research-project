#include <bits/stdc++.h>

#define nl  << "\n"

#define spc << " " <<

#define pt cout <<

using namespace std;

typedef long long ll;

//#define int long long

#define pii pair<int, int>

int mod = 1e9 + 7;

int MAX = 1e9 + 1;

int MIN = -1e9;

double eps = 1e-7;



bool check(vector<int> arr,int n){

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){

        if(arr[i] != (i+1))

            return false;

    }

    return true;

}



int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,minELem = 0; cin >> n;

    vector<int> diff(n-1);

    for(int i=0;i<n-1;i++) cin >> diff[i];

    vector<int> perm(n,0);

    for(int i=1;i<n;i++){

        perm[i] = perm[i-1] + diff[i-1];

        minELem = min(minELem,perm[i]);

    }

    int x = 1-minELem;

    for(int i=0;i<n;i++) perm[i] += x;

    if(!check(perm, n)) pt -1 nl;

    else{

        for(int i=0;i<n;i++) pt perm[i] << " ";

    }

}