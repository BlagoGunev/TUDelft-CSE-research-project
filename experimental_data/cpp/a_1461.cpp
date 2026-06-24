#include<bits/stdc++.h>



using namespace std;



void solve()

{

    int n , k;

    cin >> n >> k;

    deque<char> s;

    int Max = 'a';

    if(k % 2 == 1)

    {

        s.push_back(Max);

        Max++;

        k--;

        n--;

    }

    while(k > 0)

    {

        if(Max == 'd')

        {

            Max = 'a';

        }

        s.push_back(Max);

        s.push_front(Max);

        Max++;

        k -= 2;

        n -= 2;

    }

    while(n > 0)

    {

        if(Max == 'd')

        {

            Max = 'a';

        }

        s.push_back(Max);

        n--;

        Max++;

    }

    for(int i = 0 ; i < s.size() ; i++)

    {

        cout<<s[i];

    }

    cout<<"\n";

}



int main()

{

    int t;

    cin >> t;

    while(t > 0)

    {

        solve();

        t--;

    }

}