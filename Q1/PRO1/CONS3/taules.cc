#include<iostream>
#include<vector>
using namespace std;

vector<double> interseccio(const vector<double>& v1, const vector<double>& v2){
  int s1 = v1.size();
  int s2 = v2.size();
  int s3;
  if (s1 > s2) s3 = s1;
  else s3 = s2;
  int i, j, k;
  i = j = k = 0;
  vector<double> aux(s3);
  while (i < s1 and j < s2){
    if (v1[i] > v2[j]) ++j;
    else if (v1[i] < v2[j]) ++i;
    else if (k == 0 or (aux[k - 1] != v1[i])){
      aux[k] = v1[i];
      i++;
      k++;
      j++;
    }
    else{
      i++;
      j++;
    }
  }
  vector<double> inte(k);
  for(i = 0; i < k; i++) inte [i] = aux [i];
  return inte;
}
int main (){
}
