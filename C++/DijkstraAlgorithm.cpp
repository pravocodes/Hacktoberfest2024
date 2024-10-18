#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Graph {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adj;

public:
    Graph(int v) : vertices(v) {
        adj.resize(v);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    void dijkstra(int source) {
        std::vector<int> dist(vertices, INT_MAX);
        dist[source] = 0;

        using pii = std::pair<int, int>;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        printShortestPaths(dist);
    }

    void printShortestPaths(const std::vector<int>& dist) {
        std::cout << "Vertex Distance from Source\n";
        for (int i = 0; i < vertices; i++) {
            std::cout << i << "\t\t" << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 2);

    g.dijkstra(0);

    return 0;
}
