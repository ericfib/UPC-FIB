#include <iostream>
using namespace std;

int maxim(int n){
  if (n/10 == 0){
  return n%10;
}else{
  if (maxim(n/10) <= n%10)return n%10;
  else return maxim(n/10);
}

}

int main () {
  int n;
  while (cin >> n){
    cout << "Maximum digit of " << n << " is " << maxim(n) <<"." << endl;
  }
}
