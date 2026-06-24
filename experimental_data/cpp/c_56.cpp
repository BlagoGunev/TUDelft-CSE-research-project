#include <bits/stdc++.h>

using namespace std;



// goofing around with strings , not intended to be a smart solution



map<string,int> m;

string in;

string s = "";

int ans = 0;



void del (int i) {

    in.erase(i,1);

}



void derp(int i) {



    //cout << i << " " << in[i] << " " << s << " " << in << endl;



    char c = in[i];



    if ( c == ':' ) {

        ans+=m[s];

        m[s]++;

        string os = s;

        //cout << "entering a new realm" << endl;

        s="";

        derp(i+1);

        while ( in[i+1] == ',' ) {

            del(i+1);

            derp(i+1);

        }

        m[os]--;

        del(i+1);

        del(i);

        //derp();

    } else if ( c == '.' ) {

        if (s != "") {

            ans += m[s];

            s = "";

        }

        del(i);

        //cout << "finished" << endl;

        return;

    } else {

        s+=c;

        del(i);

        derp(i);

    }





}



int main () {



    getline(cin,in); in+="$";

    derp(0);

    //cout << in << endl;

    cout << ans << endl;



}