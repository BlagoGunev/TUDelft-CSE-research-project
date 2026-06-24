#include <bits/stdc++.h>

using namespace std;

int arr[10010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
		int n; cin >> n;

		int ch=0;
		for (int i=1; i<=n; i++){
			cin >> arr[i];
			if (arr[i-1]<=arr[i]){}
			else ch=1;
		}

		if (ch==1) cout << "YES\n";
		else cout << "NO\n";
    }

    return 0;
}