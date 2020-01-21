#include <iostream>
#include <vector>

using namespace std;

struct Swimmer {
    string name;
    string country;
    string style;
    double time;
};

typedef vector<Swimmer> Competition;

void read_data(Competition& v) {
    int n = v.size();
    for(int i = 0; i < n; i++){
      cin >> v[i].name >> v[i].country >> v[i].style >> v[i].time;
    }
}

int winner(const Competition& v, string style) {
    int pos = -1;
    int n = v.size();
    for (int i = 0; i < n; i++){
      if (v[i].style == style and (pos == -1 or v[i].time < v[pos].time)) pos = i;
    }
    return pos;
}

int main() {
    int n;
    cin >> n;
    Competition v(n);
    read_data(v);
    string style2;
    while (cin >> style2){
      int pos = winner(v,style2);
      if (pos != -1){
        cout << "Winner " << style2 << ": ";
        cout << v[pos].name << " " << v[pos].country << " " << v[pos].time << endl;
      }else{
        cout << "Style " << style2 << " has not been run" << endl;
      }
    }
}
