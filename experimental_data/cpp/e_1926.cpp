#include <bits/stdc++.h>
using namespace std;
#define    int        long long
#define pb push_back
#define ll  unsigned long long

int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
       return -1;
    else
      return (inv * a) % m;
}
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=1;i<=n;i=i*2){
        int x=2*i;
        int y=(n-i)/x;
        y++;
        if(y<k){
            k-=y;
        }
        else{
            int ans=i;
            ans+=(k-1)*x;
            cout<<ans<<endl;
            break;
        }
        
    }
   
    

   

    


  
  

 
 
}





 
    
    int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int _=1;
    cin>>_;  
    while(_--){
        solve(); 
    }
    return 0;

}