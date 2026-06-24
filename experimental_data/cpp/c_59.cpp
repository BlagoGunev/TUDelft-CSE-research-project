#include<bits/stdc++.h>





#define pb push_back

#define mp make_pair

#define F first

#define S second





typedef long long ll;

typedef unsigned long long ull;





using namespace std;









int main(){



ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);





int k; cin >> k;

string s; cin >> s;



map<char, bool> alp;



for(int i=0, c='a'; i<k; i++, c++) alp[(char)c]=true;



for(int i=0; i<s.length(); i++) if(s[i]!='?') {alp.erase(s[i]);  if(s[i] >= 'a'+k){ cout << "IMPOSSIBLE"; return 0; } }



int l,r;

if(s.length()%2) {l = r = s.length()/2;}

else {r=s.length()/2; l = r-1;}



for(; l>=0 && r<s.length(); l--,r++){





    if(s[l] == '?' && s[r] != '?') s[l] = s[r];

    else if(s[l] != '?' && s[r] == '?') s[r] = s[l];



    else if(s[l]=='?' && s[l]==s[r]){

            if(!alp.empty()){

                for(char c= ('a' + k -1); c>='a'; c--)

                if(alp.count(c)){

                    s[l] = s[r] = c;

                    alp.erase(c);

                    break;

                }

            } else {s[l] = s[r] = 'a'; }

    } else if(s[l]!=s[r]){

        cout << "IMPOSSIBLE";

        return 0;

    }





}



if(!alp.empty()){

    cout << "IMPOSSIBLE";

        return 0;

}



cout << s;







return 0;

}