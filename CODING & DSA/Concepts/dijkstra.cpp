
8..DIJKSTRA AlGORITHM 
#define SIZE 10000000+1
vector<pair<int,int>> v[SIZE];
int dist[SIZE];
bool visited[SIZE];
 
void dijkstra()
{
    memset(visited,false,sizeof(visited));
    multiset<pair<int,int>>s;
        s.insert({0,1});
        while(!s.empty()){
          pair<int,int> p =*s.begin();
               s.erase(s.begin());
               int x=p.second;
 int weight=p.first;
         if(vis[x]) continue;
      vis[x]=true;
         for(int i=0;i<v[x].size();i++) {
               int v=v[x][i].first; int w=v[x][i].second;
                if(dist[x] +w<dist[v]) {
                        dist[v]=dist[x] +w;
                        s.insert({dist[v],v}); //update 
                 }              
 
}   }
}
      

#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int INF = 1e9;
vector<pair<int,int> >adj_list[N];
int main() 
{
  // Number of nodes and edges
  int n = 5, m = 7;
  vector<int>dist(n,INF);
  /*
    We will be adding the 
    following 7 edges.
  */
  pair<int, int> edges[] = {{0, 1}, {1, 2}, {2, 4}, {4, 3}, {3, 0}, {3, 1}, {1, 4}};
  int weight[] = {6, 5, 5, 1, 1, 2, 2};
  for (int i = 0; i < m; i++)
  {
    int x = edges[i].first;
    int y = edges[i].second;
    int w = weight[i];
    // As graph is undirected
    adj_list[x].push_back({y,w});
    adj_list[y].push_back({x,w});
  }
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > >pq;
  int src = 0;
  pq.push({0, src}); // {distance from source, source}
  dist[src] = 0;
  cout << "Shortest distance from source vertex " << src << " to " << endl;
  while (!pq.empty())
  {
    int node = pq.top().second;
    pq.pop();
    for (auto i:adj_list[node])
    {
      int v = i.first;
      int w = i.second;
      if (dist[v] > dist[node] + w)
      {
        dist[v] = dist[node] + w;
        pq.push({dist[v], v});
      }
    }
  }
 
  for (int i = 0; i < n; i++)
  {
    cout << "Vertex " << i << ": " << dist[i] << endl;
  }
  return 0;
}



Dijkstra vector<vector<pii> > adj;
 
vi dijkstra(int src)problemscode forces d(n + 1, inf), par(n + 1);
  set<pii> s; //first->d, second->node
  d[src] = 0;
  s.insert({0, src});
  while (!s.empty())
  {
    auto it = s.begin();
    int u = it->ss;
    s.erase(it);
    for (pii e : adj[u])
    {
      int nb = e.ff, w = e.ss;
 
      if (d[u] + w < d[nb])
      {
        s.erase({d[nb], nb});
        d[nb] = d[u] + w;
        par[nb] = u;
        s.insert({d[nb], nb});
      }
    }
  }
 
  return d;
}
 
vi multi_dijkstra(vi sources)
{
  vi d(n + 1, inf), par(n + 1);
  set<pii> s; //first->d, second->node
 
  for (int src : sources)
  {
    d[src] = 0;
    s.insert({0, src});
  }
 
  while (!s.empty())
  {
    auto it = s.begin();
    int u = it->ss;
 
    s.erase(it);
 
    for (pii e : adj[u])
    {
      int nb = e.ff, w = e.ss;
 
      if (d[u] + w < d[nb])
      {
        s.erase({d[nb], nb});
        d[nb] = d[u] + w;
        par[nb] = u;
        s.insert({d[nb], nb});
      }
    }
  }
 
  return d;
}
 
int32_t main()
{
  cin >> n >> m;
  adj.resize(n + 1);
 
  while (m--)
  {
    int i, j, w; cin >> i >> j >> w;
    adj[i].pb({j, w});
    adj[j].pb({i, w});
  }
 
  vi d = dijkstra(1);
 
  for (int i = 1; i <= n; ++i)
    cout << i << ' ' << d[i] << '\n';
 
  return 0;
}


