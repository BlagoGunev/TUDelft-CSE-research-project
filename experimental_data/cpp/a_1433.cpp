#include <iostream>

#include <map>



using namespace std;



int main()

{

    int t; cin >> t;

    while (t--)

    {

        int x; cin >> x;

        cout << (x/10==0 ? x*10-9 : (x/100==0 ? x%10*10-7: (x/1000==0 ? x%10*10-4 : x%10*10))) << endl;

    }

    return 0;

}