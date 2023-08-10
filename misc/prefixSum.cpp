#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

class PrefixSum
{
private:
    vector<ll> preSum;

public:
    PrefixSum(vector<ll> nums) : preSum(nums.size() + 1)
    {
        for (int i = 0; i < nums.size(); i++)
            preSum[i + 1] = preSum[i] + nums[i];
    }

    ll getSum(int i, int j) // 0 <= i <= j <= n - 1
    {
        return i <= j && i >= 0 && j < preSum.size() - 1 ? preSum[j + 1] - preSum[i] : 0;
    }
};