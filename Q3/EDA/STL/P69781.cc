#include<iostream>
#include<map>
#include<math.h>
using namespace std;

int parell (int n, int x){
  n /= 2;
  n += x;
  return n;
}

int senar (int n, int y){
  n *= 3;
  n += y;
  return n;
}



int main(){
  int x,y,n, it, nxt, res;
  bool trobat;

  while (cin >> x >> y >> n){
    it = 0;
    trobat = false;
    map<int,int> seq;
    map<int,int>::iterator ite;
    seq[n] = it;
    nxt = n;
    while(n <= 1e8 and not trobat){
      nxt = (n % 2 == 0) ? parell(n, x) : senar(n, y);
      ite = seq.find(nxt);
      it++;
      if (ite != seq.end()){
        trobat = true;
        res = it - (ite->second);
      }else{
        seq[nxt] = it;
      }
      n = nxt;
    }
    if (trobat) cout << res << endl;
    else if (n > 1e8) cout << n << endl;
  }
}
