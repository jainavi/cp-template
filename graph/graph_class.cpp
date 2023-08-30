#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ln "\n"
#define ll long long
#define vint vector<int>
#define vll vector<long long>
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define rep(i, s, n) for (int i = s; i < n; i++)

class Graph
{
private:
    int V;
    v(vint) adj;
    vint indegree;

public:
    Graph(int V) : adj(V), indegree(V)
    {
        this->V = V;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        indegree[v]++;
    }

    vint topologicalSort()
    {
        vint res;
        queue<int> qu;
        rep(i, 0, V) if (!indegree[i]) qu.push(i);
        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            res.push_back(node);
            for (int child : adj[node])
            {
                indegree[child]--;
                if (!indegree[child])
                    qu.push(child);
            }
        }
        return res.size() == V ? res : vint();
    }
};