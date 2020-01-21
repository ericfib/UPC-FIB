#include <iostream>
#include <math.h>
using namespace std;

int main (){
  int n, sum1 = 0;
  cin >> n;
  for (int i = n; i>0; i--){
    sum1 += pow (i,2);
  }
cout << sum1 << endl;


}
