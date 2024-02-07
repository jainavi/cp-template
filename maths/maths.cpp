#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ln "\n"
#define ll long long
#define vint vector<int>
#define vll vector<long long>
#define v(x) vector<x>
#define p(x, y) pair<x, y>

class Math
{
private:
    int N;
    vll fact;

public:
    static int MOD;
    Math(int N) : fact(N + 1)
    {
        this->N = N;
        fact[0] = 1;
        for (int i = 1; i <= N; i++)
            fact[i] = (i * fact[i - 1]) % MOD;
    }
    
    ll getFact(int n)
    {
        return fact[n];
    }

    static ll modPow(ll x, ll n)
    {
        if (n == 0)
            return 1;
        long long u = modPow(x, n / 2);
        u = (u * u) % MOD;
        if (n % 2 == 1)
            u = (u * (x % MOD)) % MOD;
        return u;
    }

    static ll modDiv(ll a, ll b)
    {
        return (a * inv(b)) % MOD;
    }

    static ll modDiff(ll a, ll b)
    {
        return (MOD + a - b) % MOD;
    }

    static ll inv(ll x)
    {
        return modPow(x, MOD - 2);
    }

    ll ncr(ll n, ll r)
    {
        return n < r || r < 0 ? 0 : (fact[n] * inv(fact[n - r] * fact[r])) % MOD;
    }

    static bool isInt(double n, double T = 1e-10)
    {
        if (abs(n) > 1e9)
            return false;
        return abs(n - round(n)) < T;
    }

    static ll sumInBetween(ll a, ll b) // including a and b
    {
        return (b * (b + 1) / 2) - (a * (a - 1) / 2);
    }
};