#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int get_anc(vector<vector<int>> &anc, int nd, int k)
{
    for (int i = 30; i >= 0 && nd >= 0; i--)
        if (k & (1 << i))
            nd = anc[nd][i];

    return nd;
}

void bnry_lft(vector<vector<int>> &anc_arr, vector<vector<int>> &adj, int nd, int prnt = -1)
{
    anc_arr[nd][0] = prnt;
    for (int i = 1; i < 31 && anc_arr[nd][i - 1] != -1; i++)
        anc_arr[nd][i] = anc_arr[anc_arr[nd][i - 1]][i - 1];

    for (int chld : adj[nd])
    {
        if (chld == prnt) continue;
        bnry_lft(anc_arr, adj, chld, nd);
    }
}

// vector<vector<int>> anc_arr(31, vector<int>(-1));