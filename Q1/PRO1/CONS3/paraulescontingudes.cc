#include<iostream>
#include<vector>
using namespace std;

bool conte(string s1, string s2){
  int i = 0;
  bool lastcheck = false;
  while (i < s1.size() and not lastcheck){
    int j = 0;
    bool check = true;
    while(j < s2.size() and check){
      if (s1[i+j] != s2[j]) check = false;
      ++j;
      lastcheck = check;
    }
    i++;
  }
  return lastcheck;
}


int main (){
  int n;
  cin >> n;
  vector<string> pseq(n);
  for(int i = 0; i < n; i++) cin >> pseq[i];

  for(int v = 0; v < n; v++){
    cout << pseq[v] << ":";
    for(int j = 0; j < pseq.size(); j++){
      if (pseq[v].size() >= pseq[j].size() and conte(pseq[v],pseq[j])) cout << " " << pseq[j];
    }
    cout << endl;
  }
}
