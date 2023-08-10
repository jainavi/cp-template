#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <tuple>

using namespace std;
#define ll long long
#define ln "\n"
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

// converting the cyclic directed graph to acyclic shortest path directed graph using Dijkstra’s Algorithm.
// now can perform dfs on it and ans the queries related to shortest path in the graph.

const ll N = 1e5 + 1, MOD = 1e9 + 7, INF = LONG_LONG_MAX;
int n, m;
vector<vector<pair<int, ll>>> adj(N);
vector<vector<int>> rAdj(N);

vector<ll> minCst(N, INF);

vector<bool> visited(N, 0);

int main()
{
    fast_io;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    priority_queue<pair<ll, tuple<int, int, ll>>> pq;
    minCst[1] = 0;
    pq.push({0, {1, 0, 0}});
    while (!pq.empty())
    {
        int currNode;
        int ancNode;
        ll cost;
        tie(currNode, ancNode, cost) = pq.top().second;
        pq.pop();

        if (minCst[currNode] >= minCst[ancNode] + cost)
            rAdj[ancNode].push_back(currNode);

        if (visited[currNode])
            continue;
        visited[currNode] = 1;

        for (pair<int, ll> des : adj[currNode])
        {
            int desNode = des.first;
            ll desCst = des.second;
            if (minCst[desNode] >= minCst[currNode] + desCst)
            {
                minCst[desNode] = minCst[currNode] + desCst;
                pq.push({-minCst[desNode], {desNode, currNode, desCst}});
            }
        }
    }
    return 0;
}