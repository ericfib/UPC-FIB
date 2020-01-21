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
   int n1 = x.size();
   int n2 = y.size();
   int i, j;
   i = j = 0;
   int n = n2-n1;
   while (j < n1 and k+i <= n){
     if (x[j] == y[k+i+j]) j++;
     else {
       j = 0;
       i++;
     }
   }
   if (j == n1) return k+i;
   else return -1;
}

// Pre: x.size()>0 and y.size()>0
// Post: The result is a vector containing all the positions in y where
//       substring x occurs.
vector<int> substrings(const string& x, const string& y) {
   vector<int> v(0);
   int k = substring_from_k(x,0,y);
   while(k >= 0){
     v.push_back(k);
     k = substring_from_k(x,k+1,y);
   }
   return v;
}

// Comparison function to sort the output as required
bool comp (const Parst& psa, const Parst& psb) {
   if (psa.sub == psb.sub) return psa.index < psb.index;
   return psa.sub < psb.sub;
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
