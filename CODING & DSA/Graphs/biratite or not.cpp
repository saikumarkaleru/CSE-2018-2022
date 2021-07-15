BIPARTITE GRAPH OR NOT ? 
bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : adj[v]) { 
  
        // if vertex u is not explored before 
        if (visited[u] == false) { 
  
            // mark present vertex as visited 
            visited[u] = true; 
  
            // mark its color opposite to its parent 
            color[u] = !color[v]; 
  
            // if the subtree rooted at vertex v is not bipartite 
            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
  
        // if two adjacent are colored with same color then 
        // the graph is not bipartite 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 

