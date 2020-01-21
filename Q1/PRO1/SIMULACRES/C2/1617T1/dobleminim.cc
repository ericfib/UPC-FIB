#include <iostream>
#include <vector>
using namespace std;

int llegeix_vector(const vector<int>& v,int n){
  cin >> v[0];
  int minim = v[0];
  for (int i = 0; i < i - 1; i++){
    cin >> v[i];
    if (v[i] < minim) minim = v[i];
  }
  return minim;
}

int first_position_of(const vector<int> &v, int x){
  int n, pos = 0;
  n = v.size();
  for (int i = 0; i < n; i++){
    if (v[i] == 2*llegeix_vector(v,n)) {
      return i;
  }
  else return n;
}
}
int main (){
  int n,x;
  vector<int> v;
  while(cin >> n){
    v = vector<int> (0);
    vvector<int> (n);
    llegeix_vector(v,n);
    cout << first_position_of(v,x) << endl;
  }

}
