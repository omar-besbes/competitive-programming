#include <iostream>
#include <vector>

#define N 1005

using namespace std;

vector<int> adj[N];   // Liste d'adjacence
bool used[N][N];      // Indique si l'arc (i, j) est utilisé ou non
vector<int> circuit;  // Stocke le circuit

void dfs(int node) {
   for (int i = 0; i < adj[node].size(); i++) {
      int next = adj[node][i];
      if (!used[node][next] && !used[next][node]) {
         used[node][next] = used[next][node] = true;

         dfs(next);
      }
   }
   circuit.push_back(node);
}

int main() {
   ios::sync_with_stdio(false);

   int n, m;
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   // Vérification que tous les noeuds ont un nombre d'arcs pair
   for (int i = 1; i <= n; i++) {
      if (adj[i].size() % 2 != 0) {
         cout << -1 << '\n';
         return 0;
      }
   }

   // Recherche du circuit
   dfs(1);

   for (int i = circuit.size() - 1; i >= 0; i--) cout << circuit[i] << " ";
   cout << '\n';

   return 0;
}