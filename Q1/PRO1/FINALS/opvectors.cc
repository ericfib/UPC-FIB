#include <iostream>
#include <vector>
using namespace std;

// read the elements and write them in a vector
vector<string> read_vector(int n) {
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    return v;
}

// print the elements of a vector leaving a space between them
void print_vector(const vector<string>& v) {
    int size = v.size();
    if (size > 0) {
        for (int i = 0; i < size - 1; ++i) cout << v[i] << ' ';
        cout << v[size -1];
    }
    cout << endl;
}

// Search element in a vector sorted in ascending order.
// The function returns the index where the element is located,
// or -1 if the element is not found.
int search_element(const vector<string>& v, string k, int esq, int dre) {
    if (esq > dre) return -1;
    int pos = (dre+esq)/2;
    if (k < v[pos]) return search_element(v,k,esq,pos-1);
    if (k > v[pos]) return search_element(v,k,pos+1,dre);
    return pos;
}

// Insert an element (only if it is not already in the vector).
// pre: vector is sorted in ascending order.
// post: vector is sorted in ascending order and contains x.
void element_insertion(vector<string>& v, string x) {
    int p = v.size();
    int pos = search_element(v,x,0,p-1);
    if (pos == -1){
       v.push_back(x);
       for(int i = p; i >= 1; i--){
         if (v[i] < v[i-1]){
           string temp = v[i];
           v[i] = v[i-1];
           v[i-1] = temp;
         }
       }
    }
}

// Delete an element (only if it is present in the vector)
// pre: vector is sorted in ascending order.
// post: vector is sorted in ascending order and does not contain x.
void element_deletion(vector<string>& v, string x) {
    int p = v.size();//algoritme de insercio que transporta el
    int pos = search_element(v,x,0,p-1);
    if (pos != -1){
      for(int i = pos; i < p-1; i++){
        string temp = v[i];
        v[i] = v[i+1];
        v[i+1] = temp;
      }
      v.pop_back();
    }
}


// read the number of operations and treat them
void read_treat_operation(vector<string>& v) {
    int num_ops;
    cin >>num_ops;
    for (int i = 0; i < num_ops; ++i) {
        string op, elem;
        cin >> op >> elem;
        if (op == "INS") element_insertion(v, elem);
        else if (op == "DEL") element_deletion(v, elem);
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<string> v = read_vector(n);
        read_treat_operation(v);
        print_vector(v);
    }
}
