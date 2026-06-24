#include <bits/stdc++.h>

using namespace std;

 

#define nline '\n'

#define ll long long

#define v vector

#define pb push_back

#define int64 int64_t

#define moudlo 1000000007

 

void google(int i){

    cout << "Case #" << i << ": ";

}



void solve(){

    int n;

    cin >> n;

    int first = 1;

    int last = n;

    bool firstchance = true;

    for(int i = 0 ; i < n ; i++){

        if(firstchance){

            cout << first << " ";

            firstchance = false;

            first++;

        }

        else{

            cout << last << " ";

            firstchance = true;

            last--;

        }

    }

    cout << nline;

}

 

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int t = 1;

    cin >> t;

    for(int i = 1 ; i <= t ; i++){

        // google(i);

        solve();

    }

    return 0;

}