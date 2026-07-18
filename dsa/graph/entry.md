# Graph Algorithms — Roadmap & Structure

[graphMindmap](images/graph_mindmap.png)
------------

## Section 1 — Foundations: Traversal & Basic Shortest Paths

Goal: Understand representations, traversals, and simple pathfinding.
Target : Able to implement Basic graph operation.

### 1. Graph Basics

- Representations: adjacency list, adjacency matrix, edge list
- Types: directed vs undirected, weighted vs unweighted, cyclic vs acyclic

### 2. Traversal

- DFS -> recursive and iterative (stack)
- BFS -> queue-based
- Connected components (count via DFS/BFS)

### 3. Simple Structural Problems

- Cycle detection (directed & undirected)
- Check tree, connectivity, bipartiteness (2-coloring via BFS)
- Topological sort (Kahn's algorithm and DFS approach)

### 4. Basic Shortest Path

- BFS for shortest paths in unweighted graphs
- Dijkstra (non-negative weights)
- Reconstructing/printing a shortest path
- Complexity trade-offs: adjacency list vs matrix

Practice milestones:

- Clean DFS/BFS implementations
- Topological sort of DAGs
- Example problems: shortest path in an unweighted maze, bipartite check.

---

## Section 2 - Intermediate: Variants & Structural Algorithms

Goal: Move to weighted variants, SCCs, MSTs, and DSU.

### 5. Shortest Path Variants

- Bellman-Ford (negative weights)
- Floyd–Warshall (all-pairs)
- Shortest path on DAG (topo + DP)
- K-shortest paths, limited-edge shortest paths

### 6. Strongly Connected Components & DAG

- Longest/shortest path via DP on DAGs
- Counting paths with memoization
- Kosaraju, Tarjan
- Condensation graph (SCC DAG)

### 7. Bridges & Articulation Points

- Find bridges and articulation vertices
- Applications: critical connections

### 8. Minimum Spanning Tree & DSU

- Kruskal (with Union-Find), Prim, Borůvka
- DSU: union by rank/size, path compression, rollback

Practice milestones:

- Implement Bellman-Ford and negative cycle detection
- Compute SCCs, bridges, MSTs
- Example problems: Cheapest Flights Within K Stops, Redundant Connection, Accounts Merge

---

## Section 3 - Advanced: Optimization & Hybrid Problems

Goal: Combine graph concepts with DP, decomposition, and real-world constraints.

### 9. Decomposition & Connectivity

- Biconnected components, block-cut trees
- Eulerian trails (Hierholzer)
- Heavy-Light & centroid decomposition

### 10. Matching, Coloring & Scheduling

- Greedy coloring, bipartite matching (Hopcroft-Karp)
- Edge coloring, scheduling reductions

### 11. Advanced DAG & DP

- Bitmask DP & TSP variants

### 12. Transformations & Flow

- Graph complements, isomorphism heuristics
- A* search, introduction to max-flow/min-cut

Practice milestones:

- Scale algorithms to large limits (N ~ 1e5, E ~ 1e6)
- Combine techniques: DP on SCC DAG, DSU rollback
- Example problems: Network Delay Time variants, Reconstruct Itinerary, Critical Connections

---

## Rounds

The split is by topic, not by section - Section 2 falls on both sides of the line.

### Round 1

- All of Section 1 (topics 1-4): representations, DFS/BFS, components, cycle
  detection, bipartite check, topological sort, BFS shortest path, Dijkstra
- 0-1 BFS and multi-source BFS
- Floyd-Warshall (topic 5), small N, all-pairs
- Bellman-Ford and negative cycle detection (topic 5)
- Shortest path on DAG, topo + DP (topics 5, 6)
- MST and DSU (topic 8), Kruskal, Prim, union by size, path compression

Div2 C/D graph problems are almost always one of these applied to a disguised graph, 
so recognising the graph is the harder half of the work.

### Round 2

- SCC: Kosaraju/Tarjan, condensation graph, DP on the SCC DAG (topic 6)
- Bridges and articulation points (topic 7)
- DSU rollback, DSU on a rebuilt/offline structure (topic 8)
- K-shortest and limited-edge shortest paths (topic 5)
- Bitmask DP and TSP variants (topic 11)
- Eulerian trails, Hierholzer (topic 9)
- Bipartite matching (topic 10)

### Someday ;-)

Heavy-Light and centroid decomposition, block-cut trees, max-flow/min-cut,
Hopcroft-Karp, A* (topics 9, 10, 12). Leave them until Round 2 is comfortable.

## Resources

- USACO guide : [https://usaco.guide/gold/unweighted-shortest-paths](https://usaco.guide/gold/unweighted-shortest-paths)
- Problem sets: CSES - [https://cses.fi/problemset/task/1192](https://cses.fi/problemset/task/1192)

> NOTE: I will add topic-wise good questions as I solve them in [practice/index.md](practice/index.md) .
