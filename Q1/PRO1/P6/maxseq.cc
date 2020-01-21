#include <iostream>
using namespace std;

int main () {
int n, max, lim;
while (cin >> lim){
cin >> n;
max = n;
  for (int i = 1; i < lim; i++){
    cin >> n;
    if (n >= max) max = n;
  }
cout << max << endl;
}
}
