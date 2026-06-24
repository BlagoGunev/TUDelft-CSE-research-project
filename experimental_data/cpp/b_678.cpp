#include <iostream>



using namespace std;



    bool isleap(int year){

    if(year % 4 != 0)  return false;

    else if (year % 100 != 0) return true;

    else if(year % 400 != 0) return false;

    else return true;



}



int main()

{



    int y;

    long long c=0;



    cin>>y;



    for(int i=y+1; i<90000000; i++)

    {

        if(isleap(i))c+=366;

        else c+= 365;

         if(c%7 == 0)

         {

             if(!(isleap(i) xor isleap(y))){

             cout<<i<<endl;

             return 0;

             }

         }

    }





   // cout << t << endl;

    return 0;

}