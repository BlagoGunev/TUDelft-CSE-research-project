#include <bits/stdc++.h>

 

using namespace std;

 

template<typename T>

T input(){

    T ans = 0, m = 1;

    char c = ' ';

    while (!((c >= '0' && c <= '9') || c == '-'))

        c = getchar();

    if (c == '-')

        m = -1, c = getchar();

    while (c >= '0' && c <= '9'){

        ans = ans * 10 + (c - '0'), c = getchar();

    }

    return ans * m;

}

 

template<typename T>

void read(T& a){

    a = input<T>();

}

template<typename T, typename... R>

void read(T& a, R&... r){

    a = input<T>();

    read(r...);

}



int main() {

    //ios_base::sync_with_stdio(0); cin.tie(0);

#ifdef LOCAL

    freopen("in.txt", "r", stdin);

    //freopen("out.txt", "w", stdout);

#endif

    char x[2][2];

    string s;

    for (int i = 0; i < 2; ++ i){

    	for (int j = 0; j < 2; ++ j){

    		cin >> x[i][j];

    	}

    }

    if (x[0][0] != 'X') s += x[0][0];

    if (x[0][1] != 'X') s += x[0][1];

    if (x[1][1] != 'X') s += x[1][1];

    if (x[1][0] != 'X') s += x[1][0];



    for (int i = 0; i < 2; ++ i){

    	for (int j = 0; j < 2; ++ j){

    		cin >> x[i][j];

    	}

    }

    string t;

    if (x[0][0] != 'X') t += x[0][0];

    if (x[0][1] != 'X') t += x[0][1];

    if (x[1][1] != 'X') t += x[1][1];

    if (x[1][0] != 'X') t += x[1][0];

    

    

    t += t;

    for (int i = 0; i < 4; ++ i){

    	if (s[0] == t[i] && s[1] == t[i + 1] && s[2] == t[i + 2]) {

    		cout << "YES";

    		return 0;

    	}

    }

    cout << "NO";

}