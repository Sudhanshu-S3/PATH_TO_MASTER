
### Introduction to Dynamic Programming

> Dynamic programming combines the correctness of a complete search with the
> efficiency of a greedy algorithm. It applies when a problem breaks into
> overlapping subproblems that can be solved independently. -> CPH Book

#### What it is

- A way to solve a problem by solving smaller versions of the same problem, and
  reusing those answers instead of recomputing them.
- The recursion looks like brute force (it tries every possibility), but it stays
  fast because each subproblem is solved only **once** and its answer is stored.
- Two things a problem needs before DP fits:
  1. **Optimal substructure** : the answer to the whole is built from answers to
     smaller parts.
  2. **Overlapping subproblems** : the same smaller parts get asked for again and
     again. This is what memoization saves.

#### What it is used for

Two jobs, same idea underneath:

1. **Find an optimal solution** : the largest or smallest value possible.
   (fewest coins, longest subsequence, max profit)
2. **Count the solutions** : how many ways in total.
   (number of ways to make a sum, number of paths in a grid)

The same recursive formulation solves both. For optimal you take a `min`/`max`
over the choices; for counting you take a `sum` over the same choices.

---

### DP vs Greedy vs Divide & Conquer

All three break a problem down. The difference is *how the pieces overlap* and
*how you pick*.

#### Where Greedy works

- **What it is:** at each step make the choice that looks best right now, and
  never look back.
- **When it works:** when a locally best choice is provably part of a globally
  best answer (the *greedy choice property*). No need to explore other choices.
- **Cost:** fastest of the three, usually `O(n)` or `O(n log n)`.
- **Catch:** it is only correct if you can *prove* the greedy choice is safe.
- **Example:** making change with euro coins `{1,2,5,10,...}` : always grab the
  largest coin and you are optimal. But with coins `{1,3,4}` and sum `6`, greedy
  gives `4+1+1 = 3 coins` while the optimal is `3+3 = 2 coins`. Greedy breaks,
  so this problem needs DP.

#### Where Divide & Conquer works

- **What it is:** split the problem into subproblems, solve them, then merge.
- **When it works:** when the subproblems are **independent / non-overlapping** :
  each piece is a fresh problem that does not share work with its siblings.
- **Cost:** typically `O(n log n)`, no table needed since nothing repeats.
- **Example:** merge sort splits the array into two halves that share nothing,
  sorts each, and merges. Binary search throws away half each time.

#### Where Dynamic Programming works

- **What it is:** like divide & conquer, but the subproblems **overlap**, so you
  store each answer and reuse it.
- **When it works:** greedy is not safe (a local choice can be wrong) *and* the
  subproblems repeat, so plain recursion would recompute the same thing
  exponentially many times.
- **Cost:** turns exponential brute force into polynomial by trading memory for
  time.
- **Example:** the coin problem `{1,3,4}` above. `solve(6)` needs `solve(2)`
  through both `solve(6-3)` and `solve(6-4)+...`, and the same `solve(x)` keeps
  showing up. Store it once.

| Technique        | Subproblems   | How you choose             | When to reach for it                    |
| ---------------- | ------------- | -------------------------- | --------------------------------------- |
| Greedy           | one path down | best-looking, never undo   | local choice is provably safe           |
| Divide & Conquer | independent   | solve each, then merge     | pieces do not share work                |
| Dynamic Prog.    | overlapping   | try all, keep the best/sum | greedy unsafe*and* subproblems repeat |

> Quick test: if a greedy pick can be wrong, and the recursion keeps asking the
> same smaller question, it is DP.

---

### Steps to approach a DP problem

The goal here is a *method*, not memorizing transitions. If you follow these in
order, the transition falls out on its own.

1. **Write the brute-force recursion first.**
   Ask: "at this state, what choices do I have?" Try all of them recursively.
   Do not think about speed yet. If you can describe the choices, you can code
   this.
2. **Name the state.**
   The state is the smallest set of parameters that fully describes a subproblem.
   Ask: *what do I need to know to answer this subproblem, and nothing more?*

   - Coin problem : the state is just the remaining sum `x` -> `solve(x)`.
   - Knapsack : the state is `(index, remaining capacity)`.
     If two different call paths reach the same state, they must give the same
     answer, that is the whole point.
3. **Write the recurrence from the choices.**
   The transition is just: *over all choices, combine the sub-answers.*

   - Optimal : `answer(state) = min/max over choices ( cost + answer(next state) )`
   - Counting : `answer(state) = sum over choices ( answer(next state) )`
     You are not inventing a formula, you are reading it off the choices in step 1.
     For coins : `solve(x) = min over c in coins ( solve(x - c) + 1 )`.
4. **Nail the base cases.**
   The smallest states that need no recursion.

   - `solve(0) = 0` (empty sum needs zero coins).
   - Impossible states return `infinity` (for min) or `0` (for counting), so
     they never win.
5. **Add memoization (top-down).**
   Same recursion as step 1, but store each computed state in a table and return
   the stored value on the next call. This one line is what makes it DP.
   Complexity now = `(number of states) x (work per transition)`.
6. **Optionally convert to bottom-up (tabulation).**
   Fill the same table from base cases upward with loops. Same answers, no
   recursion overhead, and it makes space optimizations (rolling arrays) easy.
7. **Check the complexity.**
   Count the states and the cost of one transition, multiply. If that is fast
   enough, done. If not, the state is usually too big : look for a smaller state.

> The trap is jumping straight to step 3. Always do steps 1 and 2 first, the
> transition is a consequence of the choices, not something to memorize.

#### Worked mini-example : coins `{1,3,4}`, target `n`

- **Choices** at sum `x` : pick any coin `c`, leaving `x - c`.
- **State** : the remaining sum `x`.
- **Recurrence** : `solve(x) = min( solve(x-1), solve(x-3), solve(x-4) ) + 1`.
- **Base** : `solve(0) = 0`, and `solve(x) = infinity` for `x < 0`.
- First values : `solve(0)=0, solve(1)=1, solve(2)=2, solve(3)=1, solve(4)=1, solve(5)=2, solve(6)=2`.
- Greedy would have said `solve(6) = 3`. DP finds `2`. That gap is exactly why
  this is a DP problem and not a greedy one.

> Next : Section 1.2, linear / 1D DP (Fibonacci, climbing stairs, house robber),
> where the same 7 steps get their first real reps.
