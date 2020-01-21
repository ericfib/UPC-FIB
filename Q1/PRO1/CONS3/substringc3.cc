#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Parst {
      int index;
      string sub, s;
      vector<int> vap;
};

// Pre: 0 <= k < y.size()
// Post: The result is the first position i>=k where substring x is found in y,
//       or -1 if no such position exists
int substring_from_k (const string& x, int k,  const string& y) {
   int p = x.size();
   int m = y.size();
   int n = m - p;
   int j,i;
   j = i = 0;
   while(j < p and k+i <= n){
     if (x[j] == y[k+i+j])j++;
     else {
       j = 0;
       i++;
     }
   }
   if (j == p) return k+i;
   else {
     i = -1;
     return i;
   }
}

// Pre: x.size()>0 and y.size()>0
// Post: The result is a vector containing all the positions in y where
//       substring x occurs.
vector<int> substrings(const string& x, const string& y) {
  vector<int> v (0);
  int k = substring_from_k(x,0,y);
  while(k >= 0){
    v.push_back(k);
    k = substring_from_k(x,k+1,y);
  }
  return v;
}

// Comparison function to sort the output as required
bool comp (const Parst& psa, const Parst& psb) {
   if (psa.sub < psb.sub) return true;
   else if (psa.sub == psb.sub and psa.index < psb.index) return true;
   else return false;
}

int main() {
     vector<Parst> vparst;
     Parst pst;
     pst.index = 1;
     while (cin >> pst.sub >> pst.s) {
        pst.vap = substrings(pst.sub,pst.s);
        vparst.push_back(pst);
        ++pst.index;
     }
     sort(vparst.begin(),vparst.end(),comp);
     int vpn = vparst.size();
     for (int i = 0; i < vpn;++i){
        cout << vparst[i].sub << " " << vparst[i].s;
        int n = vparst[i].vap.size();
        for (int j = 0; j < n; ++ j)
            cout << " " << vparst[i].vap[j];
        cout << endl;
    }
 }
