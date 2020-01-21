#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Result {
    string city;
    string district;
    int voters;
    int yes;
    int no;
    int blank;
    int null;
};

void read_data(vector<Result>& v) {
    Result r;
    while (cin >> r.city >> r.district >> r.voters >>
                  r.yes >> r.no >> r.blank >> r.null) {
        v.push_back(r);
    }
}

bool compara(const Result &a, const Result &b) {
   return a.district < b.district;
}

// ADD YOUR CODE HERE (procedure compute_and_print, and any other you may need)
double participacio(const Result& r){
  cout.setf(ios::fixed);
  cout.precision(4);
  int suma = r.yes+r.no+r.blank+r.null;
  return (suma/r.voters)*100;
}
int abstencio(const Result& r){
  int suma = r.yes+r.no+r.blank+r.null;
  return r.voters - suma;
}
int votstotals(const Result& r){
  int suma = r.yes+r.no+r.blank+r.null;
  return suma;
}
/*void llenavector(const vector<result>& v){
  int n = v.size();
  for(int n = 0; i < n; i++){

  }
}*/
void printresult (const Result& r){
  cout << r.city << " " << r.district << " " << participacio(r) << " " << r.voters
    << " " << votstotals(r) << " " << abstencio(r) << " " << r.yes << " "
    << r.no << " " << r.blank << " " << r.null << " " << endl;
}
/*
void compute_and_print(const vector<result>& v){
  int n = v.size();
  result comp = v[0];
  printresult(v[0]);
  for(int i = 1; i < n; i++){

  }
}
*/

int main() {
    vector<Result> v;
    read_data(v);
    sort(v.begin(), v.end(), compara);
    for (int i = 0; i < v.size();i++){
      printresult(v[i]);
    }
    /*compute_and_print(v);*/
}
