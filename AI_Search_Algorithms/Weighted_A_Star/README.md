# Weighted A* Search

## What is Weighted A*?

Weighted A* is a variation of the A* algorithm that uses a weight factor (W) to give more importance to the heuristic. By increasing the weight on the heuristic, the algorithm becomes more "greedy" and typically finds solutions faster, though they may not be optimal.

## Formula

```
f(n) = g(n) + W * h(n)

Where:
- g(n) = cost from start to current node
- h(n) = estimated cost from node n to goal (heuristic)
- W = weight factor (W >= 1)
- f(n) = total estimated cost
```

## How It Works

1. Weighted A* multiplies the heuristic by a weight W (typically W > 1)
2. A larger W makes the algorithm focus more on reaching the goal quickly
3. When W = 1, it becomes regular A*
4. When W > 1, it finds solutions faster but may sacrifice optimality
5. The solution found has cost at most W times the optimal cost

## Input Format

```
Number of nodes
Number of edges

For each edge:
  source destination cost

Heuristic values for all nodes

Start node
Goal node
Weight W
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

Enter heuristic values:
h[0] = 7
h[1] = 6
h[2] = 4
h[3] = 2
h[4] = 0

Enter start node: 0
Enter goal node: 4
Enter weight W: 2
```

## Sample Output

```
=== Starting Weighted A* Search ===

Visiting node: 0
  g = 0
  h = 7
  W = 2
  f = 14

Visiting node: 2
  g = 4
  h = 4
  W = 2
  f = 12

Visiting node: 4
  g = 7
  h = 0
  W = 2
  f = 7

=== Result ===

Goal reached!
Final cost: 7
Path: 0 -> 2 -> 4
```

## Time Complexity

- **Worst Case:** O(b^d) where b = branching factor, d = depth
- In practice, Weighted A* is faster than regular A* because it explores fewer nodes

## Space Complexity

- **O(b^d)** - stores all generated nodes

## Key Difference from Other Algorithms

| Algorithm | Uses g(n) | Uses h(n) | Formula |
|-----------|-----------|-----------|---------|
| UCS       | Yes       | No        | g(n)    |
| GBFS      | No        | Yes       | h(n)    |
| A*        | Yes       | Yes       | g+h     |
| WA*       | Yes       | Yes       | g+W*h   |

## Effect of Weight W

| W Value | Behavior |
|---------|----------|
| W = 1   | Same as regular A* (optimal) |
| W > 1   | Faster search, suboptimal solution |
| W = ∞   | Same as GBFS (very fast, not optimal) |

**Important Notes:**
- Higher W = faster search but potentially worse solution
- Lower W = slower search but better solution
- The solution cost is bounded by W × optimal_cost

## When to Use Weighted A*

- When you need a solution quickly and optimality is not critical
- In real-time applications with time constraints
- In games where near-optimal paths are acceptable
- When regular A* is too slow for your use case

## Comparison with Regular A*

| Aspect | Weighted A* (W > 1) | Regular A* (W = 1) |
|--------|---------------------|---------------------|
| Speed | Faster | Slower |
| Optimality | Suboptimal (bounded) | Optimal |
| Nodes explored | Fewer | More |
| Use case | Time-critical | Quality-critical |
