#include<iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000;

list<int> adjList[MAX];
bool visited[MAX];

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (auto v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (auto v : adjList[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}


int main() {
    int V, E;
    cout<<"Enter the number of vertices and edges:";
    cin >> V >> E;

    cout<<"Enter the end points of edges :"<<endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cout<<"Enter the edge:";
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start;
    cout<<"Enter the starting vertex:";
    cin >> start;

    bfs(start);
    cout << endl;

    // Reset visited array
    memset(visited, false, sizeof(visited));

    dfs(start);
    cout << endl;

    return 0;
}

//Algorithm for BFS
//Create a recursive function that takes the index of the node and a visited array.
// Mark the current node as visited and print the node.
// Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.

//Algorithm for DFS
//1. Mark all the vertices as not visited.
//2. Create a stack for DFS.
//3. Mark the current node as visited and push it to the stack.
//4. While stack is not empty:
//  a. Pop a vertex from stack and print it.
//  b. Get all adjacent vertices of the popped vertex
//  c. If a adjacent has not been visited, then mark it visited and push it to the stack.
