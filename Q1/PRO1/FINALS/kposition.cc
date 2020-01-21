#include <iostream>
using namespace std;

// Pre: k>0
int select_digits(string s, int pos, int k) {
  if (pos-k >= 0){
    return 10*select_digits(s,pos-k,k) + (s[pos-k]-'0');
  }
  return 0;
}

int main() {
  int k;
  string s;
  while (cin >> s >> k) {
    // Invocation with pos = length of the string
    cout << select_digits(s,s.length(),k) << endl;
  }
}
