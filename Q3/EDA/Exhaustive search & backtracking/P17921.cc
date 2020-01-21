#include<iostream>
#include<vector>

using namespace std;

void escriu(const vector<vector<char>>& Mat, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << Mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void nReines(vector<vector<char>>& Mat, vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2, int f, int n) {
	if (f == n) {
		escriu(Mat, n);
	}else{
		for(int i = 0; i < n; ++i) {
			int d1 = n-i-1+f;
			int d2 = f+i;
			if (not col[i] and not dia1[d1] and not dia2[d2]) {
				Mat[f][i] = 'Q';
				col[i] = true;
				dia2[d2] = true;
				dia1[d1] = true;
				nReines(Mat, col, dia1, dia2, f+1, n);
				Mat[f][i] = '.';
				col[i] = false;
				dia2[d2] = false;
				dia1[d1] = false;
			}
		}
	}

}


int main() {
	int n;
	cin >> n;

	vector<bool> dia1 ((2*n-1), false);
	vector<bool> dia2 ((2*n-1), false);
	vector<bool> col (n, false);

	vector<vector<char>> M (n, vector<char> (n, '.'));

	nReines(M, col, dia1, dia2, 0, n);
}
