# Greedy Best-First Search (GBFS)

## What is Greedy Best-First Search?

Greedy Best-First Search is a search algorithm that always expands the node that appears to be closest to the goal. It's called "greedy" because it makes the locally optimal choice at each step - the choice that seems best right now.

## Formula

```
f(n) = h(n)

Where:
- h(n) = estimated cost from node n to goal (heuristic)
- f(n) = priority value (just the heuristic)
```

## How It Works

1. GBFS uses ONLY the heuristic value to decide which node to explore next
2. It does NOT consider the actual cost traveled so far (g value)
3. Always expands the node with the smallest heuristic value
4. This makes it faster than A* in many cases, but NOT guaranteed to find the optimal path

## Input Format

```
Number of nodes
Number of edges

For each edge:
  source destination cost

Heuristic values for all nodes

Start node
Goal node
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
```

## Sample Output

```
=== Starting Greedy Best-First Search ===

Visiting node: 0
  h = 7

Visiting node: 2
  h = 4

Visiting node: 4
  h = 0

=== Result ===

Goal reached!
Cost: 7
Path: 0 -> 2 -> 4
```

## Time Complexity

- **Worst Case:** O(b^m) where b = branching factor, m = maximum depth
- Can be much faster than A* because it explores fewer nodes

## Space Complexity

- **O(b^m)** - stores all generated nodes

## Key Difference from Other Algorithms

| Algorithm | Uses g(n) | Uses h(n) | Formula |
|-----------|-----------|-----------|---------|
| UCS       | Yes       | No        | g(n)    |
| GBFS      | No        | Yes       | h(n)    |
| A*        | Yes       | Yes       | g+h     |
| WA*       | Yes       | Yes       | g+W*h   |

**Important:** GBFS is "greedy" because it only looks at the heuristic. This can lead to:
- Faster search (explores fewer nodes)
- Non-optimal paths (might not find the shortest path)
- Possibility of getting stuck in loops without proper tracking

## When to Use GBFS

- When you need a quick solution, not necessarily the best one
- When speed is more important than optimality
- In real-time applications where fast response is critical
- When the heuristic is very accurate

## Comparison with A*

| Aspect | GBFS | A* |
|--------|------|-----|
| Uses path cost (g) | No | Yes |
| Uses heuristic (h) | Yes | Yes |
| Optimal | No | Yes* |
| Speed | Faster | Slower |
| Memory | Less | More |

*A* is optimal when using an admissible heuristic
