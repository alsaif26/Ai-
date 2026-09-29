/*
 * Uniform Cost Search (UCS) - Beginner Friendly Implementation
 * 
 * Formula: f(n) = g(n)
 * UCS only uses the actual cost from start to current node.
 * It does NOT use any heuristic - it's an "uninformed" search.
 * 
 * UCS always finds the optimal (minimum cost) path.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Priority queue element: (cost, node)
// We use a struct to make it easier to understand
struct NodeInfo {
    int cost;      // cumulative cost from start to this node
    int node;      // current node number
    
    // For priority queue, we want smallest cost first
    bool operator>(const NodeInfo& other) const {
        return cost > other.cost;
    }
};

int main() {
    int numNodes, numEdges;
    
    // Step 1: Take graph input
    cout << "=== Uniform Cost Search ===" << endl << endl;
    
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    
    cout << "Enter number of edges: ";
    cin >> numEdges;
    
    // Adjacency list to store the graph
    // graph[node] = list of (neighbor, cost)
    vector<vector<pair<int, int>>> graph(numNodes);
    
    cout << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest, cost;
        cout << "Enter edge " << i + 1 << " (source destination cost): ";
        cin >> src >> dest >> cost;
        
        // Add edge in both directions (undirected graph)
        graph[src].push_back({dest, cost});
        graph[dest].push_back({src, cost});
    }
    
    // Step 2: Take start and goal nodes
    // NOTE: UCS does NOT need heuristic values
    int startNode, goalNode;
    cout << endl << "Enter start node: ";
    cin >> startNode;
    cout << "Enter goal node: ";
    cin >> goalNode;
    
    cout << endl << "=== Starting Uniform Cost Search ===" << endl << endl;
    
    // Step 3: Initialize data structures
    // Priority queue: always gives us the node with smallest cost
    priority_queue<NodeInfo, vector<NodeInfo>, greater<NodeInfo>> pq;
    
    // Cost array: stores minimum cost to reach each node
    vector<int> costSoFar(numNodes, INT_MAX);
    
    // Parent array: to reconstruct the path later
    vector<int> parent(numNodes, -1);
    
    // Visited array
    vector<bool> visited(numNodes, false);
    
    // Step 4: Add start node to priority queue
    costSoFar[startNode] = 0;
    pq.push({0, startNode});
    
    bool found = false;
    
    // Step 5: Main UCS loop
    while (!pq.empty()) {
        // Get node with smallest cumulative cost
        NodeInfo current = pq.top();
        pq.pop();
        
        int node = current.node;
        int cost = current.cost;
        
        // Skip if already visited
        if (visited[node]) {
            continue;
        }
        
        // Mark as visited
        visited[node] = true;
        
        // Display what we're doing
        cout << "Visiting node: " << node << endl;
        cout << "  Current cost: " << cost << endl << endl;
        
        // Check if we reached the goal
        if (node == goalNode) {
            found = true;
            break;
        }
        
        // Explore neighbors
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i].first;
            int edgeCost = graph[node][i].second;
            
            if (!visited[neighbor]) {
                int newCost = cost + edgeCost;  // Total cost to reach neighbor
                
                // If this path is better (lower cost), update
                if (newCost < costSoFar[neighbor]) {
                    costSoFar[neighbor] = newCost;
                    parent[neighbor] = node;
                    
                    // Priority is ONLY the cumulative cost (no heuristic)
                    pq.push({newCost, neighbor});
                }
            }
        }
    }
    
    // Step 6: Display result
    cout << "=== Result ===" << endl << endl;
    
    if (found) {
        cout << "Goal reached!" << endl;
        cout << "Minimum cost: " << costSoFar[goalNode] << endl;
        
        // Reconstruct path
        vector<int> path;
        int current = goalNode;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        // Reverse the path (we built it backwards)
        reverse(path.begin(), path.end());
        
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "No path exists from " << startNode << " to " << goalNode << endl;
    }
    
    return 0;
}
