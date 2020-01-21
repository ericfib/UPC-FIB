#include<iostream>
using namespace std;

int main (){
  string s;
  bool catboy,gekko,owlette;
  catboy = gekko = owlette = false;
  while(cin >> s and not (catboy and gekko and owlette)){
    if (s == "Catboy" and not catboy){
      catboy = true;
      cout << "Catboy" << endl;
    }
    else if (s == "Gekko" and not gekko){
      gekko = true;
      cout << "Gekko" << endl;
    }
    else if (s == "Owlette" and not owlette){
      owlette = true;
      cout << "Owlette" << endl;
    }
  }
}
