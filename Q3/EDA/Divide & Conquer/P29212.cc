#include<iostream>
#include<math.h>

using namespace std;


int exp_mod (int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result*base) % mod;
        }
        exp = exp >> 1;
        base = (base*base) % mod;
    }
    return result;
} 


int main () {
    long int n,k,m;
    while (cin >> n >> k >> m) {
        cout << exp_mod(n, k, m) << endl;
    }
}
