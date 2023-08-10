// #define left seg[2 * ind + 1]
// #define right seg[2 * ind + 2]

// ll seg[4 * 200000];

// void build(int ind, int low, int high)
// {
//     if (low == high)
//     {
//         seg[ind] = arr[low];
//         return;
//     }
//     int mid = (low + high) / 2;
//     build(2 * ind + 1, low, mid);
//     build(2 * ind + 2, mid + 1, high);
//     seg[ind] = left + right;
// }

// int ansQ(int ind, int low, int high, int l, int r)
// {
//     if (low >= l && high <= r)
//         return seg[ind];
//     if (high < l || low > r)
//         return INT_MIN;

//     int mid = (low + high) / 2;
//     int leftQ = ansQ(2 * ind + 1, low, mid, l, r);
//     int rightQ = ansQ(2 * ind + 2, mid + 1, high, l, r);
//     return leftQ + rightQ;
// }