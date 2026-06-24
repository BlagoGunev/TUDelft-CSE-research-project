#include<bits/stdc++.h>

using namespace std;



void solve(){

    int n ;

    cin >> n;



    vector<int> v(n) ;

    for(auto &x : v) cin >> x ;



    auto check = [&](){

        for(int i = 1; i < n; i++){

            if(v[i] < v[i-1] )

                return false ;

        }

        return true ;

    };



    auto MEX = [&](){

        vector<int> temp(n+1) ;

        for(auto x : v) temp[x] ++ ;

        for(int i = 0 ; i <= n; i++){

            if(temp[i] == 0)

                return i ;

        }

        assert(false) ;



    };



    vector<int> mv ;

    while(!check()){

        int mex = MEX() ;



        if(mex < n){

            v[mex] = mex ;

            mv.emplace_back(mex+1) ;

        }

        else{

            int i = 0 ;

            while(v[i] == i) i++ ;

            v[i] = mex ;

            mv.emplace_back(i+1) ;

        }

    }

    cout << mv.size() << endl ;

    for(auto x : mv) cout << x <<" " ;

    cout << endl ;

}



int main(){

    int t ;

    cin >> t ;

    for(int i = 0 ; i < t ; i ++){

        solve();

    }

    return 0 ;

}