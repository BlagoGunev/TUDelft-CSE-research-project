//Lukasz Janeczko Krakow

#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false);

    int n, k;

    cin >> n >> k;

    string a;

    cin >> a;

    for(int h=0; h<k; h++)

        a.push_back(a[h]);

    long long p=10000103, q=100000000019; long long X[k+3];

    X[0]=1;

    for(int i=1; i<k+3; i++)

        X[i]=(X[i-1]*p)%q;

    long long Hashes[n*k];

    Hashes[0]=0;

    for(int j=0; j<k; j++)

        Hashes[0]=(Hashes[0]+X[k-j-1]*a[j])%q;

    for(int j=1; j<n*k; j++)

        Hashes[j]=(Hashes[j-1]*p-a[j-1]*X[k]+a[j+k-1]+p*q)%q;

    int g;

    cin >> g;

    long long hash0=0; vector < pair <long long , int> > Games(g);

    for(int h=0; h<g; h++)

        {

            string b;

            cin >> b;

            for(int j=0; j<k; j++)

                hash0=(hash0+X[k-j-1]*b[j])%q;

            Games[h]={hash0,h+1};

            hash0=0;

        }

    sort(Games.begin(),Games.end());

    bool found=false;

    for(int i=0; i<k && !found; i++)

        {

             bool x=true; int l, am=0; pair <long long , int> w1; int Ans[n]; vector <int> To_sort(n);

             while(x && am<n)

                 {

                     w1={Hashes[am*k+i],0};

                     l=lower_bound(Games.begin(),Games.end(),w1)-Games.begin();

                     w1.second=2100000000;

                     if(lower_bound(Games.begin(),Games.end(),w1)-Games.begin()!=l)

                        {

                            Ans[am]=Games[l].second;

                            To_sort[am]=Games[l].second;

                            am++;

                        }

                    else

                        x=false;

                 }

            if(x)

                {

                    sort(To_sort.begin(),To_sort.end());

                    int e=unique(To_sort.begin(),To_sort.end())-To_sort.begin();

                    if(e==n)

                        {

                            cout << "YES" <<endl << Ans[0];

                            for(int f=1; f<n; f++)

                                cout << " " << Ans[f];

                            cout <<endl;

                            found=true;

                        }

                }

        }

    if(!found)

        cout << "NO" <<endl;

    return 0;

}