#include<bits/stdc++.h>

using namespace std;



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    int t;

    cin >> t;

    

    while(t--){

        int a[6];

        unordered_set<int> x,y;

        for(int i=0; i<6; i++) cin>>a[i];

        

        x.insert(a[0]);

        x.insert(a[2]);

        x.insert(a[4]);

        

        y.insert(a[1]);

        y.insert(a[3]);

        y.insert(a[5]);

        

        if(x.size() == 3 || y.size() == 3) cout << "YES" << endl;

        else cout << "NO" << endl;

    }



    return 0;

}