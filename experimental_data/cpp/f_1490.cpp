#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    map<int,int> freq;
    map<int,int> ffreq;
    set<int> fset;
    int max = 0;
    int elm = 0;
    for(int i = 0; i < n; i++){

      int m;
      cin >> m;
      if(m > max){
        max = m;
      }
      if(freq.find(m) == freq.end()){
        freq[m] = 1;
        
      } else{
        freq[m] += 1;
      }
      
    }

    for(auto& it:freq){
        
      if(ffreq.find(it.second) == ffreq.end()){
        ffreq[it.second] = 1;
        
      } else{
        ffreq[it.second] += 1;
      }
      fset.insert(it.second);
      
      
    }

     
    int nsmf = 0;
    int freqS = freq.size();
    int e = 0;
    for(auto& itrsd:fset){
        
     e = itrsd*(freqS-nsmf);
     if(e > elm){
         elm = e;
     }    
     
     nsmf += ffreq[itrsd];
     
    
      
    }
    int ans = n-elm;
    std::cout << ans << '\n';

    
  }
  return 0;
}