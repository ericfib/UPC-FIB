#include <iostream>
using namespace std;


int digital_sum(int a, int b){
  if (a/10==0 and b/10==0){
   return (a%10 + b%10)%10;
 }
  return ((a%10 + b%10)%10) + digital_sum(a/10,b/10)*10;
}

int main (){
  int a, b;
  while (cin >> a >> b){
    cout << digital_sum(a,b) << endl;
  }
}
