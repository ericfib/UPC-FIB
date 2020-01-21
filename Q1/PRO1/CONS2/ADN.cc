#include<iostream>
#include<vector>
using namespace std;
char complement (char c){
  if (c == 'T') return 'A';
  if (c == 'A') return 'T';
  if (c == 'C') return 'G';
  else return 'C';
}

int main (){
  char c;
  int r = 0;
  while(cin >> c){
    if (r == 0 and c != 'T') r = 0;
    else if (r == 0 and c == 'T') {
      r = 1;
      cin >> c;
    }
    if (r == 1 and c == 'T') r = 1;
    else if (r== 1 and c == 'A'){
      r = 2;
      cin >> c;
    }
    else if (r == 1) r = 0;

    if (r == 2 and c == 'A') r = 0;
    else if (r == 2 and c == 'T') r = 1;
    else if (r == 2 and c == 'G') while(cin >> c) cout << complement(c);
  }
  cout << endl;
}
