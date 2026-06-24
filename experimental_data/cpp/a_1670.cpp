#include<bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

#define deb(x) cout << #x << " " << x << endl;

#define deb1(x,y) cout<<#x<<" "<<x<<" , "<<#y<<" "<<y<<endl;

#define deb2(x,y,z) cout<<#x<<" "<<x<<" , "<<#y<<" "<<y<<" , "<<#z<<" "<<z<<endl;

#define endn "\n"

#define ll long long int

#define pb push_back

#define mp make_pair

#define ss second

#define ff first

#define M 1000000007

const int N = 1e5 + 10;



int small=INT_MIN;

int large=INT_MAX;



vector<int> primeSieve(int n){

    int p[n+1]={0};

    for(int i=3;i<=n;i+=2)

        p[i]=1;

    for(int i=3;i*i<=n;i+=2)

        if(p[i]==1)

            for(int j=i*i;j<=n;j+=i)

                p[j]=0;

    p[2]=1;

    p[1]=p[0]=0;

    vector<int> prime;

    for(int i=2;i<=n;++i)

        if(p[i]==1)

            prime.push_back(i);

    return prime;

}



int main() {

    fast_cin(); 



    int t;

    cin>>t;

    while(t--)

    {

        int n;

        cin>>n;

        int a[n], neg=0;

        for(int i=0;i<n;++i)

        {

            cin>>a[i];

            if(a[i]<0)

            {

                neg++;

            }

        }

        int idx=0;

        while(neg--)

        {

            a[idx]=-abs(a[idx]);

            idx++;

        }

        for(int i=idx;i<n;++i)

        {

            a[i]=abs(a[i]);

        }

        int flag=1;

        for(int i=0;i<n-1;++i)

        {

            if(a[i]>a[i+1])

            {

                flag=0;

                break;

            }

        }

        if(flag==0)

        {

            cout<<"NO";

        }

        else

        {

            cout<<"YES";

        }

        cout<<endn;



    }

   

    return 0;

}