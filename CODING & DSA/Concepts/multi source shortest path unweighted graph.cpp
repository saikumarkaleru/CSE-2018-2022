Suppose there are n towns connected by m bidirectional roads. 
There are s towns among them with a police station. 
We want to find out the distance of each town from the nearest police station. 
If the town itself has one the distance is 0.
Input : 
Number of Vertices = 6
Number of Edges = 9
Towns with Police Station : 1, 5
Edges:
1 2
1 6
2 6
2 3
3 6
5 4
6 5
3 4
5 3


Naive Approach: We can loop through the vertices and from each vertex run a BFS to find the closest town with police station from that vertex. This will take O(V.E).

Naive approach implementation using BFS from each vertex: 

// C++ program to demonstrate distance to
// nearest source problem using BFS
// from each vertex
#include <bits/stdc++.h>
using namespace std;
#define N 100000 + 1
#define inf 1000000

// This array stores the distances of the
// vertices from the nearest source
int dist[N];

// a hash array where source[i] = 1
// means vertex i is a source
int source[N];

// The BFS Queue
// The pairs are of the form (vertex, distance
// from current source)
deque<pair<int, int> > BFSQueue;

// visited array for remembering visited vertices
int visited[N];

// The BFS function
void BFS(vector<int> graph[], int start)
{
	// clearing the queue
	while (!BFSQueue.empty())
		BFSQueue.pop_back();

	// push_back starting vertices
	BFSQueue.push_back({ start, 0 });

	while (!BFSQueue.empty()) {

		int s = BFSQueue.front().first;
		int d = BFSQueue.front().second;
		visited[s] = 1;
		BFSQueue.pop_front();

		// stop at the first source we reach during BFS
		if (source[s] == 1) {
			dist[start] = d;
			return;
		}

		// Pushing the adjacent unvisited vertices
		// with distance from current source = this
		// vertex's distance + 1
		for (int i = 0; i < graph[s].size(); i++)
			if (visited[graph[s][i]] == 0)
				BFSQueue.push_back({ graph[s][i], d + 1 });
	}
}

// This function calculates the distance of each
// vertex from nearest source
void nearestTown(vector<int> graph[], int n,
					int sources[], int S)
{

	// reseting the source hash array
	for (int i = 1; i <= n; i++)
		source[i] = 0;
	for (int i = 0; i <= S - 1; i++)
		source[sources[i]] = 1;

	// loop through all the vertices and run
	// a BFS from each vertex to find the distance
	// to nearest town from it
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++)
			visited[i] = 0;
		BFS(graph, i);
	}

	// Printing the distances
	for (int i = 1; i <= n; i++)
		cout << i << " " << dist[i] << endl;
}

void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

// Driver Code
int main()
{ // Number of vertices
	int n = 6;

	vector<int> graph[n + 1];

	// Edges
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 6);
	addEdge(graph, 2, 6);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 6);
	addEdge(graph, 5, 4);
	addEdge(graph, 6, 5);
	addEdge(graph, 3, 4);
	addEdge(graph, 5, 3);

	// Sources
	int sources[] = { 1, 5 };

	int S = sizeof(sources) / sizeof(sources[0]);

	nearestTown(graph, n, sources, S);

	return 0;
}












Efficient Method A better method is to use the Djikstra’s algorithm in a modified way. Let’s consider one of the sources as the original source and the other sources to be vertices with 0 cost paths from the original source. Thus we push all the sources into the Djikstra Queue with distance = 0, and the rest of the vertices with distance = infinity. The minimum distance of each vertex from the original source now calculated using the Dijkstra’s Algorithm are now essentially the distances from the nearest source. 

Explanation: The C++ implementation uses a set of pairs (distance from the source, vertex) sorted according to the distance from the source. Initially, the set contains the sources with distance = 0 and all the other vertices with distance = infinity. 
On each step, we will go to the vertex with minimum distance(d) from source, 
i.e, the first element of the set (the source itself in the first step with distance = 0). 
We go through all it’s adjacent vertices and if the distance of any vertex is > d + 1
 we replace its entry in the set with the new distance. Then we remove the current vertex 
 from the set. We continue this until the set is empty. 
The idea is there cannot be a shorter path to the vertex at the front of the set than the
 current one since any other path will be a sum of a longer path (>= it’s length) and a
  non-negative path length (unless we are considering negative edges). 
Since all the sources have a distance = 0, in the beginning, the adjacent non-source 
vertices will get a distance = 1. All vertices will get distance = distance from their nearest source.


// C++ program to demonstrate
// multi-source BFS
#include <bits/stdc++.h>
using namespace std;
#define N 100000 + 1
#define inf 1000000

// This array stores the distances of the vertices
// from the nearest source
int dist[N];

// This Set contains the vertices not yet visited in
// increasing order of distance from the nearest source
// calculated till now
set<pair<int, int> > Q;

// Util function for Multi-Source BFS
void multiSourceBFSUtil(vector<int> graph[], int s)
{
	set<pair<int, int> >::iterator it;
	int i;
	for (i = 0; i < graph[s].size(); i++) {
		int v = graph[s][i];
		if (dist[s] + 1 < dist[v]) {

			// If a shorter path to a vertex is
			// found than the currently stored
			// distance replace it in the Q
			it = Q.find({ dist[v], v });
			Q.erase(it);
			dist[v] = dist[s] + 1;
			Q.insert({ dist[v], v });
		}
	}

	// Stop when the Q is empty -> All
	// vertices have been visited. And we only
	// visit a vertex when we are sure that a
	// shorter path to that vertex is not
	// possible
	if (Q.size() == 0)
		return;

	// Go to the first vertex in Q
	// and remove it from the Q
	it = Q.begin();
	int next = it->second;
	Q.erase(it);

	multiSourceBFSUtil(graph, next);
}

// This function calculates the distance of
// each vertex from nearest source
void multiSourceBFS(vector<int> graph[], int n,
						int sources[], int S)
{
	// a hash array where source[i] = 1
	// means vertex i is a source
	int source[n + 1];

	for (int i = 1; i <= n; i++)
		source[i] = 0;
	for (int i = 0; i <= S - 1; i++)
		source[sources[i]] = 1;

	for (int i = 1; i <= n; i++) {
		if (source[i]) {
			dist[i] = 0;
			Q.insert({ 0, i });
		}
		else {
			dist[i] = inf;
			Q.insert({ inf, i });
		}
	}

	set<pair<int, int> >::iterator itr;

	// Get the vertex with lowest distance,
	itr = Q.begin();

	// currently one of the souces with distance = 0
	int start = itr->second;

	multiSourceBFSUtil(graph, start);

	// Printing the distances
	for (int i = 1; i <= n; i++)
		cout << i << " " << dist[i] << endl;
}

void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

// Driver Code
int main()
{
	// Number of vertices
	int n = 6;

	vector<int> graph[n + 1];

	// Edges
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 6);
	addEdge(graph, 2, 6);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 6);
	addEdge(graph, 5, 4);
	addEdge(graph, 6, 5);
	addEdge(graph, 3, 4);
	addEdge(graph, 5, 3);

	// Sources
	int sources[] = { 1, 5 };

	int S = sizeof(sources) / sizeof(sources[0]);

	multiSourceBFS(graph, n, sources, S);

	return 0;
}
