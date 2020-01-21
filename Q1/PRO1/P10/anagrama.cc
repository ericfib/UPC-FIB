#include<iostream>
#include<vector>
using namespace std;

int main (){
  int n;
  cin >> n;
  while (n > 0){
    char c;
    vector<int> v(26,0);
    cin >> c;
    while(c != '.'){
      int aux;
      aux = c - 'A';
      if (c >= 'A' and c <= 'Z') ++v[aux];
      cin >> c;
    }
    char d;
    cin >> d;
    while (d != '.'){
        int aux;
        aux = d - 'A';
        if (d >= 'A' and d <= 'Z') --v[aux];
        cin >> d;
  }
  bool b = true;
  for (int i = 0; i < 26; i++){
    if (v[i] != 0) b = false;
  }
  if (b) cout << "SI" << endl;
  else cout << "NO" << endl;
  n--;
}
}
