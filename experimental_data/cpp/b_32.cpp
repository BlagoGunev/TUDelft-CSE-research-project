#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;


int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    string s;
    cin>>s;
    vector< int > ans;
    int i=0;
    while(i < s.size()){
       if(s[i] == '.'){
         ans.push_back(0);
         i++;
       }
       else{
           if(s[i+1] == '.'){
              ans.push_back(1);
              i += 2;
           }
           else{
              ans.push_back(2);
              i += 2;
           }
       }
    }                            
    for(int i=0; i<ans.size(); i++) cout<<ans[i];        
    return 0;
}