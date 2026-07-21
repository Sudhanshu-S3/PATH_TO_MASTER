
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

    for(int i=2 ; i<n ; i++)
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

    int prev1 =0, prev2 =1;
    int curr;
    

    for(int i=2 ; i< n ; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        
    }

    std::cout<< prev1 <<"\n" ;

    return 0;
}

```

### climbing stair
### House robber I and II.
### Min cost climbing stairs.
### Frog 1