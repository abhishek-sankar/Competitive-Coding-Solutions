/*
The School of Xtreme is considering reopening in-person class for the best learning experience. To maximize social distancing, the school wants to seat the students in a classroom such that the sum of squared distances between all pairs of students is maximized. There are NN students in the class numbered from 11 to NN. There are exactly N-1N−1 pairs of students who are best friends. The best friend relationships form a tree structure, so that if everyone keeps sharing a story with his/her best friends, the story will eventually be shared across the whole class. To keep the students happy, we need to keep everyone no farther than 11 meter from each of their best friends.


The classroom can be thought of as a Euclidean plane of infinite size, and the students are points on this plane. What is the maximum possible sum of squared distances between every pair of students, if they are seated optimally?


Standard input
The first line of input has a single integer NN, the of the number of students.

The next N-1N−1 lines each have a single integer, giving B_2, B_3, ... B_NB
​2
​​ ,B
​3
​​ ,...B
​N
​​ , where B_iB
​i
​​  is the best friend of student ii.


Standard output
Output a single line including the maximum possible sum of squares of distances. Your answer is considered correct if it has an absolute or relative error of 10^{-6}10
​−6
​​  from the correct answer.


Constraints and notes
1 \leq N \leq 10^51≤N≤10
​5
​​ 
B_i < iB
​i
​​ <i
It is fine for two students to be seated at the same location.
For 30\%30% of the test data, N \le 500N≤500
For 60\%60% of the test data, N \le 5\,000N≤5000
Input	Output	Explanation
3
1
1
6
There are 33 students. Both student 22's and student 33's best friends are student 11. We can let the three students sit in a row, with student 11 being in the middle and the other two students on the two sides at exactly 11 meter from student 11. The pairwise Euclidean distances in this optimal solution is \{1, 1, 2\}{1,1,2}. Sum of their squares is 66. The figure illustrates this arrangement.


Note that the absolute coordinates of the students do not matter. Only the relative distances between them affect the answer.



5
1
2
3
4
50.0
*/

#include <bits/stdc++.h> 
using namespace std; 

typedef long long int ll;

void add_edge(vector<int> adj[], int src, int dest) 
{ 
    adj[src].push_back(dest); 
    adj[dest].push_back(src); 
} 
  
bool BFS(vector<int> adj[], int src, int dest, int v, 
         int pred[], int dist[]) 
{ 
    list<int> queue; 
  
    bool visited[v]; 
  
    for (int i = 0; i < v; i++) { 
        visited[i] = false; 
        dist[i] = INT_MAX; 
        pred[i] = -1; 
    } 
  
    visited[src] = true; 
    dist[src] = 0; 
    queue.push_back(src); 
  
    // standard BFS algorithm 
    while (!queue.empty()) { 
        int u = queue.front(); 
        queue.pop_front(); 
        for (int i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == false) { 
                visited[adj[u][i]] = true; 
                dist[adj[u][i]] = dist[u] + 1; 
                pred[adj[u][i]] = u; 
                queue.push_back(adj[u][i]); 
  
                if (adj[u][i] == dest) 
                    return true; 
            } 
        } 
    } 
  
    return false; 
} 
  
int printShortestDistance(vector<int> adj[], int s, 
                           int dest, int v) 
{ 
    int pred[v], dist[v]; 
  
    if (BFS(adj, s, dest, v, pred, dist) == false) { 
        return 0; 
    } 
  
    // vector path stores the shortest path 
    vector<int> path; 
    int crawl = dest; 
    path.push_back(crawl); 
    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 
    
    return path.size() - 1;
} 
  
// Driver program to test above functions 
int main() 
{ 
    int v = 8; 
    cin >> v;

    vector<int> adj[v]; 
    
    for (int i = 1; i < v; i++){
        int x;
        cin >> x;
        add_edge(adj, i, x); 
    }

    ll res = 0;
    for (int i = 0; i < v; i++){
        for (int j = i+1; j < v; j++){
            res += printShortestDistance(adj, i, j, v);
        }
    }

    return 0; 
} 