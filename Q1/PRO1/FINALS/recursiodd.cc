#include<iostream>
using namespace std;

bool divisors_odd(int x, int y){
  if (x < 100){
    return y%(x%10) == 0;
  }
  else return divisors_odd(x/100,y) and y%(x%10) == 0;
}

int main (){
  int x,y;
  while (cin >> x >> y){
    if (divisors_odd(x,y)) cout << "YES" << endl;
    else cout << "FALSE" << endl;
  }
}
