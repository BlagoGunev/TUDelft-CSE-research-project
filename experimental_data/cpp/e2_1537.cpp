#include <bits/stdc++.h>

#define lli long long int

#define pb push_back

#define endl '\n'

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

using namespace std;

 

void ans(){

    int n, k;

    cin >> n >> k;

    string s;

    cin >> s;

    int p1=0, p2=1, pn=-1;

    while(p2<n){

        if(s[p2]>s[p1]){

            if(pn==-1) pn=p2-1;

            break;

        }

        else if(s[p2]==s[p1]){

            if(pn==-1) pn=p2-1;

            p1++;

            p2++;

        }

        else{

            pn = -1;

            p1=0;

            p2++;

        }

    }

    if(pn!=-1){

       string temp = s.substr(0, pn+1);

       s = temp;

    }

    for(int i=0; i<k; i++) cout << s[i%s.size()];

}

int main(){

    // freopen("input.txt", "r", stdin);

    // freopen("output.txt", "w", stdout);

    fastio();

    ans();

    return 0;

}