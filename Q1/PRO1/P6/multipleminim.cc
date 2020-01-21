#include <iostream>
using namespace std;
int main () {
  int a, b;
  for (int i = 1; cin >> a >> b; i++){
    if (a <= b and a != 0) cout << "#" << i << " : " << b << endl;
    else {
      while (a%b != 0){
        a++;
      }
      cout << "#" << i << " : " << a << endl;
    }
  }
}
