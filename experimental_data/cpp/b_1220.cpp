#include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        int dl;
        cin>>dl;
        vector <long long> liczby(dl);
        vector <long long> liczby2(dl);
        for(auto &x:liczby)
            cin>>x;
        for(auto &x:liczby2)
            cin>>x;
        long long x=liczby[1];
        long long y=liczby2[2];
        long long z=liczby[2];
        long long czynnik=sqrt((z*x)/y);
        cout<<czynnik<<' ';
        for(int i = 1; i < dl; i++)
        {
            cout<<liczby[i]/czynnik<<' ';
        }

        return 0;
    }