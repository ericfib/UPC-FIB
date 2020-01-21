#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct racional{
  int num;
  int den;
};

void llegeixseq(vector<racional>& r){
  int n = r.size();
  for(int i = 0; i < n; i++){
    cin >> r[i].num >> r[i].den;
  }
}
bool comp(const racional& r, const racional& s){
  return (r.num*s.den) < (r.den*s.num);
}
void print(const vector<racional>& r){
  int n = r.size();
  for(int i = 0; i < n; i++){
    cout << r[i].num << "/" << r[i].den << endl;
  }
}

int main (){
  int n;
  bool primer = true;
  while(cin >> n){
    vector<racional> r(n);
    llegeixseq(r);
    sort(r.begin(),r.end(),comp);
    if (primer) primer = false;
    else cout << endl;
    print(r);
  }
}
