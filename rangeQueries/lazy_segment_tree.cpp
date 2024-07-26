#include<iostream>
#include <bits/stdc++.h>

using ll = long long;

using namespace std;

template<typename Node, typename Update>
struct LazySGT {
private:
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<ll> arr;
    int n;
    int s;
    void build(int start, int end, int index) {
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void pushdown(int index, int start, int end){
        if(lazy[index]){
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(int index, int start, int end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update& u) {
        if(start > right || end < left)
            return;
        if(start >= left && end <= right){
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) {
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }

public:
    LazySGT(int a_len, vector<ll> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), false);
        updates.resize(s); fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void make_update(int left, int right, ll val) {
        Update new_update = Update(val); 
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    ll val;
    Node1() {
        val = 0;   
    }
    Node1(ll p1) { 
        val = p1;
    }
    void merge(Node1 &l, Node1 &r) {
        val = l.val + r.val; 
    }
};

struct Update1 {
    ll val; 
    Update1(){ 
        val = 0;
    }
    Update1(ll val1) { 
        val = val1;
    }
    void apply(Node1 &a, int start, int end) { 
        a.val = val * (end - start + 1); 
    }
    void combine(Update1& new_update, int start, int end){
        val = new_update.val;
    }
};
