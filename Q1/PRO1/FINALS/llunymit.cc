#include<iostream>
#include<vector>
using namespace std;

bool find_element(const vector<double>& v, double x, double &e){
  int n = v.size();
  double comp1,comp2;
  comp1 = 2*x;
  comp2 = x/2;
  for(int i = n-1; i >= 0; i--){
    if (v[i] >= comp1 or v[i] <= comp2){
      e = v[i];
      return true;
    }
  }
  return false;
}




int main() {
   cout.setf(ios::fixed);
   cout.precision(2);
   int n;
   cin >> n;
   vector<double> v(n);

   double mean;
   double suma;
   for(int i = 0; i < n; i++){
     cin >> v[i];
     suma += v[i];
   }
   mean = suma/n;

   double elem;
   bool found = find_element(v,mean,elem);
   if (found) cout << elem << endl;
   else cout << "not found" << endl;
}
