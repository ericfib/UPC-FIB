#include <iostream>
using namespace std;
void afegir(int n, char s) {
	if(n > 0){
		afegir(--n, s);
		cout << s;
	}
}
int num_digits(int n, int b) {
	if(n/b <= 0) return 1;
	else return 1 + num_digits(n/b, b);
}
void canvi_base(int n, int b){
	if(n/b <= 0) cout << n;
	else {
		canvi_base(n/b, b);
		cout << n%b;
	}
}
int main() {
	int n;
	while (cin >> n) {
		char s;
		int b, c;
		cin >> b >> c;
		int digits = num_digits(n,b);
		if (c == digits) canvi_base(n ,b);
		else if(digits < c) {
			s = '#';
			afegir(c - digits, s);
			canvi_base(n,b);
		}else {
			s = '*';
			afegir(c, s);
		}
		cout << endl;
	}
}
