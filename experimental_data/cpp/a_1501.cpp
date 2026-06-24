/**

 * 

 * Author: withtahmid

 * Created: 06-08-2022

 * 

 * */

#include<bits/stdc++.h>

using namespace std;

#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#define endl "\n";

#define nl cout<<"\n"

#define ll  long long

#define nn int n; cin>>n

#define lln long long n; cin >> n

#define vi(n) vector<int>v(n)

#define vl(n) vector<long long>v(n)

#define srt(v) sort(v.begin(), v.end())

#define reverse(v) reverse(v.begin(), v.end())

#define ub(v,n) upper_bound(v.begin(), v.end(), n)

#define lb(v,n) lower_bound(v.begin(), v.end(), n)

#define pb push_back

#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)

#define debug cout<<"I am here\n";

template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }

template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";}



int main()

{

	boostIO

    test_case{

        nn;

        vector<pair<int,int>>stopage(n);

        vi(n);

        for(pair<int,int>& i : stopage)

            cin>>i.first>>i.second;

        cin>>v;

        int current_time  = stopage[0].first + v[0];

        for(int i = 1; i<n; i++)

        {

            current_time += ceil(double(stopage[i-1].second -stopage[i-1].first)/2);

            if(current_time < stopage[i-1].second) 

                current_time = (stopage[i-1].second);

            current_time += v[i] + (stopage[i].first) - (stopage[i-1].second);

        }

        cout << current_time << endl;

    }

}