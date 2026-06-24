#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = (int)2e5 + 1;
int arr[N],lmx[N], rmx[N];


void solve() {
      int n;
      cin >> n;
      for(int i = 0; i < n; i++) cin >> arr[i];

      int left[n], right[n];
      for(int i = 0; i < n; i++) left[i] = right[i] = -1;

      stack<int> st;
      int mx = -1;
      for(int i = 0; i < n; i++){
            mx = max(mx, arr[i]);
            lmx[i] = mx;
            while( st.size() and arr[ st.top() ] >= arr[i] ) st.pop();
            left[i] = (st.size() ? st.top(): -1 );
            st.push(i);
      }

      mx = -1;
      while(st.size()) st.pop();
      for(int i = n - 1; i >= 0; i--){
            mx = max(mx, arr[i]);
            rmx[i] = mx;
            while( st.size() and arr[ st.top() ] >= arr[i] ) st.pop();
            right[i] = (st.size() ? st.top(): -1 );
            st.push(i);
      }

      for(int i = 1; i < n - 1; i++){
            int i1 = left[i], i2 = right[i];
            
            if( i1 == -1 ) i1 = 0;
            if( i2 == -1 ) i2 = n - 1;

            if( lmx[i1] > arr[i] or rmx[i2] > arr[i] ) continue;
            if( lmx[i1] < arr[i] ) {
                  if( i1 + 1 == i or arr[i1 + 1] != arr[i] ) continue;
                  i1++;
            }

            if( rmx[i2] < arr[i] ){
                  if( i2-1 == i or arr[i2-1] != arr[i] ) continue;
                  i2--;
            }

            cout << "YES" << endl;
            //cout << arr[i] << endl;
            int x = i1 + 1, z = n - i2, y = n - x - z;
            cout << x << " " << y << " " << z << endl;
            return;
      }
      cout << "NO" << endl;
}


int32_t main()
{
      ios_base::sync_with_stdio(0);   
      cin.tie(0);   
      cout.tie(0);
 
      int test = 1;
       cin >> test;
      while(test--)solve();

}