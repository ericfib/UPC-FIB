#include<iostream>
using namespace std;

//pre: n >  0
//post: returns true if n is a SevenThree number
//         returns false if n is not a SevenThree number
bool is_seventhree_number(int n){
  if (n == 1) return true;
  else{
    if (n%7 == 0) return is_seventhree_number(n/7);
    else if (n%3 == 0) return is_seventhree_number(n/3);
    else return false;
  }
}

int main (){
  int n,p,cont;
  while(cin >> n){
    cont = 0;
    for(int i = 0; i < n; i++){
      cin >> p;
      if (is_seventhree_number(p)) cont++;
    }
    cout << cont << endl;
  }
}
