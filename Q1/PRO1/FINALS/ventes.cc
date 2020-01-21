#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Info{
    string code;
    int gross_income;
};
void llegeixseq(vector<Info>& p,int n){
  for(int i = 0; i < n; i++){
    int sales, price;
    cin >> p[i].code >> sales >> price;
    p[i].gross_income = sales*price;
  }
}

bool comp(const Info& a,const Info& b){
    if (a.gross_income == b.gross_income){
      return a.code < b.code;
    }
    return a.gross_income > b.gross_income;
}

void print(const vector<Info>& p, int n){
  if (p.size() == 0) cout << endl;
  for(int i = 0; i < p.size(); i++){
    cout << p[i].code << " " << p[i].gross_income << endl;
    if (i == p.size() - 1) cout << endl;
  }
}
int main (){
  int n;
  while(cin >> n){
    vector<Info> p(n);
    llegeixseq(p,n);
    sort(p.begin(),p.end(),comp);
    print(p,n);
  }

}
