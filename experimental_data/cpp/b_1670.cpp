#include <iostream>

#include<array>

#include<bitset>

#include<algorithm>

#include<chrono>

#include<cmath>

#include<cassert>

#include<iomanip>

#include<map>

#include<iomanip>

#include<numeric>

#include<queue>

#include<random>

#include<set>

#include <vector>

#include<stdio.h>

using namespace std;

#define int long long





signed main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    int tt;

    cin>>tt;

    while(tt--){

      int n,A=0,count=0;cin >> n;

      string s; cin >> s;



      int k;cin >> k;

      set<char> p;

      for(int i=0;i<k;i++)

      {

        char x;cin >> x;

        p.insert(x);

      }



      for(int j=0;j<n;j++)

      {

        if(p.find(s[j])!=p.end())

        {

          A=max(count,A);

          count=1;

        }else count++;



        

      }

      cout<<A<<"\n";



  





        

      

     

      

    

    } 

  return 0;

}