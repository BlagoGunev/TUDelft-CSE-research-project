#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int happyboy[200];

int happygirl[200];



int main() {



    int n,m;

    cin >> n >> m;

    int b;

    cin >> b;

    for(int i=0; i<b; i++) {

        int foo;

        cin >> foo;

        happyboy[foo] = 1;

    }

    int g;

    cin >> g;

    for(int i=0; i<g; i++) {

        int foo;

        cin >> foo;

        happygirl[foo] = 1;

    }

    for(int i=0; i<(n*m)+(m+n); i++) {

        int boy = (i%n);

        int girl = (i%m);

        happyboy[boy] = (happyboy[boy]|happygirl[girl]);

        happygirl[girl] = (happyboy[boy]|happygirl[girl]);



    }

    int ok =1;

    for(int i=0; i<n; i++) ok &= happyboy[i];

    for(int i=0; i<m; i++) ok &= happygirl[i];

    if(ok) {

        cout << "YES" << endl;

    } else {



        cout << "NO" << endl;

    }









}