#include <iostream>
using namespace std;

int compara_num (int a, int b){
    if (a/10 == 0 and b/10 == 0){
      if (a%10 > b%10) return a;
      else return b;
    }
    else {
      if (a%10 > b%10) return (a%10) + compara_num(a/10,b/10)*10;
      else return (b%10) + compara_num(a/10,b/10)*10;
    }
  }


int main () {
  int a, b;
  while (cin >> a >> b){
    cout << compara_num(a,b) << endl;
  }
}
