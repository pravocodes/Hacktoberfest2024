#include <iostream>
#include <vector>

/**
 * @brief Performs Depth First Search (DFS) traversal of the graph recursively.
 * 
 * @param vertex The current vertex being visited.
 * @param adj The adjacency list of the graph.
 * @param visited A boolean array to keep track of visited vertices.
 * @param result A vector to store the DFS traversal result.
 */
void dfs_recursive(int vertex, std::vector<int> adj[], std::vector<bool>& visited, std::vector<int>& result) {
    // Mark the current vertex as visited and add it to the result
    visited[vertex] = true;
    result.push_back(vertex);

    // Traverse all adjacent vertices
    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            dfs_recursive(neighbor, adj, visited, result);
        }
    }
}

/**
 * @brief Starts the DFS traversal from vertex 0 of the graph.
 * 
 * @param V The number of vertices in the graph.
 * @param adj The adjacency list of the graph.
 * @return std::vector<int> The DFS traversal result starting from vertex 0.
 */
std::vector<int> dfs_of_graph(int V, std::vector<int> adj[]) {
    // Array to track visited vertices
    std::vector<bool> visited(V, false);
    
    // Vector to store the result of DFS traversal
    std::vector<int> result;

    // Start DFS from vertex 0
    dfs_recursive(0, adj, visited, result);

    return result;
}

/**
 * @brief Test function to perform DFS traversal on a sample graph and print the result.
 */
void test() {
    // Number of vertices
    int V = 5;

    // Adjacency list representation of the graph
    std::vector<int> adj[V];
    adj[0] = {2, 3, 1};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    // Get the DFS traversal result starting from vertex 0
    std::vector<int> dfs_result = dfs_of_graph(V, adj);

    // Print the result
    std::cout << "DFS Traversal: ";
    for (int v : dfs_result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief The main function to execute the program.
 * 
 * @return int Exit status of the program.
 */
int main() {
    // Call the test function to execute DFS on the sample graph
    test();
    return 0;
}
