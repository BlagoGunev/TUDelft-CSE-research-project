#include <bits/stdc++.h>



using namespace std;



#define F first

#define S second



int main()

{

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

    int a , b;

    cin >> a >> b;

    cout << min(a , b) << " " << (max(a , b) - min(a , b)) / 2;

    return 0;

}