#include <iostream>
#include <vector>
using namespace std;

int llegeix_vector(vector<int> &v, int n){
  int minim;
  cin >> v[0];
  minim = v[0];
  for(int i = 1; i < n; i++){
    cin >> v[i];
    if (v[i] < minim) minim = v[i];
  }
  return minim;
}

int first_position_of(const vector<int> &v, int x){
  int l;
  l = v.size();
  for (int i = 0; i < l; i++){
    if (v[i] == x) return i;
  }
  return l;
}

int main () {
  int n;
  vector<int> v;
  while (cin >> n){
    v = vector<int> (0);
    v = vector<int> (n);
    cout << first_position_of(v,2*llegeix_vector(v,n)) << endl;
  }
}
