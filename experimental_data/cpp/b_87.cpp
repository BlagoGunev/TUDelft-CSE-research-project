#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n)  for(int i = 0;i<n;i++)

#define for1(i, n)  for(int i = 1;i<=n;i++)

map<string,int> mp;



void make(string s,string d){

   int cnt1 = 0, cnt2 = 0;



   forn(i, s.size()) {if(s[i] == '&') cnt1++;

                      if(s[i] == '*') cnt2 ++;

   }



    string pure = s.substr(cnt1, s.size() - cnt1 - cnt2);



    if( (!mp.count(pure)) || mp[pure] == -1) { mp[d] = -1;return; }



    if(mp[pure] - cnt1 + cnt2 < 0)         { mp[d] = -1;return; }

    mp[d] = mp[pure] - cnt1 + cnt2;

}



int main(){

    //freopen("Second.inp","r",stdin);

    ios_base:: sync_with_stdio(false);

   int n;

   cin >> n;

   mp["void"] = 0;

   while(n--){

     string type, s, d;

     cin >> type;

     if(type == "typedef"){

        cin >> s >> d;

        make(s, d);

     }

     else{

        cin >> s;

        int cnt1 = 0, cnt2 = 0;

        forn(i, s.size()){ if(s[i] == '&') cnt1 ++;

                           if(s[i] == '*') cnt2 ++;

                          }

        string pure = s.substr(cnt1, s.size() - cnt1 - cnt2);



        if(!mp.count(pure) || mp[pure] == - 1 || mp[pure] - cnt1 + cnt2 < 0) { cout<<"errtype" << endl;continue; }

        cout<<"void";

         cout << string(mp[pure] - cnt1 + cnt2, '*') << endl;

     }

   }

}