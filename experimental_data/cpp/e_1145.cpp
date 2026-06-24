#include <bits/stdc++.h>
using namespace std;

int main () {
    for (int id = 21; id <= 50; id++)
        cout << ((((min(id,25)+id)%(2+id%3))>0) ? "1" :"0")<<endl;
}