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

void backtrack(vector<int>& l, int t) {
	int siz = l.size();
	if (t == siz) print(l);
	else {
		l[t] = 0;
		backtrack(l, t+1);
		l[t] = 1;
		backtrack(l, t+1);
	}
}


int main() {
	int n, z, u, t;
	cin >> n;

	vector<int> llista (n);
	z = u = t = 0;

	backtrack(llista, t);
}
