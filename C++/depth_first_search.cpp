#include <iostream>
#include <vector>

void dfs(int node, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    std::cout << node << " ";

    // Recursively visit all the adjacent nodes
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int vertices, edges;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> vertices >> edges;

    std::vector<std::vector<int>> adjList(vertices);
    std::cout << "Enter the edges (format: start end):\n";
    for (int i = 0; i < edges; ++i) {
        int start, end;
        std::cin >> start >> end;
        adjList[start].push_back(end);
        adjList[end].push_back(start); // Assuming an undirected graph
    }

    std::vector<bool> visited(vertices, false);
    int startNode;
    std::cout << "Enter the starting node for DFS traversal: ";
    std::cin >> startNode;

    std::cout << "DFS Traversal starting from node " << startNode << ": ";
    dfs(startNode, adjList, visited);
    std::cout << std::endl;

    return 0;
}
