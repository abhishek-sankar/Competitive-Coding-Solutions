// C++ program to print all paths 
// from a source to destination. 
#include <bits/stdc++.h> 
#include <list> 
using namespace std; 
int min_path = INT_MAX;
vector<vector<int>>paths;
// A directed graph using 
// adjacency list representation 
class Graph { 
	int V; // No. of vertices in graph 
	list<int>* adj; // Pointer to an array containing adjacency lists 

	// A recursive function used by printAllPaths() 
	void printAllPathsUtil(int, int, bool[], int[], int&); 

public: 
	Graph(int V); // Constructor 
	void addEdge(int u, int v); 
	void printAllPaths(int s, int d); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
	adj[u].push_back(v); // Add v to u’s list. 
	adj[v].push_back(u);
} 

// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(int s, int d) 
{ 
	// Mark all the vertices as not visited 
	bool* visited = new bool[V]; 

	// Create an array to store paths 
	int* path = new int[V]; 
	int path_index = 0; // Initialize path[] as empty 

	// Initialize all vertices as not visited 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function to print all paths 
	printAllPathsUtil(s, d, visited, path, path_index); 
} 

// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
void Graph::printAllPathsUtil(int u, int d, bool visited[], 
							int path[], int& path_index) 
{ 
	// Mark the current node and store it in path[] 
	if(path_index>=min_path+1)return;
	visited[u] = true; 
	path[path_index] = u; 
	path_index++; 

	// If current vertex is same as destination, then print 
	// current path[] 
	if (u == d) {
		vector<int>current_path;
		for (int i = 0; i < path_index; i++) {
			// cout << path[i]+1 << " "; 
			current_path.push_back(path[i]+1);
		}
		// cout << endl; 
		paths.push_back(current_path);
		min_path = std::min(min_path, path_index);
	} 
	else // If current vertex is not destination 
	{ 
		// Recur for all the vertices adjacent to current vertex 
		list<int>::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			if (!visited[*i]) {
				// cout<<"Unvisited: "<<*i<<endl;
				printAllPathsUtil(*i, d, visited, path, path_index); 
				}
			}
	} 

	// Remove current vertex from path[] and mark it as unvisited 
	path_index--; 
	visited[u] = false; 
} 

// Driver program 
int main() 
{ 
	// Create a graph given in the above diagram 
	int n, m, q, l1, l2;
	cin>>n>>m;
	if(n<=0){
		cout<<"0"<<endl;
		return 0;
	}
	Graph g(n); 
    for(int contacts = 0; contacts<m; contacts++){
        cin>>l1>>l2;
        g.addEdge(l1-1, l2-1);
    }
    int s, d; 
    cin>>q;
    for(int queries = 0; queries<q; queries++){
        cin>>s>>d;
		paths.clear();
        g.printAllPaths(s-1, d-1);
		// for(int m=0;m<paths.size();m++){
		// 	for(int n=0;n<paths[m].size();n++){
		// 		cout<<paths[m][n]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		vector<int>v;
		for(int m=0;m<paths.size();m++){
			set_intersection(paths[0].begin(),paths[0].end(),paths[m].begin(),paths[m].end(), std::back_inserter(v));
			paths[0] = v;
		}
		cout<<"printing paths: "<<endl;
		for(int f=0;f<v.size();f++){
			cout<<v[f]<<" ";
		}cout<<endl;
		cout<<v.size()<<endl;
    }
	return 0;
} 