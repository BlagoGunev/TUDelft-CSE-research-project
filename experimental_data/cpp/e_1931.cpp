#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007

int find(int x) {
    int k1 = 0;
    while(x%10 == 0) {
        x/=10;
        k1++;
    } 
    return k1; 
}

int find2(int x) {
    int k1 = 0;
    while(x>0) {
        x/=10;
        k1++;
    }
    return k1; 
}


bool compare(int x, int y){
    return find(x)>find(y);
}

int main(){
    FIO;
    int t,n,k,i,j;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int a[n];
        
        for(i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a,a+n, compare);
        
        j=0;
        for(i=0;i<n;i++) {
            if(i%2==0)
                j+=find2(a[i])-find(a[i]);
            else
                j+=find2(a[i]);
        }
        
        if(j<=k)
            cout << "Anna\n";
        else
            cout << "Sasha\n";
        
    }
	return 0;
}