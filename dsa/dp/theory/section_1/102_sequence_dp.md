
## Sequence DP

### 1. Fibonacci

I) Recusion with Memorization

```cpp

#include <iostream>
#include <vector>

int fibonacci(int n , std::vector<int> &dp)
{
    if (n <= 2) return 1;

    if(dp[n] != 0) return dp[n];

    dp[n]= fibonacci(n-1, dp) + fibonacci(n-2, dp);

    return dp[n];

}

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> dp(n + 1,0);

    std::cout << fibonacci(n, dp) << "\n";

    return 0;
}

```

II) Tabulation

```cpp

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin>>n;

    std::vector<int> dp(n+1, 0);

    dp[1] = 1;

    for(int i=2 ; i<=n ; i++)   // <=n so dp[n] gets computed
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    std::cout << dp[n] <<"\n";

    return 0;
}


//Space optimized Version

int main()
{
    int n;
    std::cin >> n;

    // prev2 = fib(i-2), prev1 = fib(i-1); seeded at fib(1)=fib(2)=1
    int prev2 = 1, prev1 = 1;
    int curr = 1;

    for(int i=3 ; i<=n ; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;   // slide the window forward
        prev1 = curr;
    }

    std::cout<< curr <<"\n" ;

    return 0;
}

```

### climbing stair

[problem link](https://leetcode.com/problems/climbing-stairs/)

```cpp
#include <iostream>
#include <vector>

int ways(int n, std::vector<int> &dp)
{
    if(n <= 1) return 1;              // base: 0 or 1 stair -> 1 way
    if(dp[n] != 0) return dp[n];

    dp[n] = ways(n-1,dp) + ways(n-2,dp);

    return dp[n];
}

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> dp(n + 1, 0);   // need index up to n

    std::cout << ways(n,dp) << "\n";
    return 0;
}
```

### House robber I and II.

[House  robber I problem](https://leetcode.com/problems/house-robber/description/)
[House robber II problem](https://leetcode.com/problems/house-robber-ii/)

I) House Robber I — can't rob two adjacent houses.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// max money robbing houses in the range [lo, hi]
int robLine(const std::vector<int> &input, int lo, int hi)
{
    int prev2 = 0;   // best up to i-2
    int prev1 = 0;   // best up to i-1

    for(int i = lo; i <= hi; i++)
    {
        int take = prev2 + input[i];        // rob i, skip i-1
        int skip = prev1;                   // don't rob i
        int curr = std::max(take, skip);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> input(n);
    for(auto &a : input) std::cin >> a;

    std::cout << robLine(input, 0, n - 1) << "\n";
    return 0;
}
```

II) House Robber II — houses are in a circle, so the first and last are
adjacent. Rob either [0, n-2] or [1, n-1] and take the better one.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int robLine(const std::vector<int> &input, int lo, int hi)
{
    int prev2 = 0, prev1 = 0;

    for(int i = lo; i <= hi; i++)
    {
        int curr = std::max(prev2 + input[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> input(n);
    for(auto &a : input) std::cin >> a;

    if(n == 1)              // single house: no circle constraint
    {
        std::cout << input[0] << "\n";
        return 0;
    }

    int skipLast  = robLine(input, 0, n - 2);
    int skipFirst = robLine(input, 1, n - 1);

    std::cout << std::max(skipLast, skipFirst) << "\n";
    return 0;
}
```

### Min cost climbing stairs.

[problem link](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

You may start at step 0 or step 1, and from step i you can climb 1 or 2
steps, paying `cost[i]` to leave step i. Reach the top (index n).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int minCost(const std::vector<int> &cost)
{
    int n = cost.size();

    // prev2 = min cost to reach step i-2, prev1 = to reach step i-1
    int prev2 = 0, prev1 = 0;   // starting at step 0 or 1 is free

    for(int i = 2; i <= n; i++)
    {
        int curr = std::min(prev1 + cost[i - 1],   // step from i-1
                            prev2 + cost[i - 2]);  // step from i-2
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;   // cost to reach the top (index n)
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> cost(n);
    for(auto &c : cost) std::cin >> c;

    std::cout << minCost(cost) << "\n";
    return 0;
}
```