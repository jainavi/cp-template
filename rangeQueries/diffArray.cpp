// vector<ll> diffArrConstructor(int n, int *arr)
// {
//     vector<ll> diffArr;
//     diffArr.push_back(arr[0]);
//     for (int i = 1; i < n; i++)
//         diffArr.push_back(arr[i] - arr[i - 1]);
//     return diffArr;
// }

// vector<ll> stSumConstruct(int n, vector<ll> arr)
// {
//     vector<ll> sts(2 * n);
//     for (int i = 2 * n - 1; i > 0; i--)
//     {
//         if (i >= n)
//             sts[i] = arr[i - n];
//         else
//             sts[i] = sts[2 * i] + sts[2 * i + 1];
//     }
//     return sts;
// }

// ll SumInRange(int a, int b, vector<ll> &sts, int n)
// {
//     a += n; // a and b are 0-indexed
//     b += n;
//     ll sum = 0;
//     while (a <= b)
//     {
//         if (a % 2 == 1)
//             sum += sts[a++];
//         if (b % 2 == 0)
//             sum += sts[b--];
//         a /= 2;
//         b /= 2;
//     }
//     return sum;
// }

// void updateIndex(int i, int k, vector<ll> &sts, int n)
// {
//     i += n; // i is 0-indexed
//     int diff = k - sts[i];
//     while (i > 0)
//     {
//         sts[i] += diff;
//         i /= 2;
//     }
// }

// Differece array construct and st construct
// vector<ll> diffArray = diffArrConstructor(n, arr);
// vector<ll> diffArraySts = stSumConstruct(n, diffArray);

// Range Update
//  updateIndex(a - 1, diffArraySts[a + n - 1] + u, diffArraySts, n);
// if (b != n)
//     updateIndex(b, diffArraySts[b + n] - u, diffArraySts, n);