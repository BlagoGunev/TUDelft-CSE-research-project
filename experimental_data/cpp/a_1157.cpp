#include <iostream>
#include <set>
using namespace std;


int cal(int n) {
    set<int> tmp;
    int cnt = 0;
    while(1) {
        n += 1;
        if(tmp.find(n) == tmp.end()) {
            cnt ++;
            tmp.insert(n);
        }
        else {
            break;
        }
        while(n % 10 == 0) n /= 10;
    }
    return cnt;
}

int main()
{
    int n;
    while(cin>>n) {
        cout<<cal(n)<<endl;
    }
    return 0;
}