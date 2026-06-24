#include <bits/stdc++.h>

//#include <cstdio>

using namespace std;

#define ll long long

#define F first

#define S second

template <class T> void fmax(T &a, T b){ a = max(a, b);}

template <class T> void fmin(T &a, T b){ a = min(a, b);}

template <class T> void fmax(T &a, const T &b){ a = max(a, b);}

template <class T> void fmin(T &a, const T &b){ a = min(a, b);}



const int N = 2e2 + 10;

char t[N];

int n, m;



int main(){

    // freopen("input.txt", "r", stdin);

  //  freopen("output.txt", "w", stdout);

   // ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){

        char c;

        cin >> t[i];

    }

    if(n - m >= m - 1){

        cout << "PRINT " << t[m] << endl;

        int cnt = 0;

        while(m != 1){

            cnt++;

            m--;

            cout << "LEFT\n";

            cout << "PRINT " << t[m] << endl;

        }

        if(cnt == n - 1) return 0;

        for(int i = 1; i <= cnt; i++){

            m++;

            cout << "RIGHT\n";

        }

        while(m != n){

            m++;

            cout << "RIGHT\n";

            cout << "PRINT " << t[m] << endl;

        }

    } else {

        cout << "PRINT " << t[m] << endl;

        int cnt = 0;

        while(m != n){

            cnt++;

            m++;

            cout << "RIGHT\n";

            cout << "PRINT " << t[m] << endl;

        }if(cnt == n - 1) return 0;

        for(int i = 1; i <= cnt; i++){

            m--;

            cout << "LEFT\n";

        }

        while(m != 1){

            m--;

            cout << "LEFT\n";

            cout << "PRINT " << t[m] << endl;

        }

    }

}