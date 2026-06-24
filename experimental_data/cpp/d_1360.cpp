// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>

using namespace std;





void HelperStartTheEngine(){

    int n,k; cin >> n >> k;



    int x = -1;



    for(int i = 1; i*i <= n; i++)  {

        if(n%i == 0) {

            int a = n/i;

            if(a <= k && i <= k) x = max(x,max(a,i));

            else if(i <= k) x = max(x,i);

            else if(a <= k) x = max(x,a);

        }

    }

    cout << n/x << '\n';

    

}

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    // freopen("pails.in", "r", stdin);

    // freopen("pails.out", "w", stdout);

    int tt = 1;

    cin >> tt;

    int ii = 1;

    while(tt--){

        //cout << "Case " << ii++ << ": ";

        HelperStartTheEngine();

        

    }

 

    return 0;

}