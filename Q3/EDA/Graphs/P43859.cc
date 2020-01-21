#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

typedef pair<double, int> WArc;
typedef vector<vector<WArc>> WGraph;


void dijkstradexstruido (const WGraph &G, int ini, int fi,
              vector<int>& dist, vector<int>& pes, int &distance) {
    int n = G.size();
    dist = vector<int> (n, 99999);
    dist[ini] = 0;
    pes = vector<int> (n, -1);
    vector<bool> S (n, false);
    priority_queue <WArc, vector<WArc>, greater<WArc> > Q;
    Q.push(WArc(0,ini));

    while (not Q.empty()) {
      int u = Q.top().second;
      Q.pop();

      if (not S[u]) {
        if (u == fi) {
          distance = dist[u];
          return;
        }

        S[u] = true;
        for(int i = 0; i < G[u].size(); ++i) {
          int pes1 = G[u][i].second;
          int dist1 = G[u][i].first;

          if (dist[pes1] > dist[u] + dist1) {
            dist[pes1] = dist[u] + dist1;
            pes[pes1] = u;
            Q.push(WArc(dist[pes1],pes1));
          }
        }
      }
    }
}

void input(WGraph &graf, int y) {
  WArc arc;
  int aux;
  for(int i = 0; i < y; i++) {
    cin >> aux >> arc.second >> arc.first;
    graf[aux].push_back(arc);
  }
}

int main() {
  int x, y;
  while (cin >> x >> y){
    WGraph inp_graf(x);
    input(inp_graf, y);
    vector<int> pesos;
    vector<int> distancies;
    int origN, finalN, dist = -1;
    cin >> origN >> finalN;

    dijkstradexstruido(inp_graf, origN, finalN, distancies, pesos, dist);

    if (dist != -1) cout << dist << endl;
    else cout << "no path from " << origN << " to " << finalN << endl;
  }
}
