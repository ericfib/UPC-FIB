#include<iostream>
#include<vector>
using namespace std;

bool mirarprefix(const string& s, const string& p){
  for (int i = 0; i < p.size(); i++){
      if(s[i] != p[i]) return false;
    }
    return true;
}

void llegeixseq(vector<string>& x, int n){
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
}
void imprimeix(const vector<string>& seq, const vector<string>& pref){
  int n = seq.size();
  int m = pref.size();
  for(int q = 0; q < n; q++){
    cout << "Comencen amb " << pref[q] << ":" << endl;
    for(int i = 0; i < m; i++){
      if(mirarprefix(seq[i],pref[q])){
        cout << seq[i] << endl;
      }
      else cout << "";
    }
  }
}

int main (){
  int n,m;
  while(cin >> n){
    vector<string> seq(n);
    llegeixseq(seq,n);
    cin >> m;
    vector<string> pref(m);
    llegeixseq(pref,m);
    imprimeix(seq,pref);
  }
}
