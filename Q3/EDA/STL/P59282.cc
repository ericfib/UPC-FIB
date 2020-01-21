#include<queue>
#include<iostream>

using namespace std;

int main() {
  cout.setf(ios::fixed);
  cout.precision(4);

  priority_queue<int, vector<int>, greater<int>> inp;
  int max, n;
  double mitj = 0.0;
  string op;

  while (cin >> op){
    if (op == "number") {
      cin >> n;

      if (inp.empty()) max = n;
      else if(n >= max) max = n;

      mitj += n;
      inp.push(n);
    }
    if (op == "delete" and not inp.empty()) {
      mitj -= inp.top();
      inp.pop();
    }
    if (!inp.empty()) {
      cout << "minimum: " << inp.top();
      cout << ", maximum: " << max;
      cout << ", average: " << mitj/inp.size() << endl;
    }else{
      cout << "no elements" << endl;
    }

  }
}
