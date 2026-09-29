/*
 * Greedy Best-First Search (GBFS) - Beginner Friendly Implementation
 *
 * Formula: f(n) = h(n)
 * GBFS only uses heuristic value to decide which node to explore next.
 * It does NOT consider the actual cost traveled so far.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Priority queue element: (h_value, node)
// We use a struct to make it easier to understand
struct NodeInfo {
    int hValue;    // heuristic value (priority)
    int node;      // current node number

    // For priority queue, we want smallest h value first
    bool operator>(const NodeInfo& other) const {
        return hValue > other.hValue;
    }
};

int main() {
    int numNodes, numEdges;

    // Step 1: Take graph input
    cout << "=== Greedy Best-First Search ===" << endl << endl;

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

    cout << endl << "=== Starting Greedy Best-First Search ===" << endl << endl;

    // Step 4: Initialize data structures
    // Priority queue: always gives us the node with smallest h value
    priority_queue<NodeInfo, vector<NodeInfo>, greater<NodeInfo>> pq;

    // Cost array: stores cost to reach each node
    vector<int> costSoFar(numNodes, INT_MAX);

    // Parent array: to reconstruct the path later
    vector<int> parent(numNodes, -1);

    // Visited array
    vector<bool> visited(numNodes, false);

    // Step 5: Add start node to priority queue
    costSoFar[startNode] = 0;
    pq.push({heuristic[startNode], startNode});

    bool found = false;

    // Step 6: Main GBFS loop
    while (!pq.empty()) {
        // Get node with smallest heuristic value
        NodeInfo current = pq.top();
        pq.pop();

        int node = current.node;
        int hValue = current.hValue;

        // Skip if already visited
        if (visited[node]) {
            continue;
        }

        // Mark as visited
        visited[node] = true;

        // Display what we're doing
        cout << "Visiting node: " << node << endl;
        cout << "  h = " << hValue << endl << endl;

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
                // Calculate cost to reach neighbor through current node
                int newCost = costSoFar[node] + edgeCost;

                // If we haven't reached this node before, or found a cheaper path
                if (newCost < costSoFar[neighbor]) {
                    costSoFar[neighbor] = newCost;
                    parent[neighbor] = node;

                    // Priority is ONLY based on heuristic (this is what makes it greedy)
                    pq.push({heuristic[neighbor], neighbor});
                }
            }
        }
    }

    // Step 7: Display result
    cout << "=== Result ===" << endl << endl;

    if (found) {
        cout << "Goal reached!" << endl;
        cout << "Cost: " << costSoFar[goalNode] << endl;

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
