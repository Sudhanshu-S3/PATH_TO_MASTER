### Max SubArray Sum

```cpp

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin>>n;

    std::vector<int> input(n,0);

    for(auto &a: input)
    {
        std::cin>>a;
    }

    int sum = input[0];
    int maxSum = input[0];

    for(int i=1; i<n ; i++)
    {
        sum = std::max(input[i], sum + input[i]);
        maxSum = std::max(maxSum, sum);
    }

    std::cout<<maxSum <<"\n" ;

    return 0;
}

```