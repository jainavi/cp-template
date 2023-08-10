#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int findParent(int a)
    {
        return parent[a] == a ? a : parent[a] = findParent(parent[a]);
    }
    bool join(int a, int b)
    {
        int pa = findParent(a), pb = findParent(b);
        if (pa != pb)
        {
            rank[pa] < rank[pb] ? parent[pa] = pb : parent[pb] = pa;
            rank[pa] += rank[pa] == rank[pb];
            return true;
        }
        return false;
    }
};