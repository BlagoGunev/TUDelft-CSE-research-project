#include <iostream>

#include <vector>

using namespace std;



int main(){

    int t; cin >> t;

    while(t--){

        int n; cin >> n;

        bool b=1;

        vector<int> v(n);

        for(int i = 0;i<n;i++) cin >> v[i];



        for (int i=0;i<n;i+=2) {

          if(v[0]%2!=v[i]%2) b = 0;

        }



        for (int i=1;i<n;i+=2) {

          if(v[1]%2!=v[i]%2) b=0;

        }

        if(b) cout << "YES" << endl;

        else cout << "NO" << endl;

    }

    return 0;

}