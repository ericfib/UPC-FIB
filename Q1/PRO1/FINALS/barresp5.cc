#include<iostream>
using namespace std;

void recc(int n){
  if (n != 0){
    recc(n-1);
    recc(n-1);
    for(int i = 0; i < n; i++){
      cout << "*";
      if (i == n-1) cout << endl;
    }
  }
}


int main (){
  int n;
  while(cin >> n){
    recc(n);
  }

}
