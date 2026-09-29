# AI Search Algorithms Project

A beginner-friendly collection of 4 fundamental AI search algorithms with complete implementations in both C++ and Python.

## Project Overview

This project contains implementations of:
- **A\* Search** - Optimal informed search using both path cost and heuristic
- **Greedy Best-First Search (GBFS)** - Fast informed search using only heuristic
- **Weighted A\* Search** - Tunable search balancing speed and optimality
- **Uniform Cost Search (UCS)** - Optimal uninformed search using only path cost

All implementations are designed to be:
- Easy to understand for university students
- Suitable for viva/exam explanations
- Complete with user input (no hard-coded graphs)
- Working correctly with path reconstruction

## Folder Structure

```
AI_Search_Algorithms/
│
├── A_Star/
│   ├── a_star.cpp
│   ├── a_star.py
│   └── README.md
│
├── GBFS/
│   ├── gbfs.cpp
│   ├── gbfs.py
│   └── README.md
│
├── Weighted_A_Star/
│   ├── weighted_a_star.cpp
│   ├── weighted_a_star.py
│   └── README.md
│
├── UCS/
│   ├── ucs.cpp
│   ├── ucs.py
│   └── README.md
│
└── README.md (this file)
```

## Quick Start

### Running Python Files

```bash
cd AI_Search_Algorithms/A_Star
python a_star.py
```

### Running C++ Files

```bash
cd AI_Search_Algorithms/A_Star
g++ a_star.cpp -o a_star
./a_star
```

## Algorithm Comparison Table

| Algorithm | Uses g(n) | Uses h(n) | Formula | Optimal? | Speed |
|-----------|-----------|-----------|---------|----------|-------|
| UCS       | Yes       | No        | g(n)    | Yes      | Slow  |
| GBFS      | No        | Yes       | h(n)    | No       | Fast  |
| A*        | Yes       | Yes       | g(n)+h(n) | Yes*   | Medium |
| WA*       | Yes       | Yes       | g(n)+W×h(n) | No** | Fast |

\* A* is optimal when using an admissible heuristic (never overestimates)  
\*\* WA* finds bounded suboptimal solutions (at most W× optimal cost)

## When to Use Each Algorithm

| Situation | Recommended Algorithm |
|-----------|----------------------|
| No heuristic available | UCS |
| Need optimal path quickly | A* |
| Speed is more important than optimality | GBFS |
| Balance between speed and optimality | Weighted A* |
| Real-time applications | Weighted A* or GBFS |
| Network routing | UCS |

## Heuristic Input Requirements

| Algorithm | Requires Heuristic? |
|-----------|---------------------|
| A* | Yes |
| GBFS | Yes |
| Weighted A* | Yes |
| UCS | **No** |

## Sample Graph for Testing

Use this graph to test all algorithms:

```
Number of nodes: 5
Number of edges: 6

Edges:
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1

Heuristic values (for A*, GBFS, Weighted A*):
h[0] = 7
h[1] = 6
h[2] = 4
h[3] = 2
h[4] = 0

Start node: 0
Goal node: 4
Weight W (for Weighted A*): 2
```

## Expected Results

For the sample graph above:

| Algorithm | Path | Cost |
|-----------|------|------|
| UCS | 0 → 1 → 2 → 4 | 6 |
| A* | 0 → 1 → 2 → 4 | 6 |
| GBFS | 0 → 2 → 4 | 7 |
| WA* (W=2) | 0 → 2 → 4 | 7 |

Note: GBFS and Weighted A* may find different paths depending on tie-breaking, and may not always find the optimal path.

## Key Concepts

### g(n) - Actual Cost
The cumulative cost from the start node to node n. Always increases as we travel further.

### h(n) - Heuristic Estimate
An estimate of the cost from node n to the goal. Must never overestimate for A* to be optimal (admissible heuristic).

### f(n) - Evaluation Function
The value used to decide which node to explore next. Different algorithms use different formulas.

## Time and Space Complexity

| Algorithm | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| UCS | O(b^(1+C*/ε)) | O(b^(1+C*/ε)) |
| GBFS | O(b^m) | O(b^m) |
| A* | O(b^d) | O(b^d) |
| WA* | O(b^d) | O(b^d) |

Where:
- b = branching factor (average number of successors per node)
- d = depth of the shallowest solution
- m = maximum depth of the search tree
- C* = cost of the optimal solution
- ε = minimum edge cost

## Tips for Viva/Exam

1. **Know the formulas** - Each algorithm has a specific formula for f(n)
2. **Understand trade-offs** - Speed vs optimality is the key trade-off
3. **Remember which use heuristics** - UCS is the only one that doesn't
4. **Explain the priority queue** - All algorithms use it to select the next node
5. **Path reconstruction** - Use parent array/dictionary to trace back from goal

## Common Mistakes to Avoid

1. Using wrong formula (e.g., using h(n) in UCS)
2. Forgetting to check if node is already visited
3. Not updating parent correctly for path reconstruction
4. Using heuristic in UCS (it's uninformed!)
5. Wrong priority queue ordering (smallest should come first)

## Author

Created for CSE university students studying AI search algorithms.

## License

Free to use for educational purposes.
