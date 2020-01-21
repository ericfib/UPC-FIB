#include<iostream>
#include<vector>

using namespace std;

void print(const vector<int>& l){
	int n = l.size();
	cout << "(";
	for(int i = 0; i < n; i++) {
		cout << ( i != 0 ? "," : "") << l[i];
	}
	cout << ")" << endl;
}

void backtrack(const vector<int>& l, vector<int>& sol, vector<bool>& u, int p) {
	int n = l.size();

	if (p == n) print(sol);
	else {
		for(int i = 0; i < n; i++) {
			if (not u[i]){
				u[i] = true;
				sol[p] = l[i];
				backtrack(l, sol, u, p+1);
				u[i] = false;
			}
		}
	}
}

int main() {
	int n, t = 0;
	cin >> n;

	vector<int> lista(n);
	for(int i = 0; i < n; i++) {
		lista[i] = i+1;
	}
	vector<int> sol(n);
	vector<bool> used(n, false);
	backtrack(lista, sol, used, t);
}
