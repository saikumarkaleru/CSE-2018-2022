6..BFS


visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty()) {
          int s = q.front(); q.pop();
         for (auto u : adj[s]) {
                   if (visited[u]) continue;
                    visited[u] = true; 
                    Distance[u] = distance[s]+1;
                    Q.push(u);
        }
}
