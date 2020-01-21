#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct rook{
  int x;
  int y;
};
void llegeixvector(vector<rook>& v, int k){
  for(int i = 0; i < k; i++){
    cin >> v[i].x >> v[i].y;
  }
}
bool comp1(const rook& a,const rook& b){
  return a.x < b.x;
}

bool comp1(const rook& a,const rook& b){
  return a.y < b.y;
}
void pushback(const vector<rook>& a, vector<rook>& b){
  int n = a.size();
  rook pre, act;
  pre = a[0];
  for(int i = 1; i < n; i++){
    if (a[i].x == pre.x){
      b.push_back(pre);
      while (i < n and a[i].x == pre.x){
        b.push_back(a[i]);
        pre = a[i];
        i++;
      }
    }
    pre = a[i];
  }
}
int main (){
  int n,k;
  while(cin >> n >> k){
    vector<rook> v(k);
    llegeixvector(v,k);

  }
}
