#include <iostream>
using namespace std;

int suma(int n){
  if (n/10 == 0){
    if (n%2 != 0) return n;
    else return 0;
  }
  else{
    if ((n%10)%2 != 0) return (n%10) + suma(n/10);
    else return suma(n/10);
  }
}


int main (){
  int n;
  while (cin >> n){
    cout<< "The sum of odd digits of "<< n << " is " << suma(n) << "." << endl;
  }
}
