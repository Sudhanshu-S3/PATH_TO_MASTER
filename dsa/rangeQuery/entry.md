# Range Queries: Roadmap & Structure

Answering questions about a subarray faster than reading it. The whole section is
one trade: spend time preprocessing, or spend it per query. Which structure to
reach for depends on two things : whether the array changes, and whether the
queries can be answered offline.

Quick decision table:

| Array is | Query is | Use |
| -------- | -------- | --- |
| static | sum | prefix sums |
| static | min/max/gcd (idempotent) | sparse table |
| point update | any associative op | BIT or segment tree |
| range update | any associative op | segment tree with lazy |
| offline, no update | anything countable | Mo's algorithm |

---

## Section 1: Foundations, Static Arrays

Goal: Answer queries on an array that never changes.

### 1. Prefix Techniques

- Prefix sums, prefix xor
- 2D prefix sums (submatrix sum)
- Difference array (range update, single final read)
- 2D difference array

### 2. Sparse Table

- O(N log N) build, O(1) query for idempotent operations
- Range min / max / gcd
- Why it does not work for sum

Practice milestones:

- Range sum and range min on a static array
- Example problems: CSES Static Range Sum Queries, Static Range Minimum Queries

---

## Section 2: Point Updates

Goal: Support updates without rebuilding.

### 3. Fenwick Tree (BIT)

- Point update, prefix query
- Range update with point query (difference trick)
- Range update with range query (two BITs)
- Finding the kth element by binary lifting on the BIT

### 4. Segment Tree

- Build, point update, range query
- Any associative operation: sum, min, max, gcd, custom merge
- Iterative vs recursive implementation
- Descending the tree to answer "first index where ..."

Practice milestones:

- BIT and segment tree both written from memory
- Example problems: CSES Dynamic Range Sum Queries, Range Update Queries

---

## Section 3: Range Updates & Offline

Goal: Update whole ranges, and use the fact that queries can be reordered.

### 5. Lazy Propagation

- Range assign, range add, range multiply
- Composing lazy tags correctly
- Combining two different update types on one tree

### 6. Offline Techniques

- Coordinate compression plus BIT
- Sorting queries: sweep line, offline counting of inversions
- Merge sort tree, BIT of sorted vectors

### 7. Mo's Algorithm

- Block ordering, add / remove pointers, O((N+Q) sqrt N)
- Choosing the block size
- Mo's with updates

Practice milestones:

- Lazy segment tree with two composed update types
- Example problems: CSES Range Updates and Sums, Distinct Values Queries

---

## Section 4: Advanced Structures

Goal: The specialised structures, reached for only when the standard ones fail.

### 8. Sqrt Decomposition

- Block decomposition as a general fallback
- When it beats a segment tree (odd operations, easier to reason about)

### 9. Persistent & Specialised

- Persistent segment tree, kth smallest in a range
- Segment tree beats (range chmin/chmax with sum)
- Li Chao tree (dynamic line/CHT queries)
- 2D BIT, BIT of BITs
- Wavelet tree

---

## Rounds

Round 1, Round 2. The split is by topic, not section.

### Round 1

- All of Section 1 (topics 1-2): prefix sums, 2D prefix, difference array, sparse table
- BIT: point update and prefix query (topic 3)
- Segment tree: build, point update, range query (topic 4)
- Coordinate compression plus BIT for counting (topic 6)
- Inversion counting

Prefix sums and a plain BIT. Do not skip the difference array. 
It is the cheapest technique here and shows up often.

### Round 2

- Lazy propagation, range add and range assign (topic 5)
- Composing two update types on one lazy tree (topic 5)
- BIT for range update and range query (topic 3)
- Descending a segment tree for "first index where ..." (topic 4)
- Merge sort tree (topic 6)
- Mo's algorithm without updates (topic 7)
- Sqrt decomposition (topic 8)

### Someday ;-)

Persistent segment trees, segment tree beats, Li Chao, wavelet trees, 2D BIT,
Mo's with updates (topics 7, 9). Leave them until Round 2 is comfortable.

## Resources

- CSES Range Queries: [https://cses.fi/problemset/task/1646](https://cses.fi/problemset/task/1646)
- cp-algorithms data structures: [https://cp-algorithms.com/data_structures/segment_tree.html](https://cp-algorithms.com/data_structures/segment_tree.html)
- USACO Guide (Gold/Platinum range queries): [https://usaco.guide/gold/PURS](https://usaco.guide/gold/PURS)

> NOTE: I will add topic-wise good questions as I solve them in [practice/index.md](practice/index.md) .
