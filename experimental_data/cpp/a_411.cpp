#include <iostream>
#include <string>
using namespace std;

bool has_cap(string s) {
  bool b = false;
  for (int i = 0; i < s.length(); i++) {
    if (int (s[i] - 'A') >= 0 && int (s[i] - 'Z') <= 0) {
      b = true;
    }
  }
  return b;
}

bool has_small(string s) {
  bool b = false;
  for (int i = 0; i < s.length(); i++) {
    if (int (s[i] - 'a') >= 0 && int (s[i] - 'z') <= 0) {
      b = true;
    }
  }
  return b;
}

bool has_char(string s) {
  bool b = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '!' || s[i] == '?' || s[i] ==  '.' || s[i] ==  ',' || s[i] ==  '_') {
      b = true;
    }
  }
  return b;
}

bool has_digit(string s) {
  bool b = false;
  for (int i = 0; i < s.length(); i++) {
    if (int (s[i] - '0') >= 0 && int (s[i] - '9') <= 0) {
      b = true;
    }
  }
  return b;
}

int main() {
  string s;
  cin>>s;
  cerr<<s.length()<<endl;
  if (s.length() >= 5 && has_cap(s) && has_digit(s) && has_small(s)) {
    cout<<"Correct"<<endl;
  }
  else {
    cout<<"Too weak"<<endl;
  }
}