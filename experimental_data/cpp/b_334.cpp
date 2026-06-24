#include <iostream>

#include <vector>

#include <set>

#include <utility>

using namespace std;



int main()

{

    set <int> row, col;

    set <pair<int, int> > cdt;

    int x[8], y[8];

    

    while (cin >> x[0] >> y[0])

    {

		for (int i = 1; i < 8; i++)

            cin >> x[i] >> y[i];

            

        for (int i = 0; i < 8; i++)

        {

        	row.insert(y[i]);

        	col.insert(x[i]);

        	cdt.insert(make_pair(x[i], y[i]));

        }

        

        vector <int> r, c;

        copy(row.begin(), row.end(), back_inserter(r));

        copy(col.begin(), col.end(), back_inserter(c));

        

        if (r.size() == 3 && c.size() == 3)

        {

        	int i = 0, j = 0;

        	

			for (i = 0; i < 3; i++)

			{

				for (j = 0; j < 3; j++)

				{

					if (i == 1 && j == 1)

        				continue;

        				

        			if (cdt.find(make_pair(c[i], r[j])) == cdt.end())

        				break;

				}

				

				if (j != 3)

					break;

			}

        				

        	if (i == 3 && j == 3)

				cout << "respectable" << endl;

			else

				cout << "ugly" <<endl;

        }

        else

            cout << "ugly" <<endl;

    }

    

    return 0;

}

/*

1 1

1 2

1 3

2 1

2 2

3 1

3 2

3 3

*/