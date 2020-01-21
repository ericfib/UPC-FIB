#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
  string artist, title, genre;
  int year;
};

bool comp(const Track &a, const Track &b) {
  if (a.artist == b.artist and a.year == b.year) return a.title < b.title;
  else if (a.artist == b.artist) return a.year < b.year;
  else return a.artist < b.artist;
}

vector<Track> read_tracks(int n) {
  vector<Track> tlist (n); //tlist = tracklist
  for(int i = 0; i < n; i++){
    cin >> tlist[i].artist >> tlist[i].title >> tlist[i].genre >> tlist[i].year;
  }
  return tlist;
}

void print_track(const Track &t) {
  cout << t.artist;
  cout << " (" << t.year;
  cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

int main() {
  int n;
  string genres;
  cin >> n;
  vector<Track> v (n);
  vector<string> g;
  v = read_tracks(n);
  sort (v.begin(),v.end(),comp);
  while(cin >> genres){
    g.push_back(genres);
  }
  for(int i = 0; i < g.size(); i++){
    for(int j = 0; j < n; j++){
      if (v[j].genre == g[i]) print_track(v[j]);
    }
  }
}
