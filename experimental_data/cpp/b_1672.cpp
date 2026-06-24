#include <algorithm>

#include <vector>

#include <string>

#include <map>

#include <queue>

#include <stack>

#include <queue>

#include <iostream>

#include <cmath>

#include <cstring>

#include <set>

#include <iomanip>

#include <stdexcept>

#include <fstream>

#define ll long long

#define endl '\n'

using namespace std;

const int INF=0x3f3f3f3f;

const ll inf=0x3f3f3f3f3f3f3f3f;

const int N=1e5+7;

const double pi=acos(-1);

int t;

int main(){

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   cin>>t;

   while(t--){

      string s;

      int flag=0;

      cin>>s;

      int cnt=0;

      if(s[s.size()-1]=='B') flag=1;

      for(int i=0;i<s.size();++i){

         if(s[i]=='A') cnt++;

         else cnt--;

         if(cnt<0) flag=0;

      }

      if(flag) cout<<"YES"<<endl;

      else cout<<"NO"<<endl;

   }

    return 0;

}