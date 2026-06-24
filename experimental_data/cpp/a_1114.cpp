#include <iostream>
using namespace std;
int main(){
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    bool q1, q2, q3;
    if(x <= a) q1 = true;
    else q1 = false;

    if(a-x+b >= y) q2 = true;
    else q2 = false;

    if(a+b+c-x-y-z >= 0) q3 = true;
    else q3 = false;
    if(q1 == true && q2 == true && q3 == true){
        cout << "YES";
        
    }
    else cout << "NO";
    /*int r1 = a-x;
    int r2 = r1+c-y;
    int r3 = r2+b-z;
    if(r1 >= 0 && r2 >= 0 && r3 >= 0) cout << "YES";
    else cout << "NO";*/
}