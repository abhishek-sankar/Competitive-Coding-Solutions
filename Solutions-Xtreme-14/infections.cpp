/*
Bad-virus is a highly contagious virus that can seriously complicate people’s health. This virus is only spread from person to person and the only way to prevent infection (not 100\%100% safe) is by wearing masks.

Chief of epidemiology has received the first case of bad-virus in your country, this case is imported from the other country. In this context, in coordination with the president, it was decided to close the country's borders, prohibit encounters of more than two persons and make the use of masks mandatory. But in order not to affect the economy, no type of quarantine will be carried out.

Two days later, Chief of epidemiology has been notified about the second case of bad-virus (now necessarily is a national case). Knowing that there are NN persons in the country (including the imported case) enumerated by an integer from 1 to NN, they ask you to identify all people who necessarily are infected. For this task, the department of epidemiology provides you with a list of the MM encounters of two persons during this time. You will be given QQ scenarios that you should handle separately. In the ii-th scenario, you will be given the IDs of the first and the second case of bad-virus, and you should count how many people that can be 100\%100% identified as infected (including the first and the second case).


Standard input
The first line contains two integers NN and MM, denoting the number of persons and number of encounters respectively.

Each one of the next MM lines contains two different integers A_iA
​i
​​  and B_iB
​i
​​ , denoting the two persons in the encounter (there aren't two equal pairs of integers).

The next line contains an integer QQ, denoting the number of scenarios.

Each one of the next QQ lines contains two different integers F_iF
​i
​​  and S_iS
​i
​​ , denoting the first and second case of bad-virus in the ii-th scenario.


Standard output
For each scenario, output the number of people that can be 100\%100% identified as infected on a single line.


Constraints and notes
2 \leq N \leq 10^{5}2≤N≤10
​5
​​ 
1 \leq M, Q \leq 2 \times 10^{5}1≤M,Q≤2×10
​5
​​ 
1 \leq A_i \lt B_i \leq N1≤A
​i
​​ <B
​i
​​ ≤N for all 1 \leq i \leq M1≤i≤M
A_i \ne A_jA
​i
​​ ≠A
​j
​​  or B_i \ne B_jB
​i
​​ ≠B
​j
​​  for all 1 \leq i < j \leq M1≤i<j≤M
1 \leq F_i, S_i \leq N1≤F
​i
​​ ,S
​i
​​ ≤N and F_i \ne S_iF
​i
​​ ≠S
​i
​​  for all 1 \leq i \leq Q1≤i≤Q
For each scenario, it is guaranteed that there is at least a sequence of encounters so that the second case is originally infected from the first case.

For 30\%30% of the test data, N \leq 100N≤100 and M, Q \leq 200M,Q≤200.
For 60\%60% of the test data, N \leq 1\,000N≤1000 and M, Q \leq 2\,000M,Q≤2000.

Input	Output	Explanation
6 5
1 2
1 3
2 4
3 4
4 5
2
1 5
4 3
3
2
Below is the illustration of the encounters.


In the first scenario, there are only two ways such that the fifth person can be infected by the first person, i.e. 1 \rightarrow 2 \rightarrow 4 \rightarrow 51→2→4→5 and 1 \rightarrow 3 \rightarrow 4 \rightarrow 51→3→4→5. We cannot identify which one of the second and the third person that is actually infected. So, the people that can be 100\%100% identified as infected are 11, 44, and 55.

In the second scenario, the people that can be 100\%100% identified as infected are 33 and 44.



C++



*/
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