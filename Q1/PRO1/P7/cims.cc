#include <iostream>
#include <vector>

using namespace std;

vector<int> calcula_cims(const vector<int>& v){
  cin >> previo >> seq >> post;
   bool pic = false;
   while (not pic and post != 0){
       if (previo < seq and post < seq and seq > 3143) pic = true;
       else {
           previo = seq;
           seq = post;
           cin >> post;
       }
}
