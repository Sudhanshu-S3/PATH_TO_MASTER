# Trees: Roadmap & Structure

A tree is a connected acyclic graph, so everything in the graph section applies.
This section is for the techniques that only exist because of the structure:
a unique path between any two nodes, and subtrees that nest.

---

## Section 1: Foundations, Rooting & Traversal

Goal: Root a tree and compute per-node information in one DFS.
Target: Able to answer subtree questions without thinking about it.

### 1. Tree Basics

- Properties: N nodes and N-1 edges, unique path between any pair, acyclic
- Representation: adjacency list, parent array, children list
- Rooting an unrooted tree (pick a root, DFS, fill parent)

### 2. Single-DFS Quantities

- depth, parent, subtree size
- Entry and exit times (tin / tout)
- Ancestor check in O(1) using tin/tout

### 3. Classic Tree Properties

- Diameter (two DFS, or DP in one pass)
- Centre and centroid of a tree
- Counting leaves, counting nodes at each depth

Practice milestones:

- Subtree size and depth in one clean DFS
- Diameter by both methods
- Example problems: CSES Subordinates, Tree Diameter, Tree Distances I

---

## Section 2: Ancestors & Path Queries

Goal: Answer questions about the path between two nodes.

### 4. LCA

- Binary lifting (up[k][v] table), kth ancestor
- Euler tour + sparse table
- Distance between two nodes via LCA

### 5. Path Aggregates

- Prefix sums from the root (path sum, path xor)
- Path max/min using the binary lifting table
- Difference on tree (add on a path, read at the end)

Practice milestones:
 
- LCA in O(log N) after O(N log N) preprocessing
- Example problems: CSES Company Queries I & II, Distance Queries, Path Queries

---

## Section 3: Tree DP

Goal: Combine children results into a parent result, then reverse the direction.

### 6. Subtree DP

- Aggregating children into the parent (classic tree DP)
- Independent set on a tree, matching on a tree
- Knapsack on a tree, tree DP with an extra state dimension

### 7. Rerooting

- Computing an answer for every node as root in O(N)
- Down pass and up pass, combining without the excluded child

Practice milestones:

- Rerooting written from scratch without a reference
- Example problems: CSES Tree Matching, Tree Distances II

---

## Section 4: Advanced, Decomposition & Heavy Machinery

Goal: Handle updates and queries at scale.

### 8. Flattening

- Euler tour to turn a subtree into a contiguous range
- Subtree update / subtree query via segment tree or BIT

### 9. Merging Techniques

- Small-to-large merging
- DSU on tree (sack) for subtree colour-count style queries

### 10. Decomposition

- Heavy-Light Decomposition for path queries with updates
- Centroid decomposition for path-counting problems
- Virtual / auxiliary trees

Practice milestones:

- Subtree update plus path query on the same tree
- Example problems: CSES Path Queries II, Distinct Colours

---

## Rounds

Round 1, Round 2. The split is by topic, not section.

### Round 1

- All of Section 1 (topics 1-3): rooting, subtree size, depth, tin/tout, diameter
- LCA by binary lifting (topic 4)
- Distance between two nodes (topic 4)
- Root prefix sums for path sum / path xor (topic 5)
- Basic subtree DP (topic 6): aggregate children into parent

Tree problems are one DFS with the right thing accumulated. LCA is
the only real machinery you need in this band.

### Round 2

- Euler tour flattening plus segment tree / BIT (topic 8)
- Rerooting (topic 7)
- Harder subtree DP: tree knapsack, extra state dimensions (topic 6)
- Difference on tree (topic 5)
- Small-to-large merging (topic 9)
- Binary lifting for path max/min (topic 5)

### Someday ;-)

Heavy-Light Decomposition, centroid decomposition, DSU on tree, virtual trees,
link-cut trees (topics 9, 10). Leave them until Round 2 is comfortable.

## Resources

- CSES Tree Algorithms: [https://cses.fi/problemset/task/1674](https://cses.fi/problemset/task/1674)
- cp-algorithms LCA: [https://cp-algorithms.com/graph/lca.html](https://cp-algorithms.com/graph/lca.html)
- USACO Guide (Gold/Platinum trees): [https://usaco.guide/gold/tree-euler](https://usaco.guide/gold/tree-euler)

> NOTE: I will add topic-wise good questions as I solve them in [practice/index.md](practice/index.md) .
