#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int> > Room;

// Pre: n, m integers greater than 0
// Post: it returns a valid n*m Room
Room read_room(int n, int m) {
    Room p(n, vector<int>(m));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> p[i][j];
      }
    }
    return p;
}

// Pre: room is a valid Room
// Post: it returns the value of those objects that are not monitored by any of the security cameras in room, no matter the final value of room
int non_monitored_objects(const Room& room){
  int n = room.size();
  int m = room[0].size();
  int suma = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if (room[i][j] == -1){
          m = j;
      }
      else suma+=room[i][j];
    }
  }
  return suma;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Room room = read_room(n, m);
        cout << non_monitored_objects(room) << endl;
    }
}
