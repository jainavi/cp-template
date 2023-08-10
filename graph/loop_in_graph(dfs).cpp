// finding and printing the loop

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

const int N = 1e5 + 1, INF = INT_MAX;

int n = 4, m = 5;
vector<vector<int>> adj(N);

vector<bool> visited(N);
vector<int> dp(N, -1);

vector<int> cycle;
vector<bool> connected(N);
bool cycleFound = 0;

void dfs(int node)
{
    connected[node] = 1;
    if (visited[node])
    {
        cycle.push_back(node);
        dp[node] = 1;
        return;
    }

    visited[node] = 1;
    for (int des : adj[node])
    {
        if (cycleFound)
            break;
        if (dp[des] == -1)
            dfs(des);
        if (dp[des])
        {
            if (cycleFound)
                break;
            cycle.push_back(node);
            visited[node] = 0;
            if (cycle.size() && node == cycle[0])
                cycleFound = 1;
            dp[node] = 1;
            return;
        }
    }

    visited[node] = 0;
    dp[node] = 0;
}

int main()
{
    fast_io;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if (!connected[i] && !cycle.size())
            dfs(i);

    if (!cycle.size())
        cout << "IMPOSSIBLE";
    else
    {
        cout << cycle.size() << ln;
        for (int i = cycle.size() - 1; i >= 0; i--)
            cout << cycle[i] << " ";
    }

    return 0;
}