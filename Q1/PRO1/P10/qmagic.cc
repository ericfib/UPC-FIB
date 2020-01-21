#include<iostream>
#include<vector>
using namespace std;

typedef vector< vector<int> > matriz;

bool quadrat_magic(const vector< vector<int> >& t) {
    int n = t.size();
    int suma = 0;
    for (int j = 0; j < n; ++j) {
        if (t[0][j] > n*n or t[0][j] <= 0) return false;
        suma += t[0][j];
    }
    int mateixa = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (t[i][j] > n*n or t[i][j] <= 0) return false;
            mateixa += t[i][j];
        }
        if (suma != mateixa) return false;
        mateixa = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mateixa += t[j][i];
        }
        if (suma != mateixa) return false;
        mateixa = 0;
    }
    for (int i = 0; i < n; ++i) {
        mateixa += t[i][i];
    }
    if (suma != mateixa) return false;
    int i;
    mateixa = i = 0;
    for (int j = n - 1; j >= 0; --j) {
        mateixa += t[i][j];
        ++i;
    }
    if (suma != mateixa) return false;
    return true;
}
