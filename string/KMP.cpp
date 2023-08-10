#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int>& KMPlookupGen(string &s1, string &s2) // Generates the KMP lookup table
{
    string temp = s1 + "*" + s2;
    vector<int> lookup(temp.size());
    int idx = 0;
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] == temp[idx])
        {
            lookup[i] = ++idx;
            continue;
        }

        idx = lookup[i - 1];
        while (idx > 0 && temp[i] != temp[idx])
            idx = lookup[idx - 1];
        idx += temp[idx] == temp[i];
        lookup[i] = idx;
    }

    return lookup;
}