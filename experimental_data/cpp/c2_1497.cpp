#include<bits/stdc++.h>

using namespace std;





void solution()

{

    int n,k;

    cin >> n >> k;



    int r = n-k+3;

    for(int i=1;i<=k-3;i++){

        cout << 1 << ' ';

    }

    if(r%2==1){

        cout << 1 << ' ' << r/2 << ' ' << r/2 << '\n';

        return;

    }

    if(r%4==0){

        cout << r/2 << ' ' << r/4 << ' ' << r/4 << '\n';

        return;

    }

    cout << r/2 -1 << ' ' << r/2 -1 << ' ' << 2 << '\n';





}





int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    int tt;

    cin >> tt;

    while(tt--) solution();



    return 0;



}