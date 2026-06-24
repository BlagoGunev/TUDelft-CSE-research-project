#include<bits/stdc++.h>



using namespace std;

#define IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define ll long long

#define ld long double



const int N = 1e2+5;



int a[N][N];



int main() {



    IO;



    int t;

    cin>>t;

    while(t--)

    {

        int n;

        cin>>n;

        int lst;

        for (int i = 0; i < n; i++)

        {

            for (int j = 0; j < n-1; j++)

                cin>>a[i][j];

            if (i && a[i][n-2] == a[i-1][n-2])

                lst = a[i][n-2];

            else if (i > 1 && a[i][n-2] == a[i-2][n-2])

                lst = a[i][n-2];

        }

        for (int i = 0; i < n; i++)

        {

            bool found = false;

            for (int j = 0; j < n-1 && !found; j++)

            {

                if (a[i][j] == lst)

                    found = true;

            }

            if (!found)

            {

                for (int j = 0; j < n-1; j++)

                    cout<<a[i][j]<<' ';

                cout<<lst<<'\n';

                break;

            }

        }

    }



}