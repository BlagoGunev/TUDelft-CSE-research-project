#include<bits/stdc++.h>

using namespace std;

void test_ans(){
    long long n;
    cin >> n;
    if(n==2){
        cout << 1 << " " << 0 << "\n";
        return;
    }
    int idx=1;
    long long arb=2;
    while(arb<=n){
        arb*=2;
        idx++;
    }
    if((n&n-1)==0){
        arb/=2;
    }
    arb/=2;
    for(int elem=n-1;elem>=arb;elem--){
        cout << elem << " ";
    }
    cout << 0 << " ";
    for(int elem=arb-1;elem>0;elem--){
        cout << elem << " ";
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >>t;
    while(t--){
        test_ans();
        cout << "\n";
    }
    return 0;

}