#include<bits/stdc++.h>

using namespace std;

/* ascii value A=65, Z=90, a=97, z=122, 0=48, 9=57*/ 

typedef long long ll;

typedef long double ld;

typedef long long int lli;

typedef unsigned long long int uns;

typedef std::vector<int> vi;

typedef std::vector<long long> vll;

typedef std::vector<long double> vld;

typedef std::pair<int,int> pii;

typedef std::pair<long long,long long> pll;

typedef std::priority_queue<long long> prioritysort1;

typedef std::priority_queue<long long, vector<long long>, greater<long long>> prioritysort2;

typedef std::priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>> >prioritypair;



#define mod 1000000007

#define ss endl;

#define pb push_back

#define f first

#define s second

#define all(x) (x).begin(), (x).end()

#define pre(x,y) setprecision(y)<<x

#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



//----------------------------------------------------------------------------------------//

 

int gcd(int a,int b){ if(b==0) return a; else return gcd(b,a%b); }           

long long reverse(long long n){int r;int sum=0;while(n>0){r=n%10;sum=(sum*10)+r;n=n/10;}return sum;}           

bool prime(unsigned long long int n){if(n <= 1)if(n <= 1)if(n <= 1){return false;}if(n == 2 || n == 3){return true;}if (n % 2 == 0 || n % 3 == 0){return false;}for (unsigned long long i = 5; i <= sqrt(n); i+=6){if (n % i == 0 || n % (i+2) == 0){return false;}}return true;}

uns factorial(int n){ return (n==1 || n==0) ? 1: n * factorial(n - 1);}

bool is_sorted(int arr[],int n){int x=0; for(int i=0; i<n-1; i++){if(arr[i]<=arr[i+1]){x++;}} if(x==n-1){return 1;}else{return 0;}}



//----------------------------------------------------------------------------------------//

 

int32_t main()

{

 	#ifndef ONLINE_JUDGE

    	freopen("input.txt","r",stdin);

    	freopen("output.txt","w",stdout);

    #endif

    FastIO;

 

    int t;

    cin>>t;

    while(t--)

    {

    	int n,count=0,one=0; cin>>n;

    	int arr[n],arr1[n];

    	for(int i=0; i<n; i++)

    	{

    		cin>>arr[i];

    		arr1[i]=arr[i];

    	}

    	sort(arr1,arr1+n);

    	for(int i=0; i<n; i++)

    	{

    		if(arr[i]!=arr1[i]){count++;}

    	}

    	cout<<count/2<<ss;





    } 

    return 0;

}