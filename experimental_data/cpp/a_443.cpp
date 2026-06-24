#include<iostream>

#include<string>

#include<set>

using namespace std;



int main()

{

    string a;

    getline(cin,a);



    set <char> b;

    for(int i=0;i<a.length();i++)

    {if(a[i]>='a' && a[i]<='z')

     b.insert(a[i]);

    }



    cout << b.size();





}