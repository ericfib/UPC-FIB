#include <iostream>
#include <vector>
using namespace std;

bool resistant_search(double x, const vector<double>& v){
    if (v.size() == 0) return false;

    int e = 0;
    int d = v.size()-1;

    while (e+1 < d) {
      int mid = (e+d)/2;

      if (v[mid-1] == x or v[mid] == x or v[mid+1] == x) return true;
      if (x > v[mid]) e = mid;
      else d = mid;
    }

    if (v[d] == x) return true;
    if (v[e] == x) return true;
    else return false;
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
