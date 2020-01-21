#include<iostream>
using namespace std;

int mcd(int a, int b){
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  if (b > a){
    int temp = a;
    a = b;
    b = temp;
  }
  int r;
  while(b != 0){
    r = a%b,
    a = b;
    b = r;
  }
  return a;
}
int main(){
  int n,m;
  while(cin >> n >> m){
    cout << mcd(n,m) << endl;
  }
}
