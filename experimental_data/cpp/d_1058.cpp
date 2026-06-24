#include<bits/stdc++.h>

using namespace std;

#define int long long

int mdc(int x,int y){
  if(y == 0) return x;
  return mdc(y,x%y);
}

#undef int
int main(){
#define int long long

  int n , m ,k;

  cin >> n >> m >> k;

  int a = mdc(n,k);
  int b = mdc(m,k/a);

  if(a != 1) n *= 2;
  else if(b != 1) m *= 2;
  else{
    if(k == 2){
      cout << "YES" << endl;
      cout << 0 << " " << 0 << endl;
      cout << n << " " << 0 << endl;
      cout << 0 << " " << m << endl; 
      return 0;
    }

    cout << "NO" << endl;
    return 0;
  }

  if(k/(a*b) > 2){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  if(k/(a*b) == 1){
    cout << 0 << " " << 0 << endl;
    cout << n/a << " " << 0 << endl;
    cout << 0 << " " << m/b << endl;
  }
  else{
    if((n/a)%2 == 0) n /= 2;
    else m /= 2;

    cout << 0 << " " << 0 << endl;
    cout << n/a << " " << 0 << endl;
    cout << 0 << " " << m/b << endl;
  }
}