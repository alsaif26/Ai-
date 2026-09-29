# A* Search Algorithm

## What is A* Search?

A* (pronounced "A-star") is one of the most popular and effective search algorithms used in pathfinding and graph traversal. It was first described in 1968 and is widely used in games, robotics, and navigation systems.

## Formula

```
f(n) = g(n) + h(n)

Where:
- f(n) = total estimated cost of path through node n
- g(n) = actual cost from start node to node n
- h(n) = estimated cost from node n to goal (heuristic)
```

## How It Works

1. A* combines the actual cost from the start (g) and the estimated cost to the goal (h)
2. It always expands the node with the smallest f value
3. This makes it both complete (will find a solution if one exists) and optimal (will find the shortest path) when using an admissible heuristic
4. A heuristic is "admissible" if it never overestimates the actual cost to reach the goal

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
=== Starting A* Search ===

Visiting node: 0
  g = 0
  h = 7
  f = 7

Visiting node: 1
  g = 2
  h = 6
  f = 8

Visiting node: 2
  g = 3
  h = 4
  f = 7

Visiting node: 4
  g = 6
  h = 0
  f = 6

=== Result ===

Goal reached!
Final cost: 6
Path: 0 -> 1 -> 2 -> 4
```

## Time Complexity

- **Worst Case:** O(b^d) where b = branching factor, d = depth of solution
- **Best Case:** O(d) when heuristic guides directly to goal
- In practice, with a good heuristic, A* is much faster than uninformed searches

## Space Complexity

- **O(b^d)** - stores all generated nodes in memory

## Key Difference from Other Algorithms

| Algorithm | Uses g(n) | Uses h(n) | Formula |
|-----------|-----------|-----------|---------|
| UCS       | Yes       | No        | g(n)    |
| GBFS      | No        | Yes       | h(n)    |
| A*        | Yes       | Yes       | g+h     |
| WA*       | Yes       | Yes       | g+W*h   |

A* is the middle ground between UCS (which only considers cost so far) and GBFS (which only considers estimated remaining cost). By using both, A* typically finds optimal paths more efficiently than either extreme.

## When to Use A*

- When you need the optimal (shortest) path
- When you have a good heuristic estimate
- When memory is not extremely limited
- Game AI pathfinding
- GPS navigation systems
