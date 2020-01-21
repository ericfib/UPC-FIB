#include <iostream>
#include <vector>
using namespace std;


int first_occurrence_i (double x, const vector<double>& v, int esq, int dre) {
    int pos = (dre - esq)/2 + esq;
    if (esq > dre) return -1;
    if (esq == dre) return (v[esq] == x) ? esq : -1;
    
    if (v[pos] < x) return first_occurrence_i(x, v, pos+1, dre);
    else if (v[pos] > x) return first_occurrence_i(x, v, esq, pos);
    else return first_occurrence_i(x, v, esq, pos);
}

int first_occurrence(double x, const vector<double>& v) {
    int esq = 0;
    int dre = v.size()-1;
    return first_occurrence_i(x, v, esq, dre);  
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
            cout << first_occurrence(x, V) << endl;
        }
    }
}
