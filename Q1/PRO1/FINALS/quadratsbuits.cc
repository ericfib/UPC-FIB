#include<iostream>
using namespace std;

int main (){
  int n;
  char c;
  cin >> n >> c;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      for(int k = 1; k <= i; k++){
        if (j == 1 or j == i or k == 1 or k == i) cout << c;
        else cout << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
