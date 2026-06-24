//JAI SHREE RAM



#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define ll long long 

#define endl "\n" 

#define cin(a,n) for(long long i=0;i<n;i++){cin>>a[i];}

#define pb push_back

#define pp pop_back

#define eb emplace_back

#define mp make_pair

#define lb lower_bound

#define ub upper_bound

#define vv(n,m) vector<vector<long long>>vv(n,vector<long long>(m))   //n is rows , m is columns

#define vl vector<long long>

#define vs vector<string>

#define vc vector<char>

#define f(i,n) for(long long i=0;i<n;i++)

#define vps vector<pair<long long,string>>

#define vp vector<pair<long long,long long>>

#define sa(a,n) sort(a, a + n)

#define sv(v) sort(v.begin(), v.end())

#define all(v) v.begin(),v.end()



//For policy based data structures:-



//order_of_key (K): Number of items strictly smaller than K

//find_by_order(k): Kth element in a Set (counting from zero)



//deleting element in ordered multiset:-

//ordered_multiset::iterator it = v.find_by_order(v.order_of_key(a[i]));

//v.erase(it);



//deleting element in ordered set:-

//ordered_set::iterator it = v.find_by_order(v.order_of_key(a[i]));

//v.erase(it);





using namespace std;

using namespace __gnu_pbds;





typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_multiset;



typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;





//Tips:-





//Logic -----> Code .



//emplace_back ---> Better and faster option of push_back . 



//If you want to count occurences of an element in an sorted array/string , use lower_bound and upper_bound .



/*If you want to use binary search (to check whether a particular element exists or not) without sorting the elements of an array or vector ,

then use set count() inbuilt-function . Make a set of all the elements of the array/vector (making set already sorts the elements) , then use set_name.count(particular_element) if

it returns 1 then the element exists but if it returns 0 then the elemnet doesnot exists .*/



//vector pairs can be sorted by first entry as well as by second entry .



//use stl for better and faster outputs .



//search for stl whenever confused for a particular task in code/logic .



//If swapping elements from forwards is not giving right answer , then try swapping elements from backwards , it might work .



//In questions involving sum of elements of an array/vector , greedily adding the items from largest to smallest or vice versa may help .



// 32768=2^15 .



// Don't forget modulo at last step .



// Sieve me i and factors me i*i hota hai , mistake mat karna .



// Wanting to implement double upper_bound or something complex , then can use upper_bound on vector of pairs .



//stuck due to double values , then can see 1616-C:Representative Edges code .



// Agar cases kam ho then , brute force kar do using next_permutation function :)) .



//try to solve the question mathematically,generalising or by pattern identification . 



//if the question asks for the maximum/minimum value , check whether binary search can be applied or not .



// If things are linear , then think mathematically taking general terms , and try to get a formula .



// Digits and Alphabets are very less and limited i.e. 10 and 26 respectively .



// If no idea comes , think from the point of view of author , why he used that particular things . Like he may be using powers of two for set bits or so .



// Whenever stuck , have clear thoughts , try to prove the solution .



//-----------------------------------------actual code starts from here----------------------------------------------



void solve(){

    ll n;

    cin>>n;

    ll a[n];

    cin(a,n);

    ll poss[n+1];

    f(i,n+1){

        poss[i]=0;

    }

    poss[0]=1;

    f(i,n){

        if(poss[i]==1&&(i+a[i]+1)<=n){

            poss[i+a[i]+1]=1;

        }

        if((i-a[i])<=n&&(i-a[i])>=0&&poss[i-a[i]]==1){

            poss[i+1]=1;

        }

    }

    if(poss[n]==1){

        cout<<"YES"<<endl;

    }else{

        cout<<"NO"<<endl;

    }



    return;

}



int main(){



    //faster submission

    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    #endif



    //faster input and output

    std::ios::sync_with_stdio(false);

    std::cin.tie(0);



    ll t;

    cin>>t;

    while(t--){

        solve();

    }

    // solve();



    return 0;

}