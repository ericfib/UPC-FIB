#include<iostream>
using namespace std;

int number_of_odd_digits(int n){
  if (n == 0){
    return 0;
  }
  return (n%2) + number_of_odd_digits(n/10);
}

int main (){
  int n;
  while(cin >> n){
    cout << number_of_odd_digits(n) << endl;
  }
}
