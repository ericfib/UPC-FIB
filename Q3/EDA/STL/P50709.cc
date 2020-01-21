#include<iostream>
#include<queue>
using namespace std;



int main(){
    string s;
    int x, aux;
    priority_queue<int> pq;
    
    while (cin >> s){
        if (s == "S"){
            cin >> x;
            pq.push(x);
        }
        
        else if (s == "A"){
            if (pq.size() > 0) cout << pq.top() << endl; 
            else cout << "error!" << endl;
        }
        
        else if (s == "R"){
            if (pq.size() > 0) pq.pop();
            else cout << "error!" << endl;
        }
        
        else if (s == "I"){
            cin >> x;
            
            if (pq.size() > 0){
                aux = pq.top();
                pq.pop();  
                aux += x;
                pq.push(aux);
            }else{
                cout << "error!" << endl;
            }
        }
        
        else if (s == "D"){
            cin >> x;
            
            if (pq.size() > 0){
                aux = pq.top();
                pq.pop();  
                aux -= x;
                pq.push(aux);
            }else{
                cout << "error!" << endl;
            }
        }
    }
}
