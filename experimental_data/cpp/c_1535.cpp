#include <bits/stdc++.h>

using namespace std;



#define ar array

#define ll long long int

#define ld long double

#define sz(x) ((int)x.size())

#define all(a) (a).begin(), (a).end()

#define rall(a) (a).rbegin(), (a).rend()

#define pb push_back

#define ppb pop_back

#define vll vector<long long int>

#define vi vector<int>

#define PrintArray(arr) for(int i=0;i<(int)arr.size();i++)cout<<arr[i]<<" ";cout<<"\n";

#define lowerb lower_bound

#define upperb upper_bound



const long long MAX_SIZE = 1000001;

const int MAX_N = 1e5 + 5;

const ll MOD = 1e9 + 7;

const ll INF = 2e18;

const ld EPS = 1e-9;

//----------------------------------------------Functions---------------------------------------------------//

bool isPrime(int n)

{

    // Corner case

    if (n <= 1)

        return false; 



    // Check from 2 to square root of n

    for (int i = 2; i <= sqrt(n); i++)

        if (n % i == 0)

            return false;



    return true;

}





vector<ll> SieveOfEratosthenes(int n)

{

    vector <ll> ans;

    bool prime[n + 1];

    memset(prime, true, sizeof(prime));



    for (int p = 2; p * p <= n; p++)

    {

        if (prime[p] == true)

        {

            for (int i = p * p; i <= n; i += p)

                prime[i] = false;

        }

    }

    for (int p = 2; p <= n; p++)

        if (prime[p])

            ans.pb(p);

    return ans;

}







int smallest_digit(ll n)

{

    // int largest = 0;

    int smallest = 9;



    while (n) {

        int r = n % 10;



        // Find the largest digit

        // largest = max(r, largest);



        // Find the smallest digit

        smallest = min(r, smallest);



        n = n / 10;

    }

    return smallest;

}





int largest_digit(ll n)

{

    int largest = 0;



    while (n) {

        int r = n % 10;



        // Find the largest digit

        largest = max(r, largest);



        // Find the smallest digit



        n = n / 10;

    }

    return largest;

}





int BigPower(long long x, unsigned int y, int p)

{

    int res = 1;     // Initialize result



    x = x % p; // Update x if it is more than or

                // equal to p



    if (x == 0) return 0; // In case x is divisible by p;



    while (y > 0)

    {

        // If y is odd, multiply x with result

        if (y & 1)

            res = (res*x) % p;



        // y must be even now

        y = y>>1; // y = y/2

        x = (x*x) % p;

    }

    return res;

}



string MinValue(string N, int X)

{

 

    // Variable to store length

    // of string N

    int len = N.size();

 

    // Variable to denote the position

    // where X must be added

    int position = len + 1;

 

    // If the given string N represent

    // a negative value

    if (N[0] == '-') {

        // X must be place at the last

        // index where is greater than N[i]

        for (int i = len - 1; i >= 1; i--) {

            if ((N[i] - '0') < X) {

                position = i;

            }

        }

    }

    else {

        // For positive numbers, X must be

        // placed at the last index where

        // it is smaller than N[i]

        for (int i = len - 1; i >= 0; i--) {

            if ((N[i] - '0') > X) {

                position = i;

            }

        }

    }

    // Insert X at that position

    N.insert(N.begin() + position, X + '0');

 

    // Return the string

    return N;

}

 



int getSum(string str)

{

    int sum = 0;

  

    // Traversing through the string

    for (int i = 0; i < str.length(); i++) {

        // Since ascii value of

        // numbers starts from 48

        // so we subtract it from sum

        sum = sum + str[i] - 48;

    }

    return sum;

}



  

int getClosest(int, int, int); 

  

// Returns element closest to target in arr[] 

int findClosest(vll arr, int n, ll target) 

{ 

    // Corner cases 

    if (target <= arr[0]) 

        return arr[0]; 

    if (target >= arr[n - 1]) 

        return arr[n - 1]; 

  

    // Doing binary search 

    int i = 0, j = n, mid = 0; 

    while (i < j) { 

        mid = (i + j) / 2; 

  

        if (arr[mid] == target) 

            return arr[mid]; 

  

        /* If target is less than array element, 

            then search in left */

        if (target < arr[mid]) { 

  

            // If target is greater than previous 

            // to mid, return closest of two 

            if (mid > 0 && target > arr[mid - 1]) 

                return getClosest(arr[mid - 1], 

                                  arr[mid], target); 

  

            /* Repeat for left half */

            j = mid; 

        } 

  

        // If target is greater than mid 

        else { 

            if (mid < n - 1 && target < arr[mid + 1]) 

                return getClosest(arr[mid], 

                                  arr[mid + 1], target); 

            // update i 

            i = mid + 1;  

        } 

    } 

  

    // Only single element left after search 

    return arr[mid]; 

} 

  

// Method to compare which one is the more close. 

// We find the closest by taking the difference 

// between the target and both values. It assumes 

// that val2 is greater than val1 and target lies 

// between these two. 

int getClosest(int val1, int val2, 

               int target) 

{ 

    if (target - val1 >= val2 - target) 

        return val2; 

    else

        return val1; 

} 

//----------------------------------------------Code---------------------------------------------------//



void solve()

{

    string s;

    cin >> s;

    int n = sz(s);

    ll dp[n + 1][2];

    memset(dp, 0, sizeof(dp));

    ll ans = 0;

    dp[0][0] = 0;

    dp[0][1] = 0;

    for (int i = 1; i <= n; i++)

    {

        if (s[i - 1] == '?')

        {

            dp[i][0] = dp[i - 1][1] + 1;

            dp[i][1] = dp[i - 1][0] + 1;

        }

        else if (s[i - 1] == '0')

        {

            dp[i][0] = dp[i - 1][1] + 1;

            dp[i][1] = 0;

        }

        else

        {

            dp[i][0] = 0;

            dp[i][1] = dp[i - 1][0] + 1;

        }

        ans += max(dp[i][0], dp[i][1]);

    }

    cout << ans << endl;

}







//-----------------------------------------------------------------------------------------------------//



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0); cout.tie(0);

    int tc = 1;

    cin >> tc;

    for (int t = 1; t <= tc; t++) {

        // cout << "Case #" << t << ": ";

        solve();

    }

    return 0;

}