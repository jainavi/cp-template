#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

class PrefixSum
{
private:
    vector<ll> preSum = {0};

public:
    PrefixSum(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
            preSum.push_back(*preSum.rbegin() + nums[i]);
    }
    PrefixSum() {}

    ll getSum(int i, int j)
    {
        return i <= j && i >= 0 && j < preSum.size() - 1 ? preSum[j + 1] - preSum[i] : 0;
    }

    int size()
    {
        return preSum.size() - 1;
    }

    ll getValue(int idx)
    {
        return idx >= 0 && idx < preSum.size() - 1 ? preSum[idx + 1] - preSum[idx] : 0;
    }

    void push_back(ll num)
    {
        preSum.push_back(*preSum.rbegin() + num);
    }
};