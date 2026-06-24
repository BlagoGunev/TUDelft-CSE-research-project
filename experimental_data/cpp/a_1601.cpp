#include <bits/stdc++.h>

using namespace std;





#define int long long 

#define mod 1000000007



void printAllDivisors(vector<int> &arr, int N)

{

    int g = arr[0];

    set<int> divisors;

    for (int i = 1; i < N; i++) {

        g = __gcd(arr[i], g);

    }

    for (int i = 1; i * i <= g; i++) {

        if (g % i == 0) {

            divisors.insert(i);

            if (g / i != i)

                divisors.insert(g / i);

        }

    }

    for (auto& it : divisors)

        cout << it << " ";

        cout<<endl;

}



int32_t main() {

ios_base::sync_with_stdio(false);

cin.tie(NULL);

int t; t=1;

cin>>t;



while(t--){

    bool zero=true;

   int n; cin>>n;

   int tempn=n;

   vector<int> onebit(32,0);

   while(n--){

    int num; cin>>num;

      int bit=0;

      while(num)

      {

         if(num&1)

        {

        zero=false;

        onebit[bit]++;

        }

         num=num>>1;

         bit++;

      }

   }

   if(zero)

   {

    for(int i=1; i<=tempn; i++ )

    cout<<i<<" ";

    cout<<endl;

   }

   else

   printAllDivisors(onebit,onebit.size());

   

}

return 0;

}