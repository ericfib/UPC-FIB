#include<iostream>
using namespace std;

bool pairwise_sum(int x, int y){
  if (x == 0) return true;
  if (x%10 + (x/10)%10 != y) return false;
  return pairwise_sum(x/100,y);
}
int main (){
  int x, y;
  while(cin >> x >> y){
    if (pairwise_sum(x,y)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
