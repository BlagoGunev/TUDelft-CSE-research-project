#include <bits/stdc++.h>

using namespace std ;

#define read freopen("input.txt", "r", stdin);

#define write freopen("output.txt", "w", stdout);

#define ll long long

#define ld long double

#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define yn(f,yes,no) if(f) {cout<<yes<<'\n';} else {cout<<no<<'\n';}

//ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

void fillPrefixSum(int arr[], int n, int prefixSum[])

{

    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++)

    {

        prefixSum[i] = prefixSum[i - 1] + arr[i];

    }



}

void selectionsort(ll arr[],ll n)

{

    for (int i = 0; i < n-1; ++i)

    {

        ll m=i;

        for (int j = i+1; j <n ; ++j)

        {

            if(arr[m]>arr[j])

            {

                m=j;

            }

        }

        swap(arr[i],arr[m]);

    }

}

void bubblesort(ll arr[],ll n)

{

    for (int i = 0; i <n-1 ; ++i)

    {

        for (int j = 0; j < n-i-1; ++j)

        {

            if(arr[j]>arr[j+1])

            {

                swap(arr[j],arr[j+1]);

            }

        }

    }

}

void insertionSort(ll arr[],ll n)

{

    ll kay,j;

    for (int i = 1; i <n ; ++i)

    {

        kay=arr[i];

        j=i-1;

        while (j>=0&&arr[j]>kay)

        {

            arr[j+1]=arr[j];

            j=j-1;

        }

        arr[j+1]=kay;

    }

}

ll binarySearch(ll arr[], ll l, ll h, ll element)

{

    while (l <= h) {



        ll m = (l + h) / 2;





        if (arr[m] == element)

            return m;



        if (arr[m] > element)



            h = m - 1;



        else



            l = m + 1;



    }



    return -1;

}

bool cmp(string i, string j)

{



    return i.size()>j.size();

}



int main ()

{

    fast

    ll t;

    cin>>t;

    while (t--)

    {

        map<ll,ll>mp;

        ll n,m,cu=0;

        cin>>n>>m;

        for (ll i = 0; i <n+m ; ++i)

        {

            ll x;

            cin>>x;

            mp[x]++;

        }

        for (ll i = 1; i <=100 ; ++i)

        {

         if(mp[i]>1)

         {

             cu++;

         }

        }

        cout<<cu<<'\n';



    }





    return 0;

}