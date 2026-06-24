#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    if (N%2==0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (int i=1;i<=2*N;i++) if (i<=N) {
            if (i%2==1) cout << i*2 << " ";
            else cout << i*2-1 << " ";
        }
        else {
            if (i%2==1) cout << (i-N)*2 << " ";
            else cout << (i-N)*2-1 << " ";
        }
}