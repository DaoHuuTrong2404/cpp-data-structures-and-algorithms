/**
 * @file graph_algorithms.cpp
 * @brief Graph Representation with BFS, DFS, and Dijkstra Shortest Path
 * @author Dao Huu Trong (DTrongVIP) - Can Tho University
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

class Graph {
private:
    int V;
    vector<vector<Edge>> adj;

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v, int weight = 1, bool directed = false) {
        adj[u].push_back({v, weight});
        if (!directed) {
            adj[v].push_back({u, weight});
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal from node " << start << ": ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (const auto& edge : adj[u]) {
                if (!visited[edge.to]) {
                    visited[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }
        cout << "\n";
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adj[u]) {
                if (dist[u] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[u] + edge.weight;
                    pq.push({dist[edge.to], edge.to});
                }
            }
        }
        return dist;
    }
};

int main() {
    cout << "=== Graph Algorithms: BFS & Dijkstra (DTrongVIP) ===\n";
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    g.BFS(0);

    auto dist = g.dijkstra(0);
    cout << "Shortest distances from source node 0:\n";
    for (int i = 0; i < dist.size(); ++i) {
        cout << "  Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
