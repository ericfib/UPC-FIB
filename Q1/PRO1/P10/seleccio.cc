#include <iostream>
#include <vector>
using namespace std;

 void swap(int a, int b){
     int aux;
     aux = a;
     a = b;
     b = aux;
     }


int pos_min(const vector<double>& v, int left, int right) {
    int pos = left;
    for (int i = left + 1; i <= right; ++i) {
        if (v[i] < v[pos]) pos = i;
           }
           return pos;
}


void ordena_per_seleccio(vector<double>& v,int m) {
     int last = m;
     for (int i = 0; i < last; ++i) {
     int k = pos_min(v, i, last);
     swap(v[k], v[i]);
     }
}

int main(){}
