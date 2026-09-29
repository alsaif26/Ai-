/*
 * A* Search Algorithm - Beginner Friendly Implementation
 * 
 * Formula: f(n) = g(n) + h(n)
 * g(n) = cost from start to current node
 * h(n) = heuristic estimate to goal
 * f(n) = total estimated cost
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

// Priority queue element: (f_value, node, g_value)
// We use a struct to make it easier to understand
struct NodeInfo {
    int fValue;    // f(n) = g(n) + h(n)
    int node;      // current node number
    int gValue;    // cost from start to this node
    
    // For priority queue, we want smallest f value first
    // So we use greater than operator
    bool operator>(const NodeInfo& other) const {
        return fValue > other.fValue;
    }
};

int main() {
    int numNodes, numEdges;
    
    // Step 1: Take graph input
    cout << "=== A* Search Algorithm ===" << endl << endl;
    
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
    
    // Step 2: Take heuristic values
    cout << endl << "Enter heuristic values:" << endl;
    vector<int> heuristic(numNodes);
    for (int i = 0; i < numNodes; i++) {
        cout << "h[" << i << "] = ";
        cin >> heuristic[i];
    }
    
    // Step 3: Take start and goal nodes
    int startNode, goalNode;
    cout << endl << "Enter start node: ";
    cin >> startNode;
    cout << "Enter goal node: ";
    cin >> goalNode;
    
    cout << endl << "=== Starting A* Search ===" << endl << endl;
    
    // Step 4: Initialize data structures
    // Priority queue: always gives us the node with smallest f value
    priority_queue<NodeInfo, vector<NodeInfo>, greater<NodeInfo>> pq;
    
    // Distance array: stores minimum g value to reach each node
    vector<int> gValue(numNodes, INT_MAX);
    
    // Parent array: to reconstruct the path later
    vector<int> parent(numNodes, -1);
    
    // Visited array
    vector<bool> visited(numNodes, false);
    
    // Step 5: Add start node to priority queue
    gValue[startNode] = 0;
    int fStart = 0 + heuristic[startNode];  // f = g + h
    pq.push({fStart, startNode, 0});
    
    bool found = false;
    
    // Step 6: Main A* loop
    while (!pq.empty()) {
        // Get node with smallest f value
        NodeInfo current = pq.top();
        pq.pop();
        
        int node = current.node;
        int g = current.gValue;
        int f = current.fValue;
        int h = heuristic[node];
        
        // Skip if already visited
        if (visited[node]) {
            continue;
        }
        
        // Mark as visited
        visited[node] = true;
        
        // Display what we're doing
        cout << "Visiting node: " << node << endl;
        cout << "  g = " << g << endl;
        cout << "  h = " << h << endl;
        cout << "  f = " << f << endl << endl;
        
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
                int newG = g + edgeCost;  // New cost to reach neighbor
                
                // If this path is better, update
                if (newG < gValue[neighbor]) {
                    gValue[neighbor] = newG;
                    parent[neighbor] = node;
                    
                    int newF = newG + heuristic[neighbor];
                    pq.push({newF, neighbor, newG});
                }
            }
        }
    }
    
    // Step 7: Display result
    cout << "=== Result ===" << endl << endl;
    
    if (found) {
        cout << "Goal reached!" << endl;
        cout << "Final cost: " << gValue[goalNode] << endl;
        
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
