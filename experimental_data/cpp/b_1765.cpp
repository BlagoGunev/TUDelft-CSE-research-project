#include <bits/stdc++.h>



using namespace std;



int main()

{

  int t;

  cin >> t;

  while(t--){

    int n, cnt = 0, f = 0;

    cin >> n;

    string str;

    cin >> str;



    for(int i = 1; i < n; i+=3){

      if(str[i] != str[i+1]){

        f = 1;

        break;

      }

    }



    if((n%3) != 2 && f == 0){

      cout << "YES" << endl;

    }

    else{

      cout << "NO" << endl;

    }

    

  }

}