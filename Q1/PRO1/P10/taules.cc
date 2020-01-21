#include<iostream>
#include<vector>
using namespace std;

int dicotomica  (double x, const vector<double>& v, int esq, int dre){
  if  (esq > dre) return -1;
  int pos = (esq + dre)/2;
  if (x < v[pos]) return dicotomica(x, v, esq, pos - 1);
  if (x > v[pos]) return dicotomica(x, v, pos + 1, dre);
  return pos;
}

vector<double> diferencia(const vector<double>& v1, const vector<double>& v2){
int s1 = v1.size();
int s2 = v2.size();
vector<double> aux(s1);
int i, j, k;
i = j = k = 0;
while (i < s1 and j < s2) {
        if (v1[i] < v2[j]) {
                if (k == 0 or v1[i] != aux[k-1]) {
                        aux[k] = v1[i];
                        ++k;
                }
                ++i;
        }
        else if (v1[i] > v2[j]) ++j;
        else ++i;
}
while (i < s1) {
        if (k == 0 or aux[k-1] != v1[i]) {
                aux[k] = v1[i];
                ++k;
        }
        ++i;
}
vector<double> res(k);
for (i = 0; i < k; i++) res[i] = aux[i];
return res;
}
int main() {
}
