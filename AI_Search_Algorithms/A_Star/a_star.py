import heapq


def a_star_search():
    print("=== A* Search Algorithm ===\n")

    num_nodes = int(input("Enter number of nodes: "))
    num_edges = int(input("Enter number of edges: "))

    graph = [[] for _ in range(num_nodes)]

    print()
    for edge_number in range(num_edges):
        source, destination, cost = map(
            int,
            input(f"Enter edge {edge_number + 1} (source destination cost): ").split(),
        )
        graph[source].append((destination, cost))
        graph[destination].append((source, cost))

    print("\nEnter heuristic values:")
    heuristic = [int(input(f"h[{node}] = ")) for node in range(num_nodes)]

    start_node = int(input("\nEnter start node: "))
    goal_node = int(input("Enter goal node: "))

    print("\n=== Starting A* Search ===\n")

    pq = []
    g_value = {node: float("inf") for node in range(num_nodes)}
    parent = {node: -1 for node in range(num_nodes)}
    visited = set()

    g_value[start_node] = 0
    heapq.heappush(pq, (heuristic[start_node], start_node, 0))

    found = False
    while pq:
        f, node, g = heapq.heappop(pq)

        if node in visited:
            continue
        visited.add(node)

        h = heuristic[node]
        print(f"Visiting node: {node}")
        print(f"  g = {g}")
        print(f"  h = {h}")
        print(f"  f = {f}\n")

        if node == goal_node:
            found = True
            break

        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                new_g = g + edge_cost
                if new_g < g_value[neighbor]:
                    g_value[neighbor] = new_g
                    parent[neighbor] = node
                    new_f = new_g + heuristic[neighbor]
                    heapq.heappush(pq, (new_f, neighbor, new_g))

    print("=== Result ===\n")

    if found:
        print("Goal reached!")
        print(f"Final cost: {g_value[goal_node]}")

        path = []
        current = goal_node
        while current != -1:
            path.append(current)
            current = parent[current]

        path.reverse()
        print("Path: " + " -> ".join(map(str, path)))
    else:
        print(f"No path exists from {start_node} to {goal_node}")


if __name__ == "__main__":
    a_star_search()
