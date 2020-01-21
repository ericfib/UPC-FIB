#include<iostream>
#include<vector>

using namespace std;

void print(const vector<int>& l){
	int n = l.size();
	for(int i = 0; i < n; i++) {
		cout << l[i];
		if (i != n - 1) cout << " ";
		else cout << endl;
	}
}

void backtrack(vector<int>& l, int n_0, int n_1, int tam) {
	int siz = l.size();
	if (tam == siz) print(l);
	else{
		if (n_0 > 0 && n_1 > 0){
			l[tam] = 0;
			backtrack (l, n_0-1, n_1, tam+1);
			l[tam] = 1;
			backtrack (l, n_0, n_1-1, tam+1);
		}
		else if (n_1 == 0) {
			l[tam] = 0;
			backtrack (l, n_0-1, n_1, tam+1);
		}
		else if (n_0 == 0) {
			l[tam] = 1;
			backtrack (l, n_0, n_1-0, tam+1);
		}
	}
}

int main() {
	int n, z, u, t;
	cin >> n >> u;

	z = n - u;
	t = 0;
	vector<int> vec (n);

	backtrack(vec, z, u, t);
}
