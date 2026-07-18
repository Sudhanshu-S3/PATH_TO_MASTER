# Strings: Roadmap & Structure

Most string problems reduce to one question : where does this pattern occur, and
what structure repeats inside this text. The algorithms below are the different
ways of answering that in linear time instead of quadratic.

---

## Section 1: Matching Basics

Goal: Find a pattern in a text, and know the cost of each approach.

### 1. Naive Matching

- Compare at every shift, O(n * m)
- Worth writing once to see what the rest are avoiding

### 2. Hashing

- Polynomial rolling hash, prefix hashes, substring hash in O(1)
- Rabin-Karp : average O(n + m), worst O(n * m) on collisions
- Collision handling : double hashing, random base, big mod
- Monte Carlo (fast, small error) vs Las Vegas (verify on match)

Practice milestones:

- Substring hash in O(1) after O(n) preprocessing
- Compare two substrings without comparing characters

---

## Section 2: Linear Matching

Goal: The two workhorses. Everything in Round 1 leans on these.

### 3. KMP

- Prefix function (failure function), O(n + m)
- Borders and periods of a string
- Counting occurrences, smallest period, string compression

### 4. Z-Algorithm

- Z-array in O(n)
- Pattern search via `pattern + separator + text`
- When Z is simpler to reason about than KMP

Practice milestones:

- Prefix function and Z-array written from memory
- Example problems: CSES String Matching, Finding Borders, Finding Periods

---

## Section 3: Structures Over Strings

Goal: Handle many patterns, or many queries, on the same text.

### 5. Tries

- Prefix tree, insert and search
- Counting prefixes, xor tricks on binary tries

### 6. Aho-Corasick

- Trie plus KMP style failure links
- Matching many patterns in one pass

### 7. Suffix Structures

- Suffix array, construction and LCP array
- Longest repeated substring, distinct substring counting
- Suffix automaton and suffix tree (what they buy over a suffix array)

---

## Section 4: Palindromes & Extras

### 8. Palindromes

- Manacher, all palindromic substrings in O(n)
- Palindromic tree (eertree)

### 9. Odds and Ends

- Booth's algorithm, minimal string rotation
- Boyer-Moore : great in practice, rarely needed in contests
- DP based matching : edit distance, LCS (see the [dp](../dp/entry.md) section)

---

## Rounds

Round 1 targets 1900, Round 2 targets 2100. The split is by topic, not section.

### Round 1

- Hashing, prefix hashes, O(1) substring compare (topic 2)
- Rabin-Karp (topic 2)
- KMP prefix function, borders and periods (topic 3)
- Z-algorithm (topic 4)
- Trie basics (topic 5)
- Edit distance and LCS (topic 9, covered under dp)

Hashing alone solves a large share of ≤1900 string problems, and it is the
easiest to get right under time pressure. KMP and Z are the two to actually
memorize.

### Round 2

- Aho-Corasick (topic 6)
- Suffix array plus LCP (topic 7)
- Manacher (topic 8)
- Minimal rotation, Booth's (topic 9)
- Hashing applied to trees and 2D grids (topic 2)

### Someday ;-)

Suffix automaton, suffix tree, palindromic tree (topics 7, 8). Leave them until
Round 2 is comfortable.

## Resources

- CSES String Algorithms: https://cses.fi/problemset/
- cp-algorithms strings: https://cp-algorithms.com/string/prefix-function.html

> NOTE: I will add topic-wise good questions as I solve them in [practice/index.md](practice/index.md) .
