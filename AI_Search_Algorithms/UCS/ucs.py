"""
Uniform Cost Search (UCS) - Beginner Friendly Implementation

Formula: f(n) = g(n)
UCS only uses the actual cost from start to current node.
It does NOT use any heuristic - it's an "uninformed" search.

UCS always finds the optimal (minimum cost) path.
"""

import heapq

def ucs_search():
    # Step 1: Take graph input
    print("=== Uniform Cost Search ===\n")
    
    num_nodes = int(input("Enter number of nodes: "))
    num_edges = int(input("Enter number of edges: "))
    
    # Adjacency list to store the graph
    # graph[node] = list of (neighbor, cost)
    graph = [[] for _ in range(num_nodes)]
    
    print()
    for i in range(num_edges):
        parts = input(f"Enter edge {i + 1} (source destination cost): ").split()
        src, dest, cost = int(parts[0]), int(parts[1]), int(parts[2])
        
        # Add edge in both directions (undirected graph)
        graph[src].append((dest, cost))
        graph[dest].append((src, cost))
    
    # Step 2: Take start and goal nodes
    # NOTE: UCS does NOT need heuristic values
    start_node = int(input("\nEnter start node: "))
    goal_node = int(input("Enter goal node: "))
    
    print("\n=== Starting Uniform Cost Search ===\n")
    
    # Step 3: Initialize data structures
    # Priority queue: (cost, node)
    # UCS uses ONLY the cumulative cost for priority
    pq = []
    
    # Dictionary to store minimum cost to reach each node
    cost_so_far = {i: float('inf') for i in range(num_nodes)}
    
    # Dictionary to store parent of each node (for path reconstruction)
    parent = {i: -1 for i in range(num_nodes)}
    
    # Set to track visited nodes
    visited = set()
    
    # Step 4: Add start node to priority queue
    cost_so_far[start_node] = 0
    heapq.heappush(pq, (0, start_node))
    
    found = False
    
    # Step 5: Main UCS loop
    while pq:
        # Get node with smallest cumulative cost
        cost, node = heapq.heappop(pq)
        
        # Skip if already visited
        if node in visited:
            continue
        
        # Mark as visited
        visited.add(node)
        
        # Display what we're doing
        print(f"Visiting node: {node}")
        print(f"  Current cost: {cost}\n")
        
        # Check if we reached the goal
        if node == goal_node:
            found = True
            break
        
        # Explore neighbors
        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                new_cost = cost + edge_cost  # Total cost to reach neighbor
                
                # If this path is better (lower cost), update
                if new_cost < cost_so_far[neighbor]:
                    cost_so_far[neighbor] = new_cost
                    parent[neighbor] = node
                    
                    # Priority is ONLY the cumulative cost (no heuristic)
                    heapq.heappush(pq, (new_cost, neighbor))
    
    # Step 6: Display result
    print("=== Result ===\n")
    
    if found:
        print("Goal reached!")
        print(f"Minimum cost: {cost_so_far[goal_node]}")
        
        # Reconstruct path
        path = []
        current = goal_node
        while current != -1:
            path.append(current)
            current = parent[current]
        
        # Reverse the path (we built it backwards)
        path.reverse()
        
        print("Path: " + " -> ".join(map(str, path)))
    else:
        print(f"No path exists from {start_node} to {goal_node}")


if __name__ == "__main__":
    ucs_search()
