# include <bits/stdc++.h>

# define ll  long long

# define se second

# define INF 1e15

# define fr first

using namespace std;

ll n , ans = 0 , pre[1000];

void f(ll x , ll n , ll  lol){

   // cout<<pol<<' '<<pre[x]<<' '<<x<<' '<<n<<' '<<lol<<'\n';

      //   cout<<n<<' '<<x<<' '<<lol<<'\n';

    //cout<<ans<<'\n';

    if(x == 0) return ;

    if(lol == 1){

        if(pre[x - 1]  < n)

        {

            //cout<<pre[x]<<'\n';

            ans += pre[x];

            f(x - 1 , n - pre[x - 1] , lol);

        }

        else {

                ans++;

                //cout<<ans<<'\n';

            f(x - 1 , n , lol % 2 + 1);

        }

    }

    else{

        if(pre[x - 1] >= n)

        {

            ans += pre[x];

          //  cout<<ans<<'\n';

            f(x - 1 , n , lol );

        }

        else {

            ans ++;

        //    cout<<ans<<'\n';

            f(x - 1 , n - pre[x - 1] , lol % 2 + 1);

        }

    }

}

int main()

{

    ll n , h , i , pro = 1;

    cin>> h>> n;

    pre[0] = 1;

    for(i = 1 ; i <= 52 ; i ++) pre[i] = pre[i - 1] * 2;

    f(h , n , 1);

    cout<<ans;

}