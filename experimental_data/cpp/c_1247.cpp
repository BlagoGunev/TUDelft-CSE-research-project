#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, M = 1e6+7;
 
int how (int x){
    int cnt = 0;
    for(int i=0; i<31; i++)if(x & (1<<i))cnt++;
    return cnt;
}
 
int main (){
 
 
    
    int n, p;
    cin >> n >> p;

    int mn = 33;
    
    for(int i=30; i>=1; i--){

        int x = n - i*p;
        if(x<=0)continue;


        if(x>=i && i>=how(x))mn = min(mn, i);
       
    }


    if(mn==33)
    cout << -1 << endl;
    else cout << mn << endl;

}