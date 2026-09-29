# Uniform Cost Search (UCS)

## What is Uniform Cost Search?

Uniform Cost Search is an uninformed search algorithm that expands the node with the lowest cumulative path cost. It is similar to Dijkstra's algorithm for finding the shortest path in a weighted graph.

## Formula

```
f(n) = g(n)

Where:
- g(n) = actual cost from start node to node n
- f(n) = priority value (just the cumulative cost)
```

## How It Works

1. UCS does NOT use any heuristic - it's an "uninformed" search
2. Always expands the node with the smallest accumulated path cost
3. Guaranteed to find the optimal (minimum cost) path
4. Slower than A* because it doesn't use heuristic guidance
5. Explores nodes in all directions equally (like water spreading)

## Input Format

```
Number of nodes
Number of edges

For each edge:
  source destination cost

Start node
Goal node

NOTE: UCS does NOT require heuristic values
```

## Sample Input

```
Enter number of nodes: 5
Enter number of edges: 6

Enter edge 1 (source destination cost): 0 1 2
Enter edge 2 (source destination cost): 0 2 4
Enter edge 3 (source destination cost): 1 2 1
Enter edge 4 (source destination cost): 1 3 7
Enter edge 5 (source destination cost): 2 4 3
Enter edge 6 (source destination cost): 3 4 1

Enter start node: 0
Enter goal node: 4
```

## Sample Output

```
=== Starting Uniform Cost Search ===

Visiting node: 0
  Current cost: 0

Visiting node: 1
  Current cost: 2

Visiting node: 2
  Current cost: 3

Visiting node: 4
  Current cost: 6

=== Result ===

Goal reached!
Minimum cost: 6
Path: 0 -> 1 -> 2 -> 4
```

## Time Complexity

- **Worst Case:** O(b^(1 + ⌊C*/ε⌋)) where:
  - b = branching factor
  - C* = cost of optimal solution
  - ε = minimum edge cost
- Can be exponential in the worst case

## Space Complexity

- **O(b^(1 + ⌊C*/ε⌋))** - stores all generated nodes

## Key Difference from Other Algorithms

| Algorithm | Uses g(n) | Uses h(n) | Formula |
|-----------|-----------|-----------|---------|
| UCS       | Yes       | No        | g(n)    |
| GBFS      | No        | Yes       | h(n)    |
| A*        | Yes       | Yes       | g+h     |
| WA*       | Yes       | Yes       | g+W*h   |

**Important:** UCS is the only algorithm in this set that does NOT use heuristics. This means:
- It doesn't require any domain knowledge (heuristic estimates)
- It always finds the optimal path
- It explores more nodes than informed searches (A*, GBFS)
- It's useful when no good heuristic is available

## When to Use UCS

- When you don't have any heuristic information
- When you need guaranteed optimal path
- When all edges have different costs
- In network routing protocols
- When implementing Dijkstra's algorithm for shortest path

## Comparison with Other Algorithms

| Aspect | UCS | A* | GBFS |
|--------|-----|-----|------|
| Uses heuristic | No | Yes | Yes |
| Always optimal | Yes | Yes* | No |
| Needs domain knowledge | No | Yes | Yes |
| Nodes explored | Many | Fewer | Fewest |
| Speed | Slowest | Medium | Fastest |

*A* is optimal when using an admissible heuristic

## Relationship with Dijkstra's Algorithm

UCS is essentially Dijkstra's algorithm with a goal test. Both:
- Find the shortest path in weighted graphs
- Use a priority queue based on path cost
- Have the same time and space complexity

The main difference is that UCS stops when it reaches the goal, while Dijkstra finds shortest paths to ALL nodes.
