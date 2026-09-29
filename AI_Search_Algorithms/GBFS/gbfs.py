"""
Greedy Best-First Search (GBFS) - Beginner Friendly Implementation

Formula: f(n) = h(n)
GBFS only uses heuristic value to decide which node to explore next.
It does NOT consider the actual cost traveled so far.
"""

import heapq

def gbfs_search():
    # Step 1: Take graph input
    print("=== Greedy Best-First Search ===\n")
    
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
    
    # Step 2: Take heuristic values
    print("\nEnter heuristic values:")
    heuristic = []
    for i in range(num_nodes):
        h = int(input(f"h[{i}] = "))
        heuristic.append(h)
    
    # Step 3: Take start and goal nodes
    start_node = int(input("\nEnter start node: "))
    goal_node = int(input("Enter goal node: "))
    
    print("\n=== Starting Greedy Best-First Search ===\n")
    
    # Step 4: Initialize data structures
    # Priority queue: (h_value, node)
    # In GBFS, we only use heuristic value for priority
    pq = []
    
    # Dictionary to store the cost to reach each node
    cost_so_far = {i: float('inf') for i in range(num_nodes)}
    
    # Dictionary to store parent of each node (for path reconstruction)
    parent = {i: -1 for i in range(num_nodes)}
    
    # Set to track visited nodes
    visited = set()
    
    # Step 5: Add start node to priority queue
    cost_so_far[start_node] = 0
    heapq.heappush(pq, (heuristic[start_node], start_node))
    
    found = False
    
    # Step 6: Main GBFS loop
    while pq:
        # Get node with smallest heuristic value
        h_value, node = heapq.heappop(pq)
        
        # Skip if already visited
        if node in visited:
            continue
        
        # Mark as visited
        visited.add(node)
        
        # Display what we're doing
        print(f"Visiting node: {node}")
        print(f"  h = {h_value}\n")
        
        # Check if we reached the goal
        if node == goal_node:
            found = True
            break
        
        # Explore neighbors
        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                # Calculate cost to reach neighbor through current node
                new_cost = cost_so_far[node] + edge_cost
                
                # If we haven't reached this node before, or found a cheaper path
                if new_cost < cost_so_far[neighbor]:
                    cost_so_far[neighbor] = new_cost
                    parent[neighbor] = node
                    
                    # Priority is ONLY based on heuristic (this is what makes it greedy)
                    heapq.heappush(pq, (heuristic[neighbor], neighbor))
    
    # Step 7: Display result
    print("=== Result ===\n")
    
    if found:
        print("Goal reached!")
        print(f"Cost: {cost_so_far[goal_node]}")
        
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
    gbfs_search()
