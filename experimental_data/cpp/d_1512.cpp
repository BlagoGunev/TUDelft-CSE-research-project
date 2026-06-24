#include <bits/stdc++.h>

#define lli long long int

#define pb push_back

#define pf push_front

#define endl "\n"

#define ff first

#define ss second

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);



using namespace std;



int main()

{

    fastio()

    

    int t;

    cin >> t;

    

    while(t--)

    {

        lli n;

        cin >> n;

        

        lli a[n+2],s=0;

        for(int i=0;i<n+2;i++) cin >> a[i],s+=a[i];

        

        sort(a,a+n+2);

        s-=a[n+1];

        

        lli c1=-1;

        for(int i=0;i<n+1;i++)

        {

            if(s-a[i]==a[n+1])

            {

                c1=i;

                break;

            }

        }

        

        if(c1!=-1)

        {

            for(int i=0;i<n+1;i++) if(i!=c1) cout << a[i] << " ";

            cout << endl;

        }

        

        else if(s-a[n]==a[n])

        {

            for(int i=0;i<n;i++) cout << a[i] << " ";

            cout << endl;

        }

        

        else cout << -1 << endl;

    }



    return 0;

}