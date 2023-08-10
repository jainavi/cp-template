// class StringAlgo
// {
// private:
//     int n;
//     ll BASE, MOD;
//     vll preHash, powArr;

// public:
//     StringAlgo(string &s, ll BASE = 911382323LL, ll MOD = 972663749LL) : powArr(s.length()), preHash(s.length())
//     {
//         this->n = s.length(), this->BASE = BASE, this->MOD = MOD;
//         powArr[0] = 1;
//         rep(i, 1, n) powArr[i] = (powArr[i - 1] * BASE) % MOD;

//         preHash[0] = s[0];
//         rep(i, 1, n) preHash[i] = (((preHash[i - 1] * BASE) % MOD) + s[i]) % MOD;
//     }

//     ll getHash(int i, int j)
//     {
//         if (i == 0)
//             return preHash[j];
//         return (preHash[j] - ((preHash[i - 1] * powArr[j - i + 1]) % MOD) + MOD) % MOD;
//     }
// };