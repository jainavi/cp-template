#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// LCA using segtree

template<typename Node>
struct SparseTable {
private:
    vector<vector<Node>> table;
	vector<long long> logValues;
	int n;
	int maxLog;
	vector<pii> a;
    void build() {
		for (int i = 0; i < n; i++) {
			table[i][0] = Node(a[i]);
		}
		for (int i = 1; i <= maxLog; i++) {
			for (int j = 0; (j + (1 << i)) <= n; j++) {
				table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
 
public:
	SparseTable(int n1, vector<pair<int, int>> arr) {
		n = n1;
		a = arr;
		table.resize(n);
		logValues.resize(n + 1);
		maxLog = log2(n);
		logValues[1] = 0;
		for (int i = 2; i <= n; i++) {
			logValues[i] = logValues[i / 2] + 1;
		}
		for (int i = 0; i < n; i++) {
			table[i].resize(maxLog + 1);
			fill(all(table[i]), Node());
		}
		build();
	}
	Node queryIdempotent(int left, int right) {
		if (right < left || left < 0) return Node();
 
		int j = logValues[right - left + 1];
		Node ans = Node();
		ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
		return ans;
	}
};
struct Node1 {
	long long val;
    int lvl;
	Node1() {
        val = INT_MAX, lvl = INT_MAX;
    }
	Node1(pair<int, int> v) {
		val = v.first, lvl = v.second;
	}
	void merge(Node1 &l, Node1 &r) {
        lvl = min(l.lvl, r.lvl);
		val = l.lvl <= r.lvl ? l.val : r.val;
	}
};

vector<pair<int, int>> _eu_tr_typ1;
vector<int> _frst_idx;
SparseTable<Node1> sprs_tb(0, _eu_tr_typ1);

void _dfs_eu_tour(vector<vector<int>> &adj, int nd, int prnt, int lvl)
{
    _frst_idx[nd] = min(_frst_idx[nd], (int)_eu_tr_typ1.size());
    _eu_tr_typ1.push_back({nd, lvl});
    for (int ch : adj[nd])
    {
        if (ch == prnt) continue;
        
        _dfs_eu_tour(adj, ch, nd, lvl + 1);
        _eu_tr_typ1.push_back({nd, lvl});
    }
}

void _lca_gen(vector<vector<int>> &adj, int root)
{
    _frst_idx.resize(adj.size(), INT_MAX);
    _dfs_eu_tour(adj, root, 0, 0);
    sprs_tb = SparseTable<Node1>(_eu_tr_typ1.size(), _eu_tr_typ1);
}

int get_lca(int u, int v)
{
    if (_eu_tr_typ1.empty()) return -1;
    
    int i = min(_frst_idx[u], _frst_idx[v]);
    int j = max(_frst_idx[u], _frst_idx[v]);
    return sprs_tb.queryIdempotent(i, j).val;
}
