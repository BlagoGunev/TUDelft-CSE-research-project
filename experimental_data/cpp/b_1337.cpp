#define _CRT_SECURE_NO_WARNINGS 

#include <bits/stdc++.h>

#include <cstdio>                                                //int x; while(cin >> x)poka vvod// cout.precision(5) tochnost

#include <regex>

//-----------------------MACRO------------------------------     //%.20lf\n 1.12345678900

#define endl "\n"                                                //%*d ignore %5s first 5

#define ll long long                                             //int "%d"   //char "&c" char arr[1000] //long long "%lld" //float "%f" //double "%lf" //long double "%Lf" //char* "%s"

#define vti vector<int>                                          //scanf("%d", &x); printf("%d", x)

#define vt vector                                                //%[diap,sym]s %*[diap,sym]%s ignore //getline(cin,s)

#define vts vector<string>

#define vtc vector<char>                                         //  j j j

#define vtdmi vector<vector<int>>                                //i 0 1 3    res[i][j] = {{0, 1, 3}, {2, 3, 4}, {4, 5, 5}};

#define pb push_back                                             //i 2 3 4 

#define str string                                               //i 4 5 5

#define maxe *max_element(result.begin(), result.end());

#define mine *min_element(result.begin(), result.end());         

//----------------------------------------------------------

using namespace std;

//----------------------CODE--------------------------------

int main() {

    ios::sync_with_stdio(0); cin.tie(0); 

    int t; cin >> t;

    while (t--) {

        double hp; int at1, at2; cin >> hp >> at1 >> at2;

        if (hp <= (at2 * 10)) {

            cout << "YES" << endl;

        }

        else {

            for (int i = 0; i < at1; i++) hp = floor(hp / 2) + 10;

            for (int i = 0; i < at2; i++) hp -= 10;

            cout << (hp <= 0 ? "YES" : "NO") << endl;

        }

    }

    

    return 0;

}