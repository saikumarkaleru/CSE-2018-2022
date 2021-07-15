Given a graph where every edge has weight as either 0 or 1. 
A source vertex is also given in the graph.
Find the shortest path from source vertex to every other vertex.


In normal BFS of a graph all edges have equal weight but in 0-1 BFS some edges may have 0 weight
 and some may have 1 weight. In this we will not use bool array to mark visited nodes but at each 
 
 step we will check for the optimal distance condition. We use double ended queue to store the node. While performing BFS if a edge having weight = 0 is found node is pushed at front of double ended queue and if a edge having weight = 1 is found, it is pushed at back of double ended queue.

The approach is similar to Dijkstra that the if the shortest distance to node is relaxed by the 
previous node then only it will be pushed in the queue.

The above idea works in all cases, when pop a vertex (like Dijkstra), it is the minimum weight 
vertex among remaining vertices. If there is a 0 weight vertex adjacent to it, then this adjacent 
has same distance. If there is a 1 weight adjacent, then this adjacent has maximum distance among 
all vertices in dequeue (because all other vertices are either adjacent of currently popped vertex 
or adjacent of previously popped vertices).


// Java Program to implement 0-1 BFS
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class ZeroOneBFS {
	private static class Node {
		int to; // the ending vertex
		int weight; // the weight of the edge
		
		public Node(int to, int wt) {
			this.to = to;
			this.weight = wt;
		}
	}
	
	private static final int numVertex = 9;
	private ArrayList<Node>[] edges = new ArrayList[numVertex];
	
	public ZeroOneBFS() {
		for (int i = 0; i < edges.length; i++) {
			edges[i] = new ArrayList<Node>();
		}
	}
	
	public void addEdge(int u, int v, int wt) {
		edges[u].add(edges[u].size(), new Node(v, wt));
		edges[v].add(edges[v].size(), new Node(u, wt));
	}
	
	public void zeroOneBFS(int src) {

		// initialize distances from given source
		int[] dist = new int[numVertex];
		for (int i = 0; i < numVertex; i++) {
			dist[i] = Integer.MAX_VALUE;
		}
		
		// double ended queue to do BFS
		Deque<Integer> queue = new ArrayDeque<Integer>();
		dist[src] = 0;
		queue.addLast(src);
		
		while (!queue.isEmpty()) {
			int v = queue.removeFirst();
			for (int i = 0; i < edges[v].size(); i++) {

				// checking for optimal distance
				if (dist[edges[v].get(i).to] >
						dist[v] + edges[v].get(i).weight) {

					// update the distance
					dist[edges[v].get(i).to] =
						dist[v] + edges[v].get(i).weight;

					// put 0 weight edges to front and 1
					// weight edges to back so that vertices
					// are processed in increasing order of weight
					if (edges[v].get(i).weight == 0) {
						queue.addFirst(edges[v].get(i).to);
					} else {
						queue.addLast(edges[v].get(i).to);
					}
				}
			}
		}
		
		for (int i = 0; i < dist.length; i++) {
			System.out.print(dist[i] + " ");
		}
	}
	
	public static void main(String[] args) {
		ZeroOneBFS graph = new ZeroOneBFS();
		graph.addEdge(0, 1, 0);
		graph.addEdge(0, 7, 1);
		graph.addEdge(1, 7, 1);
		graph.addEdge(1, 2, 1);
		graph.addEdge(2, 3, 0);
		graph.addEdge(2, 5, 0);
		graph.addEdge(2, 8, 1);
		graph.addEdge(3, 4, 1);
		graph.addEdge(3, 5, 1);
		graph.addEdge(4, 5, 1);
		graph.addEdge(5, 6, 1);
		graph.addEdge(6, 7, 1);
		graph.addEdge(7, 8, 1);
		int src = 0;//source node
		graph.zeroOneBFS(src);
		return;
	}
}





// C++ program to implement single source
// shortest path for a Binary Graph
#include<bits/stdc++.h>
using namespace std;

/* no.of vertices */
#define V 9

// a structure to represent edges
struct node
{
	// two variable one denote the node
	// and other the weight
	int to, weight;
};

// vector to store edges
vector <node> edges[V];

// Prints shortest distance from given source to
// every other vertex
void zeroOneBFS(int src)
{
	// Initialize distances from given source
	int dist[V];
	for (int i=0; i<V; i++)
		dist[i] = INT_MAX;

	// double ende queue to do BFS.
	deque <int> Q;
	dist[src] = 0;
	Q.push_back(src);

	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop_front();

		for (int i=0; i<edges[v].size(); i++)
		{
			// checking for the optimal distance
			if (dist[edges[v][i].to] > dist[v] + edges[v][i].weight)
			{
				dist[edges[v][i].to] = dist[v] + edges[v][i].weight;

				// Put 0 weight edges to front and 1 weight
				// edges to back so that vertices are processed
				// in increasing order of weights.
				if (edges[v][i].weight == 0)
					Q.push_front(edges[v][i].to);
				else
					Q.push_back(edges[v][i].to);
			}
		}
	}

	// printing the shortest distances
	for (int i=0; i<V; i++)
		cout << dist[i] << " ";
}

void addEdge(int u, int v, int wt)
{
edges[u].push_back({v, wt});
edges[v].push_back({u, wt});
}

// Driver function
int main()
{
	addEdge(0, 1, 0);
	addEdge(0, 7, 1);
	addEdge(1, 7, 1);
	addEdge(1, 2, 1);
	addEdge(2, 3, 0);
	addEdge(2, 5, 0);
	addEdge(2, 8, 1);
	addEdge(3, 4, 1);
	addEdge(3, 5, 1);
	addEdge(4, 5, 1);
	addEdge(5, 6, 1);
	addEdge(6, 7, 1);
	addEdge(7, 8, 1);
	int src = 0;//source node
	zeroOneBFS(src);
	return 0;
}
