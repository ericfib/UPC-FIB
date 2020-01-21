#include<iostream>
#include<map>
using namespace std;

int main (){
    map<string,int> m;
    map<string,int>::iterator it;
    string x;
    int d;
    string op;
    while (cin >> x >> op){
        if (op == "enters"){ 
            it = m.find (x);
            if (it != m.end()) cout << x << " is already in the casino" << endl;
            else{
                m[x] = 0;
            }
        }
        else if (op == "wins"){
            cin >> d;
            it = m.find (x);
            if (it == m.end()) cout << x << " is not in the casino" << endl;
            else{
                m[x] += d;
            }
        }
        else if (op == "leaves"){
            it = m.find (x);
            if (it == m.end()) cout << x << " is not in the casino" << endl;
            else{
                cout << it->first << " has won " << it->second << endl;
                m.erase(it);
            }
        }
    }
    cout << "----------" << endl;
    for (it = m.begin(); it != m.end(); it++){
        cout << it->first << " is winning " << it->second << endl;
    }
}
