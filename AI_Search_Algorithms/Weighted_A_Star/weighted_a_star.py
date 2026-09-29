"""
Weighted A* Search Algorithm - Beginner Friendly Implementation

Formula: f(n) = g(n) + W * h(n)
g(n) = cost from start to current node
h(n) = heuristic estimate to goal
W = weight factor (W >= 1)
f(n) = total estimated cost

When W > 1, the algorithm is more "greedy" and focuses more on the heuristic.
This typically results in faster search but may not find the optimal path.
"""

import heapq

def weighted_a_star_search():
    # Step 1: Take graph input
    print("=== Weighted A* Search Algorithm ===\n")
    
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
    
    # Step 3: Take start, goal, and weight
    start_node = int(input("\nEnter start node: "))
    goal_node = int(input("Enter goal node: "))
    weight = int(input("Enter weight W: "))
    
    print("\n=== Starting Weighted A* Search ===\n")
    
    # Step 4: Initialize data structures
    # Priority queue: (f_value, node, g_value)
    # heapq gives us the smallest f value first
    pq = []
    
    # Dictionary to store minimum g value for each node
    g_value = {i: float('inf') for i in range(num_nodes)}
    
    # Dictionary to store parent of each node (for path reconstruction)
    parent = {i: -1 for i in range(num_nodes)}
    
    # Set to track visited nodes
    visited = set()
    
    # Step 5: Add start node to priority queue
    g_value[start_node] = 0
    f_start = 0 + weight * heuristic[start_node]  # f = g + W*h
    heapq.heappush(pq, (f_start, start_node, 0))
    
    found = False
    
    # Step 6: Main Weighted A* loop
    while pq:
        # Get node with smallest f value
        f, node, g = heapq.heappop(pq)
        
        # Skip if already visited
        if node in visited:
            continue
        
        # Mark as visited
        visited.add(node)
        
        h = heuristic[node]
        
        # Display what we're doing
        print(f"Visiting node: {node}")
        print(f"  g = {g}")
        print(f"  h = {h}")
        print(f"  W = {weight}")
        print(f"  f = {f}\n")
        
        # Check if we reached the goal
        if node == goal_node:
            found = True
            break
        
        # Explore neighbors
        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                new_g = g + edge_cost  # New cost to reach neighbor
                
                # If this path is better, update
                if new_g < g_value[neighbor]:
                    g_value[neighbor] = new_g
                    parent[neighbor] = node
                    
                    # Weighted f = g + W * h
                    new_f = new_g + weight * heuristic[neighbor]
                    heapq.heappush(pq, (new_f, neighbor, new_g))
    
    # Step 7: Display result
    print("=== Result ===\n")
    
    if found:
        print("Goal reached!")
        print(f"Final cost: {g_value[goal_node]}")
        
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
    weighted_a_star_search()
