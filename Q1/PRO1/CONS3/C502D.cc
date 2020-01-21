#include<iostream>
#include<vector>
using namespace std;

struct persona{
  string nom;
  int edat;
  };

void sort(vector<persona>& p){
    for(int i = 0; i < p.size(); i++){
      persona x;
      x = p[i];
      int j = i;
      while(j > 0 and p[j-1].edat < x.edat){
      p[j] = p[j-1];
      j--;
      }
      while(j > 0 and p[j-1].edat == x.edat and p[j-1].nom > x.nom){
      p[j] = p[j-1];
      j--;
    }
    p[j] = x;
  }
}

int main (){
  int n;
  cin >> n;
  vector<persona> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].nom >> p[i].edat;
  }
  sort(p);
  for(int i = 0; i < n; i++){
    cout << p[i].nom << " " << p[i].edat << endl;
  }
}
