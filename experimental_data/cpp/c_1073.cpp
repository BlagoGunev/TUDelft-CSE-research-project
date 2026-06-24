#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*char anti(char c) {
switch(c) {
case 'L': return 'R';
case 'R': return 'L';
case 'U': return 'D';
case 'D': return 'U';
}
}*/

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    char a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int x, y;
    cin>>x>>y;

    int U=0, D=0, L=0, R=0;

    for(int i=0; i<n; i++) {
        switch(a[i]) {
        case 'U': U++; break;
        case 'D': D++; break;
        case 'L': L++; break;
        case 'R': R++; break;
        }
        }

    if (abs(x)+abs(y)>n) {
        cout<<-1;
        return 0;
        }

    if ((abs(x)+abs(y))%2!=n%2) {
        cout<<-1;
        return 0;
        }

    int j=-1, i=-1; /// (a; b]
    int l=0;

    int curx = R-L;
    int cury = U-D;

    if ((curx==x)&&(cury==y)) {
        cout<<0;
        return 0;
        }

    int ans = n+1;

    while(true) {
        while(abs(x-curx)+abs(y-cury)>l) {
            i++;
            if (i==n) break;
            l++;
            switch(a[i]) {
            case 'U': U--; break;
            case 'D': D--; break;
            case 'L': L--; break;
            case 'R': R--; break;
            }
            curx = R-L;
            cury = U-D;
            }
        if (i==n) break;

        while(abs(x-curx)+abs(y-cury)<=l) {
            j++;
            l--;
            switch(a[j]) {
            case 'U': U++; break;
            case 'D': D++; break;
            case 'L': L++; break;
            case 'R': R++; break;
            }
            curx = R-L;
            cury = U-D;
            }

        //cout<<j<<' '<<i<<endl;
        if (l+1<ans) ans=l+1;
        }

    cout<<ans;
    return 0;
}