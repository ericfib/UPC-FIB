#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// WRITE HERE THE SUBPROGRAM 'unique'
vector<int> unique(vector<int> v) {
  sort(v.begin(),v.end());
  vector<int> u(0);
  int n = v.size();
  if (n > 0){
    int comp = v[0];
    u.push_back(v[0]);
    for(int i = 1; i < n; i++){
      if (v[i] != comp){
        u.push_back(v[i]);
        comp = v[i];
      }
    }
    return u;
  }
  else return u;
}

// reads a sequence of integers fro the standard
// input and returns it in a vector
vector<int> read_vector(int n) {
    vector<int> S(n);
    for (int i = 0; i < n; ++i)
        cin >> S[i];
    return S;
}

// writes vector v into the standard output
void write_vector(const vector<int>& v) {
    int n = v.size();
    cout << "[";
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ", ";
            cout << v[i];
    }
    cout << "]";
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v = read_vector(n);
        vector<int> u = unique(v);
        cout << "unique("; write_vector(v);
        cout << ") = "; write_vector(u);
        cout << endl;
    }
}
