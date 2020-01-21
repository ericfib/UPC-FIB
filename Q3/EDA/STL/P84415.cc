#include<map>
#include<iostream>
using namespace std;

int main (){
  string op, word;
  map<string,int> bag;
  map<string,int>::iterator ite;
  map<string,int>::reverse_iterator r_ite;


  while (cin >> op){
    if (op == "store"){
      cin >> word;
      bag[word]++;
    }
    else if (op == "delete"){
      cin >> word;
      ite = bag.find(word);
      if (ite != bag.end()){
        if ((ite->second) > 1) ite->second--;
        else bag.erase(word);
      }
    }
    else if (op == "maximum?"){
      if (bag.size() > 0){
        r_ite = bag.rbegin();
        cout << "maximum: " << r_ite->first << ", " << r_ite->second << " time(s)" << endl;
      }else{
        cout << "indefinite maximum" << endl;
      }
    }
    else if (op == "minimum?"){
      if (bag.size() > 0){
        ite = bag.begin();
        cout << "minimum: " << ite->first << ", " << ite->second << " time(s)" << endl;
      }else{
        cout << "indefinite minimum" << endl;
      }
    }
  }

}
