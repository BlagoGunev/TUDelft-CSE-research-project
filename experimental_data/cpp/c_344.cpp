#include <bits/stdc++.h>



using namespace std;



#define ll64 long long



int main()

{

    ll64 top, bot;

    cin >> top >> bot;

    ll64 ans = 0;

    if(top < bot) swap(top, bot);

    while(bot){

        ans += top / bot;

        top = top % bot;

        if(top < bot) swap(top, bot);

    }

    cout << ans << "\n";

}