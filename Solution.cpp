#include <bits/stdc++.h>
using namespace std;
#define V 5

// Function to find index of max-weight vertex from set of unvisited vertices
int findMaxVertex(bool visited[], int weights[])
{

  int index = -1;

  int maxW = INT_MIN;

  for (int i = 0; i < V; i++) {

    if (visited[i] == false
      && weights[i] > maxW) {

      maxW = weights[i];

      index = i;
    }
  }
  return index;
}

// Utility function to find the maximum spanning tree of graph
void printMaximumSpanningTree(int graph[V][V],
              int parent[])
{

  int MST = 0;

  for (int i = 1; i < V; i++) {

    MST += graph[i][parent[i]];
  }

  int array[4];
  int c = -1;
  for (int i = 1; i < V; i++) {
      c++;
      array[c] = graph[i][parent[i]];
      }
      
		int n = sizeof(array)/sizeof(int);
		int min;
 
		min = array[0];
		for(int i=0; i<n; i++)
			if(array[i]<min)
				min = array[i];
 
		cout << "A maximum of such heavy trucks\n" <<
		 "can start on this road network: " << min << " [unit] \n";
  
}

// Function to find the maximum spanning tree
void maximumSpanningTree(int graph[V][V])
{


  bool visited[V];

  int weights[V];

  int parent[V];

  for (int i = 0; i < V; i++) {
    visited[i] = false;
    weights[i] = INT_MIN;
  }

  weights[0] = INT_MAX;
  parent[0] = -1;

  for (int i = 0; i < V - 1; i++) {

    int maxVertexIndex
      = findMaxVertex(visited, weights);

    visited[maxVertexIndex] = true;

    for (int j = 0; j < V; j++) {

      if (graph[j][maxVertexIndex] != 0
        && visited[j] == false) {

        if (graph[j][maxVertexIndex] > weights[j]) {

          weights[j] = graph[j][maxVertexIndex];

          parent[j] = maxVertexIndex;
        }
      }
    }
  }

  printMaximumSpanningTree(graph, parent);
}

// Driver Code
int main()
{

  int graph[V][V] = { { 0, 2, 0, 6, 0 },
            { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 },
            { 6, 8, 0, 0, 9 },
            { 0, 5, 7, 9, 0 } };

  printf("It provided a %d*%d dimensional adjacency matrix.\n",V,V);

  maximumSpanningTree(graph);

  return 0;
}
