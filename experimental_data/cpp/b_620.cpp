#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli cnt;

int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void fff(int n)

{

    while(n != 0){

        cnt += arr[n%10];

        n /= 10;

    }

}

int main()

{

    int a, b;

    cin >> a >> b;

    for(int i = a; i <= b; i++){

        fff(i);

    }

    cout << cnt << endl;

    return 0;

}