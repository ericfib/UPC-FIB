#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct prova {
  string part;
};

int main (){
  vector<prova> s (5);
  for (int i = 0; i < s.size(); i++){
    cin >> s[i].part;
  }
  for(int i = 0; i < 5; i++){
    if (s[i].part[0] == 'c') cout << s[i].part << endl;
  }
}
