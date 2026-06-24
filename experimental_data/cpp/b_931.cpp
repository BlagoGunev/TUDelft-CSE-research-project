#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<int> v1,v2;

int calc(int x){
 int cnt=0;
 while(x>0){
  x/=2;
  cnt++;
 }
 return cnt;
}

int main(){
 scanf("%d%d%d",&n,&a,&b);
 for(int i=1 ; i<=n ; ++i){
  v1.push_back(i);
 }

 int final = calc(n)-1;
 //cout << final << "\n" ;
 /*int val = abs(a-b);
 int ans = (val)/2;
 if(ans+1==final){
  cout << "Final!\n";

 }
 else cout << ans+1 << "\n" ;
 */
 for(int i=1 ; i<=final ; ++i){
  for(int j=0 ; j<(int)v1.size() ; j+=2){
   if((v1[j]==a && v1[j+1] == b) || (v1[j]==b && v1[j+1]==a)){
    if(i==final){
     cout << "Final!\n";
     return 0;
    }
    else{
     cout << i << "\n";
     return 0;
    }
   }
   else if(v1[j]==a || v1[j]==b)v2.push_back(v1[j]);
   else if (v1[j+1]==a || v1[j+1]==b)v2.push_back(v1[j+1]);
   else v2.push_back(v1[j]);
  }
  v1.clear();
  for(auto el : v2){
   v1.push_back(el);
  }
  v2.clear();
 }

}