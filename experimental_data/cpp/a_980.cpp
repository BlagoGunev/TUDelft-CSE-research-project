#include <iostream>

using namespace std;

string in;

int perl, link = 0;

int main()
{
  cin >> in;
  int i = 0;
  for (auto s : in)
  {
    if (s == '-')
    {
      link++;
    }
    else if (s == 'o')
    {
      perl++;
    }
    i++;
  }
  if (perl == 0)
  {
    cout << "YES" << endl;
    return 0;
  }

  if (link % perl == 0)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}