#include<iostream>
#include<vector>
using namespace std;

vector<int> concatenacio(const vector<int>& v1, const vector<int>& v2){
  int n1 = v1.size();
  int n2 = v2.size();
  int m = n1+n2;
  vector<int> cct(m);
  for(int i = 0; i < n1; i++){
    cct[i] = v1[i];
  }
  for(int i = 0; i < n2; i++){
    cct[i+n1] = v2[i];
  }
  return cct;
}
