#include <iostream>



using namespace std;



int main(){

    string grass = "";

    cin >> grass;

    int best = 0;

    int cont = 1;

    for(int i = 0; i < grass.length(); i++){



            if(grass[i] == 'A' || grass[i] == 'E' || grass[i] == 'I' || grass[i] == 'O' || grass[i] == 'U' || grass[i] == 'Y'){

                cont = 1;

            }else{

                cont++;

            }

        if(cont > best)

            best = cont;

    }

    cout << best << endl;



    return 0;

}