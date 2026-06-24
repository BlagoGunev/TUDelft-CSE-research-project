#include <iostream>

using namespace std;



const int N = 100 * 1000 +10;



bool l[N], w[N], dpw[N], dpl[N];



bool W(long long s, long long e)

{

    if(e%2ll == 1)

    {

        if(s%2ll == 1)

            return 0;

        else

            return 1;

    }

    long long up = e;

    long long down = (e/2ll) + 1;

    if(down <= s && s <= up)

    {

        if(s%2ll == 0)

            return 0;

        else

            return 1;

    }

    else

    {

        down = (e/4ll) + 1;

        if(down <= s)

            return 1;

        else

            return W(s, down-1);

    }

}



bool L(long long s, long long e)

{

    long long up = e;

    long long down = (e/2ll) + 1;

    if(down <= s && s <= up)

        return 1;

    else

        return W(s, down-1);

}

int main()

{

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



    int n; cin>>n;

    for(int i=1;i<=n;i++)

    {

        long long s, e; cin>>s>>e;

        l[i] = L(s, e);

        w[i] = W(s, e);

    }



    dpw[n] = w[n];

    dpl[n] = l[n];

    for(int i=n-1; i>=1; i--)

    {

        dpw[i] = (w[i] & (!dpw[i+1])) | (l[i] & dpw[i+1]);

        dpl[i] = (w[i] & (!dpl[i+1])) | (l[i] & dpl[i+1]);

    }



    cout<<dpw[1]<<" "<<dpl[1]<<flush;

    return 0;

}