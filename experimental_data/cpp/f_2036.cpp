// Have mercy upon us, O arav, our savior

#include<bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #include "anshul.cpp"
    extern void sublime();
#else
    #define see(...) 42
#endif 

#define int long long
using namespace std;

// Function to compute XOR from 0 to n
long long xorFromZero(long long n) {
    switch(n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0; // This will never be reached
}

// Function to compute XOR of range [l, r]
long long xorr(long long l, long long r) {
    return xorFromZero(r) ^ xorFromZero(l - 1);
}

void solve()
{
   int l, r, i, k;
   cin >> l >> r >> i >> k;
   
   int ans = xorr(l, r);
   
   int temp = l;
   temp -= k;
   
   int f = (temp + (1ll<<i) - 1)/(1ll<<i)*(1ll<<i);
   f = f + k;

   temp = r - k;
   int last = temp/(1ll<<i)*(1ll<<i);
   last = last + k;
   
   int ff = (f>>i);
   int ss = (last>>i);
   int hi = xorr(ff, ss);
   if(f > r)
   {
    cout << ans << endl;
    return;
   }
   
   if(((last - f)/(1ll<<i)) % 2 == 1)
    {
        cout << (ans^(hi<<i)) << endl;
    }
    else
        cout << ((ans^(hi<<i))^k) << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE 
        sublime();
    #endif
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        #ifndef ONLINE_JUDGE 
            cout<<"-----------------"<<i+1<<endl;
        #endif
        solve();
    }

return 0;
}