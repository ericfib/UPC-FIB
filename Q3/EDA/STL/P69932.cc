#include<iostream>
#include<set>
#include<sstream>
using namespace std;


int seq(set<int>& s) {
  set<int>:: iterator it1;
  set<int>:: iterator it2;
  int cont = 1;
  if (s.begin() == s.end()) return 0;
  it1 = s.begin();
  it2 = it1;
  it2++;
  if (it2 == s.end()) return 1;

  while (it2 != s.end()) {
    if (((*it1) + (*it2))%2 != 0) ++cont;
    ++it1;
    ++it2;
  }
  return cont;
}


int main() {
  int n;
  string s;
  while(getline(cin, s)) {
      istringstream ss(s);

      set<int> setto;

      while (ss >> n) setto.insert(n);

      cout << seq(setto) << endl;
  }

}
