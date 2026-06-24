#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solution()
{
    string str, str1 = "yes";
    cin >> str;
  	
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    if(str1 == str)
    	cout << "YES" << '\n';
    else
    	cout << "NO" << '\n';
    
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    cin >> t;
    while(t--){
        solution();
    }

    return 0;
}