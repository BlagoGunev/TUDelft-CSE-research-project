#include <bits/stdc++.h>

#define MAXN 1000+10

#define ll long long

using namespace std;



int a[MAXN];



int main()

{

    int n, x0, y0, flag=0;

    set<double>st;

    cin >> n >> x0 >> y0;

    while(n--)

    {

        int x, y;

        cin >> x >> y;

        if(x-x0==0) flag=1;

        else

        {

    //        cout << "**" << endl;

            st.insert((y-y0)*1.0/(x-x0));

        }

    }

//    cout << st.size() << endl;

    cout << (flag+st.size()) << endl;

    return 0;

}