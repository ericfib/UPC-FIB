#include <iostream>
using namespace std;

int operacion (){
  char e;
  cin >> e;
  if(e  >= '0' and e <= '9') return  e - '0';
  else{
  int x = operacion();
  int y = operacion();
    if( e == '+') return (x + y);
    else if( e== '-') return (x - y);
    else return (x * y);
    }
}

int main(){
 cout << operacion() << endl;
}
