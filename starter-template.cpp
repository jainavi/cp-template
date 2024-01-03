// Avi Jain : jainzzz

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ln "\n"
#define vint vector<int>
#define vll vector<long long>
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rep(i, s, n) for (int i = s; i < n; i++)
#define NO cout << "NO" << ln
#define YES cout << "YES" << ln

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<": "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(unsigned int t) {cerr << t;}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue <T> pq) {cerr << "[ "; while (!pq.empty()) {_print(pq.top()); cerr << " "; pq.pop();} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T, custom_hash> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";} 
template <class T, class V> void _print(unordered_map <T, V, custom_hash> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";} 

void solve()
{
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    // cout << fixed << setprecision(6);
    while (t--)
        solve();
    return 0;
}                       