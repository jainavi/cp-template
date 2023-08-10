// ll sumInRange(ll s, ll e) // Sum in range modulo
// {
//     ll sumTillE = (((e % MOD * ((e + 1) % MOD)) % MOD) * (invOfTwo % MOD)) % MOD;
//     ll sumTillS = ((((s - 1) % MOD * (s % MOD)) % MOD) * (invOfTwo % MOD)) % MOD;
//     return sumTillE - sumTillS;
// }

// long long gcd(long long a, long long b) {
//     if (b == 0) return a;
//     return gcd(b, a%b);
// }

// ll modPow(ll x, ll n, ll MOD=MOD) // Inverse of a number
// {
//     if (n == 0)
//         return 1 % MOD;
//     long long u = modPow(x, n / 2,MOD);
//     u = (u * u) % MOD;
//     if (n % 2 == 1)
//         u = (u * x) % MOD;
//     return u;
// }

// ll inv(ll x)
// {
//     return modPow(x, MOD - 2);
// }

// COMBINATORS

// vector<long long> factorialGen(int n)
// {
//     vector<long long> f(n + 1);
//     f[0] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         f[i] = (i * f[i - 1]) % MOD;
//     }
//     return f;
// }

// ll ncr(ll n, ll r)
// {
//     return n < r ? 0 : (fact[n] * inv(fact[n - r] * fact[r])) % MOD;
// }

// CLASS

// class Math
// {
// private:
//     int N, MOD;
//     vll fact;

// public:
//     Math(int N, int MOD) : fact(N + 1)
//     {
//         this->N = N;
//         this->MOD = MOD;
//         fact[0] = 1;
//         for (int i = 1; i <= N; i++)
//             fact[i] = (i * fact[i - 1]) % MOD;
//     }
//     Math(int MOD)
//     {
//         this->MOD = MOD;
//     }

//     ll getFact(int n)
//     {
//         return fact[n];
//     }

//     ll modPow(ll x, ll n)
//     {
//         if (n == 0)
//             return 1 % MOD;
//         long long u = modPow(x, n / 2);
//         u = (u * u) % MOD;
//         if (n % 2 == 1)
//             u = (u * x) % MOD;
//         return u;
//     }

//     ll inv(ll x)
//     {
//         return modPow(x, MOD - 2);
//     }

//     ll ncr(ll n, ll r)
//     {
//         return n < r ? 0 : (fact[n] * inv(fact[n - r] * fact[r])) % MOD;
//     }

        // bool isInt(double n, double T = 1e-10) {
        //     if (abs(n) > 1e9) return false;
        //     return abs(n - round(n)) < T;
        // }
// };